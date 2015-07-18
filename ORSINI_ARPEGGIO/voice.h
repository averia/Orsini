/*
  Voice.h - voice class for midi events dispatching
*/
#ifndef Voice_h
#define Voice_h

#include "Arduino.h"

#define MAX_NOTES 128
#define START_LOOP_SIZE 16


class Voice
{
  public:
    Voice(byte, byte, byte, byte  );
    void playNote();
    void killNote(); 
    bool isPlaying;
    
	
  private:
	byte note;
	byte pitch;
    byte duration;
    byte velocity;
    byte octave;

		
};

#endif