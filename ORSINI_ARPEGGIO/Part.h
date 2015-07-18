/*
  Part.h - Global Part for Orsini CUnt
*/
#ifndef Part_h
#define Part_h

#include "Arduino.h"  
#include "Mode.h"

// #include "MIDI.h"



/*THESE SETTINGS FOR 3 track for now maybe less*/
/** this sketch is only for sixteen beats sequence due to complexity and poor understanting of the atmega's limits ;)**/

#define MAX_NOTES_AT_ONCE 1
#define START_LOOP_SIZE 16

class Part
{
  public:
    Part();
    void newSequence();
    void initSequence();
    void init(byte);
    void update(byte);
    void killNotes();
	Mode mode;
	byte LOOP[4][START_LOOP_SIZE]; /*note, octave, velocity, duratinm*/
	volatile byte step;
	byte loop_size;
	byte loop_select;
	byte channel_select;
	byte mode_select;
	byte scale_select;
	byte octave_select;
	byte myPart;
  private:
	byte pin;
	

	
	
};

#endif