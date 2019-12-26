/*
  Mode.cpp - Global Mode for Orsini CUnt

*/


#include "Mode.h"


Mode::Mode()
{
///-------------TO SOLVE¿¿¿¿¡¡¡¡¡¡¡----------////
clockDivider=12;

byte 	chromatic [] = {0,1,2,3,4,5,6,7,8,9,10,11    };   //  
byte    whole_tone [] = {0,2,4,6,8,10,12    }; // 
byte    blues [] = { 0,3,5,6,7,10,12    }; //  
byte    javanese [] = { 0,1,3,5,7,9,10,12    }; // 
byte    minor [] = { 0,2,3,5,7,8,10,12    }; //  
byte    harmonic_minor  [] = { 0,2,3,5,7,8,11,12    }; // 
byte   	arabian  [] = {0,2,4,5,6,8,10,12    }; //  
byte    harmonic_major [] = { 0,2,4,5,8,9,11,12    }; //  
byte    persian [] = { 0,1,4,5,6,8,11,12    }; //  
byte    oriental [] = {  0,1,4,5,6,9,10,12   }; //  
byte    jewish [] = {   0,1,4,5,7,8,10,12  }; //  
byte    gypsy [] = {   0,1,4,5,7,8,11,12  }; //  
byte    dorian [] = {   0,2,3,5,7,9,10,12  }; //  
byte    ethiopian [] = {  0,2,4,5,7,8,11,12   }; //  
		MODES_SIZES[0]=sizeof(chromatic);
		MODES_SIZES[1]=sizeof(whole_tone);	
		MODES_SIZES[2]=sizeof(blues);	
		MODES_SIZES[3]=sizeof(javanese);	
		MODES_SIZES[4]=sizeof(minor);
		MODES_SIZES[5]=sizeof(harmonic_minor);
		MODES_SIZES[6]=sizeof(arabian);
		MODES_SIZES[7]=sizeof(harmonic_major);
		MODES_SIZES[8]=sizeof(persian);
		MODES_SIZES[9]=sizeof(oriental);
		MODES_SIZES[10]=sizeof(jewish);
		MODES_SIZES[11]=sizeof(gypsy);
		MODES_SIZES[12]=sizeof(dorian);
		MODES_SIZES[13]=sizeof(ethiopian);
		
	for(int i=0; i<12;i++){
	 MODES[0][i]=chromatic[i];
	 
 	 MODES[1][i]=whole_tone[i];
 	
	 MODES[2][i]=blues[i];

	 MODES[3][i]=javanese[i];

	 MODES[3][i]=minor[i];

	 MODES[4][i]=harmonic_minor[i];

	 MODES[5][i]=arabian[i];

	 MODES[6][i]=harmonic_major[i];

	 MODES[7][i]=persian[i];

	 MODES[8][i]=oriental[i];

	 MODES[9][i]=jewish[i];

	 MODES[10][i]=gypsy[i];

	 MODES[11][i]=dorian[i];

	 MODES[12][i]=ethiopian[i];

	 
	};
	MODE_CHOICE=0;
	TYPE_CHOICE=0;

}


///MAPPING VALUES FOR DIFFERENT MODES
void Mode::updateMode(byte which){
	switch(MODE_CHOICE){
	case 0:
		 	if(which!=5){
		 		MAPPED_ARGS[which]=map(analogRead(which), 0, 1023,   arpeggio.MAP_VALUES[which][0], arpeggio.MAP_VALUES[which][1]); // mode select
		 	}else{
		 	   clockDivider=map(analogRead(5), 0, 1023, arpeggio.MAP_VALUES[5][0], arpeggio.MAP_VALUES[5][1])*3;
		 	}
		 	
	break;
	}
  				
}


void Mode::getNewSequence(byte *sequence, byte *vels, byte *durs, byte mode){
	switch(TYPE_CHOICE){
	case 0:
		arpeggio.makeSequence( sequence, MODES[mode], MODES_SIZES[mode], MAPPED_ARGS[1], 1, MAPPED_ARGS[3], MAPPED_ARGS[4]);//array, scale, scalesize, direction, octave arpsize, offset
		arpeggio.makeVelocities( vels, MAPPED_ARGS[2]);
		//arpeggio.makeDurations( durs, MAPPED_ARGS[2]);
	break;

	}


}





// better quantize outside for immediate change of pitch
// byte Mode::quantize(int scale, int note){
//     return octave*12+MODES[scale][note%sizeof( MODES[scale])]; 
// }
// byte Mode::quantize(int scale, int note, int octave){
//     return octave*12+MODES[scale][note]; 
// 
// }
