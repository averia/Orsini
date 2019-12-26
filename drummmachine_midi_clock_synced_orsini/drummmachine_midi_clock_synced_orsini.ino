/*
--------------------------------------------------------------------------------------------------
Generative midi drum machine derived from the amazing Mutable instrument's Anushri drum sequencer.
--------------------------------------------------------------------------------------------------
I am not a programmer. I stiched this thing together because I wanted to build this and it didn't 
seem very hard. Surprisingly it worked almost immediately.
Feel free to clean up the code, tune it up or whatever.

-----------------------
Cluster and sector map:
-----------------------
(9 clusters, 4 sectors)

  7 ------- 8 ------- 9
  |         |         |
  |    2    |    3    |
  |         |         |
  4 ------- 5 ------- 6
  |         |         |
  |    1    |    4    |
  |         |         |
  1 ------- 2 ------- 3
  
______________________________  
HW connections:

Bass drum density pot  ---> A1
Snare drum density pot ---> A2
HiHat density pot      ---> A3

X coordinate           ---> A5
Y coordinate           ---> A4

Midi from TX obviously. Check the midi out connection from arduino online.
I don't even know which midi notes it's using right now - change it to whatever you need.

example of midi in and out connection circuit: http://mbed.org/media/uploads/Midimetric/midi.png
I did not use the optoisolation for this so far only breadboarded project but you should use it if you want to be perfectly safe.



Have fun!

Honza Hrubes /aka ashimoke
ashimoke@gmail.com
*/
#include <MIDI.h>
#include <Bounce.h>
int BDcluster1[16] = {236,   0,   0, 138,   0,   0, 208,   0,  58,  28, 174,   0, 104,   0,  58,   0};
int SDcluster1[16] = { 10,  66,   0,   8, 232,   0,   0,  38,   0, 148,   0,  14, 198,   0, 114,   0};
int HHcluster1[16] = {154,  98, 244,  34, 160, 108, 192,  24, 160,  98, 228,  20, 160,  92, 194,  44};

int BDcluster2[16] = {246,  10,  88,  14, 214,  10,  62,   8, 250,   8,  40,  14, 198,  14, 160, 120};
int SDcluster2[16] = { 16, 186,  44,  52, 230,  12, 116,  18,  22, 154,  10,  18, 246,  88,  72,  58};
int HHcluster2[16] = {136, 130, 220,  64, 130, 120, 156,  32, 128, 112, 220,  32, 126, 106, 184,  88};

int BDcluster3[16] = {224,   0,  98,   0,   0,  68,   0, 198,   0, 136, 174,   0,  46,  28, 116,  12};
int SDcluster3[16] = {  0,  94,   0,   0, 224, 160,  20,  34,   0,  52,   0,   0, 194,   0,  16, 118};
int HHcluster3[16] = {228, 104, 138,  90, 122, 102, 108,  76, 196, 160, 182, 160,  96,  36, 202,  22};

int BDcluster4[16] = {240, 204,  42,   0,  86, 108,  66, 104, 190,  22, 224,   0,  14, 148,   0,  36};
int SDcluster4[16] = {  0,   0, 112,  62, 232, 180,   0,  34,   0,  48,  26,  18, 214,  18, 138,  38};
int HHcluster4[16] = {232, 186, 224, 182, 108,  60,  80,  62, 142,  42,  24,  34, 136,  14, 170,  26};

int BDcluster5[16] = {228,  14,  36,  24,  74,  54, 122,  26, 186,  14,  96,  34,  18,  30,  48,  12};
int SDcluster5[16] = {  2,   0,  46,  38, 226,   0,  68,   0,   2,   0,  92,  30, 232, 166, 116,  22};
int HHcluster5[16] = { 64,  12, 236, 128, 160,  30, 202,  74,  68,  28, 228, 120, 160,  28, 188,  82};

int BDcluster6[16] = {236,  24,  14,  54,   0,   0, 106,   0, 202, 220,   0, 178,   0, 160, 140,   8};
int SDcluster6[16] = {134,  82, 114, 160, 224,   0,  22,  44, 202, 220,   0, 178,   0, 160, 140,   8};
int HHcluster6[16] = {174,  86, 230,  58, 124,  64, 210,  58, 160,  76, 224,  22, 124,  34, 194,  26};

int BDcluster7[16] = {236,   0, 226,   0,   0,   0, 160,   0,   0,   0, 188,   0,   0,   0, 210,   0};
int SDcluster7[16] = {134,  82, 114, 160, 224,   0,  22,  44,  66,  40,   0,   0, 192,  22,  14, 158};
int HHcluster7[16] = {174,  86, 230,  58, 124,  64, 210,  58, 160,  76, 224,  22, 124,  34, 194,  26};

int BDcluster8[16] = {226,   0,  42,   0,  66,   0, 226,  14, 238,   0, 126,   0,  84,  10, 170,  22};
int SDcluster8[16] = {  0,   0,  54,   0, 182,   0, 128,  36,   6,  10,  84,  10, 238,   8, 158,  26};
int HHcluster8[16] = {240,  46, 218,  24, 232,   0,  96,   0, 240,  28, 204,  30, 214,   0,  64,   0};

int BDcluster9[16] = {228,   0, 212,   0,  14,   0, 214,   0, 160,  52, 218,   0,   0,   0, 134,  32};
int SDcluster9[16] = {104,   0,  22,  84, 230,  22,   0,  58,   6,   0, 138,  20, 220,  18, 176,  34};
int HHcluster9[16] = {230,  26,  52,  24,  82,  28,  52, 118, 154,  26,  52,  24, 202, 212, 186, 196};        // config of the 9 clusters



byte midi_start = 0xfa;
byte midi_stop = 0xfc;
byte midi_clock = 0xf8;
byte midi_continue = 0xfb;
int play_flag = 0;
byte data;                               // ^ midi in stuff
byte led=7;
byte note=1;

boolean tickSent=false;
#define VOICE_COUNT 16
byte NOTE_ON[VOICE_COUNT];
byte NOTE_CHAN[VOICE_COUNT];
unsigned long NOTE_OFF[VOICE_COUNT];
long _clockCounter = -1;
long _posCounter = 0;
byte clockInState = LOW ;
long lastClock = millis();
byte debounce= 5; 
Bounce divdown= Bounce( 2,  debounce); 
Bounce divup= Bounce( 3,  debounce); 

Bounce notedown= Bounce( 5,  debounce); 
Bounce noteup= Bounce( 4,  debounce); 


int BDfreq = 0;
int SDfreq = 0;
int HHfreq = 0;                          // variables for storing drum density

float Xmap = 0;
float Ymap = 0;                          // coordinates of the 2D pattern map

int clockcount = 0;

int lastposition = 0;
int Position = 0;
int Sector = 0;                          // I have no idea what I'm doing... but it works... in a way.
float BDrum = 0;
float SDrum = 0;
float HHats = 0;

int tempoLED = 7;

byte division=2;
void setup() {
  setupMidi();                                  // set baud rate to midi
  pinMode(tempoLED, OUTPUT);  
}
void control(){

    if (divup.update()) { 
        if (divup.read() == HIGH){
        division=(division+2)%16;
        }
    }
    if (divdown.update()) { 
    if (divdown.read() == HIGH){
        if(division>2){division-=2;}
        }
    }
    if (noteup.update()) { 
        if (noteup.read() == HIGH){
        note=(note+3)%64;
        }
    }
    if (notedown.update()) { 
    if (notedown.read() == HIGH){
        if(note>=3){note-=3;}
        }
    }
}
void loop() {
    //clockIn(8);
  MIDI.read();
   control();
 
}
void midiLoop(){
if(_clockCounter%(3*division)==0){
//trace(56, _clockCounter);
//trace(57, _posCounter);

Play();
//playNote(36, 127, 1000, 10);
_posCounter++;
}

	//trace(66, 12 ); 
  	noteKill();
  	
  	//partCheck();
}
void HandleClock() {
	
 
  midiLoop();
  tickClockLed(3*division);
   _clockCounter++;
}
void reset(){
_clockCounter=0;
_posCounter=0;
}
void tickClockLed(int divi){
  if ((_clockCounter % (divi)) == 0) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
// trace(10, 123 );
  }

  // reset trigger after number+2 CLOCK_DIVIDER ticks
  if (((_clockCounter+2) % (divi)) == 0) {
    // wait for a second
    digitalWrite(led, LOW);   
   // turn the LED off by making the voltage LOW

  }
}
void noteKill(){
unsigned long time=millis();
for (int i=0;i<VOICE_COUNT;i++){
if (NOTE_ON[i]>0 && NOTE_OFF[i]<time){  // if note value>0 and note off time < time
 
	byte pitch = NOTE_ON[i];
	byte velocity = 0;
	MIDI.sendNoteOff(pitch, velocity, NOTE_CHAN[i]);
	NOTE_ON[i]=0; //wipe NOTE_ON entry to signal no active note
}}}

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

void setupMidi(){
  MIDI.begin();
  MIDI.setHandleClock ( HandleClock );
  MIDI.setHandleStart(reset);
}

void clockIn(int dig){
	
	byte inClock=digitalRead(dig);
	if(inClock == LOW ){
		//clockInState = LOW ;
		digitalWrite(7, LOW);
		tickSent=false;
	}else{
		
		if(!tickSent){
		HandleClock();
		digitalWrite(7, HIGH);
		tickSent=true;
		}
		
		//clockInState == HIGH;
	}
	
}
void Play() {
  
  
   Position=_posCounter%16;                     // loop after 16 steps
     
   lastposition = Position;
   
   //BDfreq = analogRead(0);                              // read bass drum density pot
   BDfreq = map(analogRead(0), 0, 1023, 0, 255);                // remap it to values similar to those in cluster configurations
   SDfreq = analogRead(1);                              // read snare drum density pot
   SDfreq = map(SDfreq, 0, 1023, 0, 255);                // remap it to values similar to those in cluster configurations
   HHfreq = analogRead(2);                              // read hi hat density pot
   HHfreq = map(HHfreq, 0, 1023, 0, 255);                // remap it to values similar to those in cluster configurations

   Xmap = analogRead(3);                                // read the X-pot for cluster navigation
   Xmap = map(Xmap, 0, 1023, -100, 100);                 // remap around zero
   Ymap = analogRead(4);                                // read the Y-pot for cluster navigation
   Ymap = map(Ymap, 0, 1023, -100, 100);                 // remap around zero
         
   if (Xmap < 0 && Ymap < 0) Sector = 1;
   if (Xmap < 0 && Ymap > 0) Sector = 2;
   if (Xmap >= 0 && Ymap >= 0) Sector = 3;
   if (Xmap >= 0 && Ymap <= 0) Sector = 4;               // determine sector - which 4 clusters do we want to interpolate

   Xmap = abs(Xmap / 100);
   Ymap = abs(Ymap / 100);                               // get rid off negative values and make it smaller

   
   if (Sector == 1) {
     SDrum = ( ( (SDcluster1[Position] * Xmap) + (SDcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (SDcluster4[Position] * Xmap) + (SDcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
     BDrum = ( ( (BDcluster1[Position] * Xmap) + (BDcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (BDcluster4[Position] * Xmap) + (BDcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
     HHats = ( ( (HHcluster1[Position] * Xmap) + (HHcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (HHcluster4[Position] * Xmap) + (HHcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
   }

   if (Sector == 2) {
     SDrum = ( ( (SDcluster4[Position] * Xmap) + (SDcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (SDcluster7[Position] * Xmap) + (SDcluster8[Position] * (1 - Xmap) ) ) * Ymap );
     BDrum = ( ( (BDcluster4[Position] * Xmap) + (BDcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (BDcluster7[Position] * Xmap) + (BDcluster8[Position] * (1 - Xmap) ) ) * Ymap );
     HHats = ( ( (HHcluster4[Position] * Xmap) + (HHcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (HHcluster7[Position] * Xmap) + (HHcluster8[Position] * (1 - Xmap) ) ) * Ymap );
   }

   if (Sector == 3) {
     SDrum = ( ( (SDcluster5[Position] * ( 1 - Xmap ) ) + (SDcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (SDcluster8[Position] * ( 1 - Xmap )) + (SDcluster9[Position] * Xmap ) ) * Ymap );
     BDrum = ( ( (BDcluster5[Position] * ( 1 - Xmap ) ) + (BDcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (BDcluster8[Position] * ( 1 - Xmap )) + (BDcluster9[Position] * Xmap ) ) * Ymap );
     HHats = ( ( (HHcluster5[Position] * ( 1 - Xmap ) ) + (HHcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (HHcluster8[Position] * ( 1 - Xmap )) + (HHcluster9[Position] * Xmap ) ) * Ymap );
   }   

   if (Sector == 4) {
     SDrum = ( ( (SDcluster2[Position] * ( 1 - Xmap ) ) + (SDcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (SDcluster5[Position] * ( 1 - Xmap ) ) + (SDcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
     BDrum = ( ( (BDcluster2[Position] * ( 1 - Xmap ) ) + (BDcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (BDcluster5[Position] * ( 1 - Xmap ) ) + (BDcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
     HHats = ( ( (HHcluster2[Position] * ( 1 - Xmap ) ) + (HHcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (HHcluster5[Position] * ( 1 - Xmap ) ) + (HHcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
   }

  ///////////////////////////////// above are the equations for interpolating between values. Nothing fancy.

   if (BDrum > BDfreq) playNote(35+note, 127, 1000, 10); 
   if (SDrum > SDfreq) playNote(36+note, 127, 1000, 10); 
   if (HHats > HHfreq) playNote(37+note, 127, 1000, 10);         // sending midi notes

} 

void trace(byte cc, byte val){
	 MIDI.sendControlChange(cc,val,16);
}