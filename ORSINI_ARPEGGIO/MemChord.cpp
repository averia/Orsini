/*
  MemChord.cpp - Global MemChord for Orsini CUnt

*/


#include "MemChord.h"



MemChord::MemChord()
{
        arp_loop_size=16;
        offset=0;
        MAP_VALUES[0][0]=2; //DIRECTION MIN
        MAP_VALUES[0][1]=9; //DIRECTION MAX
		 
        MAP_VALUES[1][0]=0; //scale MIN
        MAP_VALUES[1][1]=4; //scale MAX
		 
        MAP_VALUES[2][0]=0; //octave MIN
        MAP_VALUES[2][1]=127; //octave MAX
		 
        MAP_VALUES[3][0]=1; //size MIN
        MAP_VALUES[3][1]=15; //size MAX
		 
        MAP_VALUES[4][0]=0; //offset MIN
        MAP_VALUES[4][1]=15; //offset MAX
        
        MAP_VALUES[5][0]=1; //vel MIN
        MAP_VALUES[5][1]=16; //vel MAX
        
        /// WHEN SHIFT IS PRESSED
        MAP_VALUES[6][0]=2; //DIRECTION MIN
        MAP_VALUES[6][1]=9; //DIRECTION MAX
        
        MAP_VALUES[7][0]=0; //scale MIN
        MAP_VALUES[7][1]=4; //scale MAX
        
        MAP_VALUES[2][0]=0; //octave MIN
        MAP_VALUES[8][1]=127; //octave MAX
        
		MAP_VALUES[9][0]=1; //size MIN
        MAP_VALUES[9][1]=15; //size MAX
        
        MAP_VALUES[10][0]=0; //offset MIN
        MAP_VALUES[10][1]=15; //offset MAX
        
        MAP_VALUES[11][0]=1; //vel MIN
        MAP_VALUES[11][1]=16; //vel MAX  
		 
		 
}
/////SEQUNCIN NOTE
void MemChord::up(byte *seq, byte *scale, byte scaleSize){
	for(int i=0;i<16;i++){
		seq[i]=scale[(offset+(i%arp_loop_size))%(scaleSize)];
		//seq[i]=scale[random(16) ];
	}
}
void MemChord::down(byte *seq, byte *scale,  byte scaleSize){
	for(int i=0;i<16;i++){
				seq[i]=scale[((offset+(15-i))%arp_loop_size)%scaleSize];
	}
}

void MemChord::upDown(byte *seq, byte *scale,  byte scaleSize){
	for(int i=0;i<arp_loop_size;i++){
		seq[i]=scale[ ((offset+(i))%arp_loop_size) % scaleSize  ];
	}
	for(int i=arp_loop_size;i<15;i++){
		seq[i]=scale[ (offset+(	-i)%arp_loop_size) % scaleSize ];
	}
}

void MemChord::randomArp(byte *seq, byte *scale,  byte scaleSize){
	for(int i=0;i<16;i++){
		seq[i]=scale[(offset+random(15-offset)) % scaleSize];
	}
}

void  MemChord::makeSequence( byte *sequence, byte *scal, byte scalSize, byte direction, byte octave, byte arp_size, byte offst){
 arp_loop_size = arp_size;
 offset= offst;
 switch(direction){
 case 0:
			up( sequence, scal,   scalSize);
		break;
		case 1:
			down( sequence, scal, scalSize );
		break;
		case 2:
			upDown( sequence, scal , scalSize);
		break;
		case 3:
			randomArp( sequence, scal, scalSize );
		break;

}



}



//VELOCITIES
void MemChord::setVelRand(byte *seq, byte vel){
	for(int i=0;i<16;i++){
		seq[i]=random(0, 127);
	}

}

void MemChord::setVelUp(byte *seq, byte vel){
	for(int i=0;i<16;i++){
		seq[i]=map((offset+i) % arp_loop_size, 0, 16, 0, vel) ;
	}

}

void MemChord::setVelDown(byte *seq, byte vel){
	for(int i=0;i<16;i++){
		seq[i]=map((offset+i) % arp_loop_size, 0, 16, vel, 0) ;
	}

}
void MemChord::setVelVal(byte *seq, byte vel){
	for(int i=0;i<16;i++){
		seq[i]=vel;
	}

}


///DURATIONS
void MemChord::setDurVal(byte *seq, byte dur){
	for(int i=0;i<16;i++){
		seq[i]=dur ;
	}

}

void MemChord::setDurRand(byte *seq, byte dur){
	for(int i=0;i<16;i++){
		seq[i]=dur ;
	}
}

void  MemChord::makeVelocities( byte *sequence, byte vel){
	byte for_case=map(vel, 0, 127, 0, 3); //if read > 127/4 the val is good one 
	switch(for_case){
	 case 0:
				setVelDown( sequence, vel );
			break;
			case 1:
				setVelRand( sequence, vel );
			break;
			case 2:
				setVelUp( sequence, vel );
			break;
			case 3:
				setVelVal( sequence, vel );
			break;

	}
}

void  MemChord::makeDurations( byte *sequence, byte dur){
	setDurVal(sequence, dur);
	//byte for_case=map(vel, 0, 127, 0, 3); //if read > 127/4 the val is good one 
// 	switch(par5){
// 			 case 0:
// 				setVelVal( sequence, dur );
// 			break;
// 			case 1:
// 				setVelRand( sequence, dur );
// 			break;
// 			case 2:
// 				setVelUp( sequence, dur );
// 			break;
// 			case 3:
// 				setVelDown( sequence, dur );
// 			break;
// 
// 	}
}
// void  MemChord::updateSequence(byte *sequence, byte *scal, byte direction, byte arp_size, byte scl_shft, byte par4 , byte par5){
// 	switch(direction){
// 			case 0:
// 				up( sequence, scal);
// 			break;
// 			case 1:
// 				down( sequence, scal);
// 			break;
// 			case 2:
// 				upDown( sequence, scal);
// 			break;
// 			case 3:
// 				randomArp( sequence, scal);
// 			break;
// 
// 	}
// 
// }



// byte MemChord::quantize(int scale, int note, int octave){
//     return octave*12+MODES[scale][note]; 
// 
// }
