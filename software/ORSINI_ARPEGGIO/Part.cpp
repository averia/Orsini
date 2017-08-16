/*
  Part.cpp - Global Part for Orsini CUnt

*/


#include "Part.h"



Part::Part()
{
	//pin =num;  

}

void Part::init(byte chan)
{
	
	step=0;
	loop_size=START_LOOP_SIZE;
	loop_select=0;
	channel_select=chan;
	mode_select=0;
	octave_select=3;
	scale_select=0;
		//INIT SEQUENCE
	initSequence();
	

}

void Part::newSequence()
{
	//PASS THE MAIN SEQUENCE FOR MAKE CHANGES
	mode.getNewSequence(LOOP[0],LOOP[2],LOOP[3], scale_select);
	

}


void Part::initSequence()
{



 	for(byte loopItem=0;loopItem<START_LOOP_SIZE;loopItem++){
 				LOOP[0][loopItem]=1;//NOte
//  				LOOP[0][loopItem]=2;//OCTAVE FROM OUTSIDE
				LOOP[1][loopItem]=octave_select;//octave
				LOOP[2][loopItem]=12;//velocity
				LOOP[3][loopItem]=200;//duration

		 
		 }

}


void Part::update(byte which)
{
mode.updateMode( which);
}


