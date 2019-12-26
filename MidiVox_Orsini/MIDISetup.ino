//MIDI Setup
//NOTE-OFF WATCHGUARD

#include "Midi.h"
#include "SynthController.h"

byte noteOut = 255;
float pitchVal = 0.0;
float paramVal = 0.0;
float filterVal = 0.0;
float attackVal = 0.0;
float releaseVal = 0.0;
//uint8_t veloVal;
//uint8_t veloWeight;
int v, pos, i = 0;

byte noteBuf[5] = {255,255,255,255,255};  // set up keyboard buffer for 5 notes

class MyMidi :
public Midi {
public:
  // Need this to compile; it just hands things off to the Midi class.
  MyMidi(HardwareSerial &s) : 
  Midi(s){
  }

  void handleNoteOff(unsigned int channel, unsigned int note, unsigned int velocity){
    note_delete(note);
    playNote();
  }

  void handleNoteOn(unsigned int channel, unsigned int note, unsigned int velocity){

    if (!velocity)  // this will be a note off message
    {
      note_delete(note);
    }

    else if (note < 84)            // check if the note isn't too high for the synth engine
    {
      note_insert(note);
      //veloVal = velocity;
    }

    playNote();
  }

  void handlePitchChange(unsigned int pitch){  // Pitch Bend data
    pitch = map(pitch,0,127,0,128);
    //pitchVal = ((pitch)/float(690))-11.9;
    pitchVal = ((pitch)/float(690))-23.95;
    SE_SetPitchBend(pitchVal);
  }

  void handleControlChange(unsigned int channel, unsigned int controller, unsigned int value){ 
    fillParams(controller, value);
  }
};

MyMidi midi(Serial);

void playNote(){ 
	
  if (noteBuf[0]!=255){  
    PORTD |= (1<<7);                                         // DATA LED ON
    noteOut = (noteBuf[0]);                                        
  }
	
  else{   
    PORTD &= ~(1<<7);                                        //DATA LED OFF
    noteOut = 255;
  }
	
}

void note_insert(byte note){

	
	for (v=0; v<=4; v++) // remove the note if it's already in the buffer
	 {  
		 if (noteBuf[v] == note) {
			 for(pos=v; pos<=4; pos++) {
				 noteBuf[pos]=noteBuf[pos+1];
		 }
	 }
	 }


	for(i=4; i>0; i--) {
    noteBuf[i] = noteBuf[i-1];       // move each note in the buffer up one position
  }
	
  noteBuf[0]=note;                   // place our new note in the beginning of the note buffer
}

void note_delete(byte note){
	
	for (v=0; v<=4; v++)
	 {  
		 if (noteBuf[v] == note) {
			 pos=v;
			 break;  
		 }
	 }
	for(v=pos; v<=4; v++) {
		noteBuf[v]=noteBuf[v+1];
	}
	noteBuf[v-1]=255;
}

void MIDI_Setup(){
  midi.begin(1);
	midi.setParam(Midi::PARAM_SEND_FULL_COMMANDS, 0);
  
}

void MIDI_Read(){
  midi.poll();
  SynthController_ProcessEnvelopes();        // process synth data
  SynthController_Trigger(noteOut, filterVal, attackVal, releaseVal);          // send audio data
}

void fillParams(unsigned int controller, unsigned int value){

    switch (controller){
    case 0:
      presets[0] = value;
      paramVal= value/float(127);
      SC_SetParam(0, paramVal);           // Waveform Select
      break;
    case 1:
      presets[1] = value;
      paramVal= value/float(127);
      SC_SetParam(4, paramVal);           // Filter Resonance
      break;
    case 2:
      presets[2] = value;
      paramVal= (value+10)/float(137);
      SC_SetParam(3, paramVal);           // Filter Cutoff
      break;
    case 3:
      presets[3] = value; 
      paramVal= value/float(127);
      SC_SetParam(2, paramVal);           // Filter Mix  
      break;
    case 4:
      presets[4] = value;					// Filter Envelope
      filterVal= value/float(137);
      break;
    case 5:
      presets[5] = value;
      paramVal= (value+8)/float(135);
      SC_SetParam(1, paramVal);           // Wave Loop/Truncate
      break;
    case 6:
      presets[6] = value;
      attackVal = value/float(48);           // Attack Time
      break;
    case 7:
      presets[7] = value;
      releaseVal = value/float(32);         // Release Time
      break;
    case 8:
      presets[8] = value;                 // Velocity Sensitivity - DISABLED!
	  //veloWeight = value;
      break;
    default:
      break;
    }
  }




