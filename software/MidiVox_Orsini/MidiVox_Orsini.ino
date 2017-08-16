#include <Midi.h>

/***********************************************************************************
 *   HEALER MIDI SYNTH v1.0
 *         written for use with Arduino MidiVox - http://narbotic.com/kits/midivox
 *         based on Arduino Piano Squealer by Marc Nostromo - http://bit.ly/2xrZn5
 *         requires Arduino Midi Library by Tymm Twillman   - http://bit.ly/a6CDpY	
 *
 *   NOTES:
 *    - responds to MIDI note values 0-84
 *    - synth parameters are mapped to MIDI control like so:
 *
 *         CC#____Parameter______
 *          0_____Waveform Select  
 *          1_____Filter Resonance
 *          2_____Filter Cutoff
 *          3_____Filter Type
 *          4_____Filter Envelope (set to 0 to disable)
 *          5_____Wave Loop/Truncate
 *          6_____Attack Time
 *          7_____Release Time
 *          
 ***********************************************************************************/
 
#include <EEPROM.h>
#include "MIDISetup.h"
#include <Bounce.h>

#define WaveFormSel 0
#define FiltRes 1
#define FiltCutOff 2
#define FilterType 3
#define FilterEnvelope 4
#define WaveLoop 5
#define AttackTime 6
#define ReleaseTime 7

// Switches Definition
int waveFormSw1 = 2;
int waveFormSw2 = 3;
int filtTypeSw1 = 4;
int filtTypeSw2 = 5;
// Potentiometer Definition
int filtResPot = 0;
int cutOffPot = 1;
int filtEnvPot = 2;
int waveLoopPot = 3;
int attackPot = 4;
int relTimePot = 5;

long debounce= 200; // Debounce Time in ms

// Counter for the Switches
int cntWFsw=0;
int cntFTsw=0;

Bounce bWFsw1 = Bounce (waveFormSw1, debounce);
Bounce bWFsw2 = Bounce (waveFormSw2, debounce);
Bounce bFTsw1 = Bounce (filtTypeSw1, debounce);
Bounce bFTsw2 = Bounce (filtTypeSw2, debounce);

int ledValue = LOW;

void(* resetFunc) (void) = 0;               //declare reset function @ address 0

void setup(){

  pinMode(6, INPUT);
  digitalWrite(6, HIGH);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(13, OUTPUT);  // For Led
  digitalWrite(13, ledValue);

  // Set Digital Inputs for Waveform Select without Pull-up
  pinMode(waveFormSw1, INPUT);
  //digitalWrite(waveFormSw1, HIGH);
  pinMode(waveFormSw2, INPUT);
  //digitalWrite(waveFormSw2, HIGH);

  // Set Digital Inputs for Filter Type without Pull-up
  pinMode(filtTypeSw1, INPUT);
  //digitalWrite(filtTypeSw1, HIGH);
  pinMode(filtTypeSw2, INPUT);
  //digitalWrite(filtTypeSw2, HIGH);


  MIDI_Setup();                           // Set up MIDI data handlers and such
  SynthController_Setup();                // Initialize synth parameters
  Hardware_Setup();                       // Setup the arduino hardware, interrupts,etc..
  loadPresets();			  // Load preset parameters from eeprom

} 

void loop(){

        CCParams_Read();        // Check Switches and Potentiometers and sets the CC Params.
  	MIDI_Read();            // poll for MIDI data
 	
	if ((PIND&B1000000)==0){
	  saveAndReset();
	}  
}

void flashLED(int pause){
	
	PORTD |= (1<<7);     //digitalWrite(LED, HIGH);
	delay(pause);
        PORTD &= ~(1<<7);    //digitalWrite(7, LOW);
	delay(pause);
	PORTD |= (1<<7);     //digitalWrite(LED, HIGH);
	delay(pause);
	PORTD &= ~(1<<7);    //digitalWrite(7, LOW);
}

void saveAndReset(){
	uint8_t val=0;
	int index=0;
	for (index = 0; index <=7; index++){
	val = (presets[index]);
	EEPROM.write(index, val);
	}
	resetFunc();
}

void loadPresets(){  
	unsigned int val=0;
	int index=0;
	for (index = 0; index <=7; index++){
		val = EEPROM.read(index);			// Load a value from EEPROM
		if (val == 255) {					// If a preset hasn't been saved,
			val = presets[index];			// then load the default
		}
			fillParams(index, val);			
		}

	flashLED(100);
}


void CCParams_Read()
{

  // Temporary Variables
  unsigned int val;
    
  // Check WaveForm Select Switches
 if (bWFsw1.update())
 {
   if (bWFsw1.read() == LOW)
   {
     cntWFsw++;
     if (cntWFsw > 5) cntWFsw = 0;
   }
 }
 
 if (bWFsw2.update())
 {
   if (bWFsw2.read() == LOW)
   {
     cntWFsw--;
     if (cntWFsw < 0) cntWFsw = 5;
   }
 }

  val = cntWFsw * 127 /6;

  if (val != presets[WaveFormSel])
  {
    fillParams(WaveFormSel, val);
  }

  // Check Filter Type Switches 
 
 if (bFTsw1.update())
 {
   if (bFTsw1.read() == LOW)
   {
     cntFTsw++;
     if (cntFTsw > 10) cntFTsw = 0;
   }
 }
 
 if (bFTsw2.update())
 {
   if (bFTsw2.read() == LOW)
   {
     cntFTsw--;
     if (cntFTsw < 0) cntFTsw = 10;
   }
 }

  val = cntFTsw *127/10;

  if (val != presets[FilterType])
  {
    fillParams(FilterType, val);
  }
 
   // Check Filter Resonance Potentiometer
  val = map(analogRead(filtResPot),0,1024,0,127);
  if (val != presets[FiltRes])
  {
    fillParams(FiltRes, val);
  }

  // Check Filter CutOff Potentiometer
  val = map(analogRead(cutOffPot),0,1024,0,127);
  if (val != presets[FiltCutOff])
  {
    fillParams(FiltCutOff, val);
  }

  // Check Filter Envelope Potentiometer
  val = map(analogRead(filtEnvPot),0,1024,0,127);
  if (val != presets[FilterEnvelope])
  {
    fillParams(FilterEnvelope, val);
  }
  
  // Check Wave Loop Potentiometer
  val = map(analogRead(waveLoopPot),0,1024,0,127);
  if (val != presets[WaveLoop])
  {
    fillParams(WaveLoop, val);
  }

  // Check Attack Time Potentiometer
  val = map(analogRead(attackPot),0,1024,0,127);
  if (val != presets[AttackTime])
  {
    fillParams(AttackTime, val);
  }

  // Check Release Time Potentiometer
  val = map(analogRead(relTimePot),0,1024,0,127);
  if (val != presets[ReleaseTime])
  {
    fillParams(ReleaseTime, val);
  }
  
}

