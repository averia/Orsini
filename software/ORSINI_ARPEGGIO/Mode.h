/*
  Mode.h - Global Mode for Orsini CUnt
*/
#ifndef Mode_h
#define Mode_h
#include "Arpeggio.h"
#include "RandomWalk.h"
#include "MemChord.h"
#include "Anushri.h"

#include "Arduino.h"
#define MAX_NOTES 128
#define START_LOOP_SIZE 16

#define MODE_COUNT 14
#define TYPE_COUNT 1

class Mode
{
  public:
    Mode();
   
   byte quantize(int, int);
   void getNewSequence(byte*, byte*, byte*, byte);
   void updateMode(byte);
   //void updater();
	byte MODE_CHOICE;
	byte TYPE_CHOICE;
	
	int ARGUMENTS[6];
	int MAPPED_ARGS[6];
	Arpeggio arpeggio;
	RandomWalk randomWalk;
	MemChord memChord;
	Anushri anushri;
	byte clockDivider;	
	

    

	
	
  private:
	int pin;

	 byte MODES_SIZES[MODE_COUNT];
	 byte MODES[MODE_COUNT][12];
	

	
	
	
		
};

#endif