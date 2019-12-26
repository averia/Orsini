/*
  MemChord.h - MemChord MemChord for Orsini CUnt
*/
#ifndef MemChord_h
#define MemChord_h

#include "Arduino.h"


#define ARP_MODES 14

class MemChord
{
  public:
    MemChord();
    void up(byte*, byte*, byte);
    void down(byte*, byte*, byte);
    void upDown(byte*, byte*, byte);
	void randomArp(byte*, byte*, byte);
	void setVelUp(byte*, byte);
	void setVelDown(byte*, byte);
	void setVelRand(byte*, byte);
	void setVelVal(byte*, byte);
	void setDurRand(byte*, byte);
     void setDurVal(byte*, byte);
    void makeDurations(byte*, byte);
    void makeVelocities(byte*, byte);
    void setArgument(byte, int);
       
    void makeSequence(byte*, byte*,  byte,  byte, byte, byte, byte);  	
  //   void makeVelocities(byte*, byte);  
//     void makeDurations(byte*,  byte);  		
       
    

  //  void updateSequence(byte*, byte*,  byte, byte, byte, byte, byte);  	     
    volatile byte arp_loop_size;
    volatile byte offset ;
    int MAP_VALUES[6][2]; //MIN , MAX for mapping the arguments;
     
    //WILL IT BE EVER CHANGING?
   	bool inLoop;
   	
  private:
	int pin;
	
	
	
	
		
};

#endif