/*
  Voice.cpp - Global Voice for Orsini CUnt

*/


#include "Voice.h"




Voice::Voice( byte pit, byte dur, byte vel, byte octv)
{
	pitch =pit;
    duration=dur;
    velocity=vel;
	octave=octv;
	note=(octave*12)+pitch;
	
}


void Voice::playNote()
{

}

void Voice::killNote()
{
 
}

