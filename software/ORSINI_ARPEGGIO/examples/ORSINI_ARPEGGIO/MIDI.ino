#define VOICE_COUNT 16
byte NOTE_ON[VOICE_COUNT];
byte NOTE_CHAN[VOICE_COUNT];
unsigned long NOTE_OFF[VOICE_COUNT];


#define CLOCK_DIVIDER 6
int divider=1;
long _clockCounter = 0;
long step = 0;

void setupMidi(){
  MIDI.begin();
   MIDI.setHandleClock ( HandleClock );



}
void midiLoop(){
	playNotes();
	//trace(66, 12 ); 
  	noteKill();
  	tickClockLed();
  	//partCheck();
}
void partCheck(){

}

void playNotes(){

//trace(67, shiftOn ); 
			if ((_clockCounter % (part1.mode.clockDivider)) == 0 ) {
					part1.step++;
					byte steper= part1.step%16;
					byte note=part1.LOOP[0][steper];
					byte vel=part1.LOOP[2][steper];
					byte duration=part1.LOOP[3][steper];
					byte chan=part1.channel_select;
		
					// turn the LED on (HIGH is the voltage level)
					playNote(quantize(note, part1.octave_select),vel,duration,chan);
					//trace(66, note ); 
					if(steper%16==0){
						//trace(66, note ); 
						part1.newSequence();
					}
			}
			
			if ((_clockCounter % (part.mode.clockDivider)) == 0 ) {
					//trace(65, part.step ); 
					part.step++;
					byte steper= part.step%16;
					byte note=part.LOOP[0][steper];
					byte vel=part.LOOP[2][steper];
					trace(56, part.LOOP[2][steper]); 
					byte duration=part.LOOP[3][steper];
					byte chan=part.channel_select;
		
					// turn the LED on (HIGH is the voltage level)
					playNote(quantize(note, part.octave_select),vel,duration,chan);
					if(steper%16==0){
						part.newSequence();
						trace(56, map(freeRam(), 0,2048,0,127));
					}	
			}
   
    /*for(int p=0;p<nParts;p++){
    
		if ((_clockCounter % (parts[p].mode.clockDivider)) == 0 ) {
			parts[p].step++;
			byte steper= parts[p].step%16;
			byte note=parts[p].LOOP[0][steper];
			byte vel=parts[p].LOOP[2][steper];
			byte duration=parts[p].LOOP[3][steper];
			byte chan=parts[p].channel_select;
		
			// turn the LED on (HIGH is the voltage level)
			playNote(quantize(note, parts[p].octave_select),127,duration,1);
			if(steper%16==0){
			//trace(65+p, parts[p].step ); 
				parts[p].newSequence();
			}	
		}

		
    }
    */
	//byte note2=part2.LOOP[steper][0][0];
    //byte vel2=part2.LOOP[steper][0][2];
    //byte chan2=part2.channel_select;
    //playNote(quantize(note2, part2.octave_select),vel2,1000,2);
    //trace(30,steper);
    
	
	//trace(30,vel);

    //trace(24,part.mode.arpeggio.arp_loop_size );
    //trace(26,part.mode.arpeggio.offset );
	/*trace(10, part.mode.MAPPED_ARGS[0] );
		trace(11, map(analogRead(0), 0, 1023, 0,127));
	trace(20, part.mode.MAPPED_ARGS[1] );
			trace(21, map(analogRead(1), 0, 1023, 0,127));
	trace(30, part.mode.MAPPED_ARGS[2] );
		trace(31, map(analogRead(2), 0, 1023, 0,127));
	trace(40, part.mode.MAPPED_ARGS[3] );
		trace(41, map(analogRead(3), 0, 1023, 1,15));
	trace(50, part.mode.MAPPED_ARGS[4] );
		trace(51, map(analogRead(4), 0, 1023, 0,127));
	trace(60, part.mode.MAPPED_ARGS[5] );
			trace(61, map(analogRead(5), 0, 1023, 0,127));*/
	

 /*   if(steper%16==0){
      //trace(15,0);
	  // trace(66, part.mode.ARGUMENTS[3] );   
	  //trace(67,map(analogRead(3),0,1024,1,15));
		
		parts[0].newSequence();
        //part2.newSequence();
        //MIDI.sendProgramChange(random(127),2);
		//MIDI.sendProgramChange(random(127),1);
    }
*/
}
//
void noteKill(){
unsigned long time=millis();
for (int i=0;i<VOICE_COUNT;i++){
if (NOTE_ON[i]>0 && NOTE_OFF[i]<time){  // if note value>0 and note off time < time
 
	byte pitch = NOTE_ON[i];
	byte velocity = 0;
	MIDI.sendNoteOff(pitch, velocity, NOTE_CHAN[i]);
	NOTE_ON[i]=0; //wipe NOTE_ON entry to signal no active note
}}}

void HandleClock() {
	
  _clockCounter++;
  midiLoop();
}

void trace(byte cc, byte val){
	 MIDI.sendControlChange(cc,val,16);
}

void playNote(byte pitch, byte velocity, int duration, byte chan) {
unsigned long time = millis();
// find an empty note slot 
boolean found_slot = false;
for (int i=0;i<VOICE_COUNT;i++){
if (NOTE_ON[i] == 0){
  
  NOTE_ON[i] = pitch;
  NOTE_OFF[i] = time+duration;
 NOTE_CHAN[i] = chan;
  found_slot = true;
  
  break;
}
}

// RED LIGHT SHOWS NOTE BUFFER IS OVERFULL 
if (found_slot == false){
//digitalWrite (7, HIGH);
}
else{
//-  digitalWrite (7, LOW);
 MIDI.sendNoteOn(pitch, velocity, chan);
};
 
  

  
}

void tickClockLed(){

  if ((_clockCounter % (CLOCK_DIVIDER)) == 0) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
// trace(10, 123 );
  }

  // reset trigger after number+2 CLOCK_DIVIDER ticks
  if (((_clockCounter+2) % (CLOCK_DIVIDER)) == 0) {
    // wait for a second
    digitalWrite(led, LOW);   
   // turn the LED off by making the voltage LOW

  }
}
 byte quantize(int note,int octave){
     return octave*12+note; 
 
 }
