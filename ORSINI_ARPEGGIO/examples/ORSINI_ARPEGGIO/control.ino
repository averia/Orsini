#include <Bounce.h>
byte debounce= 5; // Debounce Time in ms

Bounce channel_mode_up= Bounce( 2,  debounce); 
Bounce channel_mode_down= Bounce( 3,  debounce ); 
Bounce scale_part_up= Bounce(  4,  debounce ); 
Bounce scale_part_down= Bounce(  5,  debounce ); 
Bounce shift= Bounce(  6,  debounce ); 
 



bool checkAnalog(byte analogIn)
{
	if( changeAnalogVal[analogIn]<analogRead(analogIn)-100 || changeAnalogVal[analogIn]>analogRead(analogIn)+100 ){
	
	 changeAnalogBool[analogIn] = true;
	 return true;	
	 
	}else{	
	
	 return false;
	 
	}
}


void resetAnalog(){
	 for(int ch=0; ch<6;ch++){
				changeAnalogBool[ch] = false ;
				changeAnalogVal[ch]=analogRead(ch);
	}
}

void control(){

shift.update ( );
 
 // SHIFT 
 int shiftVal = shift.read();
 if ( shiftVal == HIGH) {
	  shiftOn=0;
	  //resetAnalog();
	 } else {
	  shiftOn=1;
	  resetAnalog();
	}
 if (channel_mode_up.update())
 {
   if (channel_mode_up.read() == LOW)
   {
   ///ON SHIFT
    if(shiftOn==1){//part channel change up
		if(selected_part==0){
			if(part.channel_select<16){
				part.channel_select = (part.channel_select+1);
			}
		}else{
			if(part1.channel_select<16){
				part1.channel_select = (part1.channel_select+1);
			}
		}
			
    	
    }else{
    	
    
    	//part mode change
    }
     
   }
 }
 if (channel_mode_down.update())
 {
   if (channel_mode_down.read() == LOW)
   {///ON SHIFT
    if(shiftOn==1){//part channel change down
		if(selected_part==0){
			if(part.channel_select>=0){
				part.channel_select = (part.channel_select-1);
			}
		}else{
			if(part1.channel_select>=0){
				part1.channel_select = (part1.channel_select-1);
			}
			
		}
			
    	
    }else{
    	
    
    	//part mode change
    }
     
   }
 }
 
 ///SCALE UP
 if (scale_part_up.update())
 {
   if (scale_part_up.read() == LOW)
   {
//  resetAnalog();
   
    if(shiftOn==1){
		//part select
		if(selected_part==0){
		
			selected_part=1;
			
		}else{
		
			selected_part=0;
			
		}
	
			
    	
    }else{
    	//scale change up
    
    	if(selected_part==0){
			if(part.scale_select<14){
				part.scale_select = (part.scale_select+1);
			}
		}else{
			if(part1.scale_select<14){
				part1.scale_select = (part1.scale_select+1);
			}
		}
    }
    
   
   }
 }
  ///SCALE DOWN
 if (scale_part_down.update())
 {
   if (scale_part_down.read() == LOW)
   {
   for(int ch=0; ch<6;ch++){
			changeAnalogBool[ch] = false ;
			changeAnalogVal[ch]=analogRead(ch);
	
		}
   
    if(shiftOn==1){
		//part select
		if(selected_part==0){
		
			selected_part=1;
			
		}else{
		
			selected_part=0;
			
		}
	
			
    	
    }else{
    	//scale change down
    	if(selected_part==0){
			if(part.scale_select>0){
				part.scale_select = (part.scale_select-1);
			}
		}else{
			if(part1.scale_select>0){
				part1.scale_select = (part1.scale_select-1);
			}
		}
    	
    	
    	
    }
    
   
   }
 }
			checkAnalog(0);
			checkAnalog(1);
			checkAnalog(2);
			checkAnalog(3);
			checkAnalog(4);
			checkAnalog(5);
 
 ///UPDATE IF ANALOG READ CHANGED AND PART CHANGED SO NO CHANGES WHEN COMING FROM OTHER PART 
 if(selected_part==0){
			byte n=0;
			
			///OCTAVE FROM OUTSIDE OF THE SEQUENCE FOR IMMEDIATE CHANGE
 			if( changeAnalogBool[n] ){  
				byte m1=map( analogRead(n) ,0,1024,2,16); //OCTSEL 
				part.octave_select=m1;
				
 			}; 
 			//REST OF ANALOG INS FROM 1 with SHIFT OPTION
 			 n=1+(shiftOn*5);
 			if( changeAnalogBool[n] ){  
				part.update(n);
 			};
 			 n=2+(shiftOn*5);
 			if( changeAnalogBool[n] ){  
				part.update(n);
 			};
 			 n=3+(shiftOn*5);
 			if( changeAnalogBool[n] ){  
				part.update(n);
 			};
 			 n=4+(shiftOn*5);
 			if( changeAnalogBool[n] ){  
				part.update(n);
 			};
 			 n=5+(shiftOn*5);
 			if( changeAnalogBool[n] ){  
				part.update(n);
 			};
 			
 			
 			
 			
 			
 			/*byte m1=map( checkAnalog( 0, analogRead(0) ), 0, 1023,   part.mode.arpeggio.MAP_VALUES[0][0], part.mode.arpeggio.MAP_VALUES[0][1]); // mode select
			byte m2 =map( checkAnalog( 1, analogRead(1) ), 0, 1023,   part.mode.arpeggio.MAP_VALUES[1][0], part.mode.arpeggio.MAP_VALUES[1][1]); // mode select
			byte m3=map( checkAnalog( 3, analogRead(3) ), 0, 1023,   part.mode.arpeggio.MAP_VALUES[3][0], part.mode.arpeggio.MAP_VALUES[3][1]); // mode select	
			byte m [4]=map( checkAnalog( 4, analogRead(4) ), 0, 1023,  part.mode.arpeggio.MAP_VALUES[4][0], part.mode.arpeggio.MAP_VALUES[4][1]); // mode select	
			part.mode.clockDivider=map( checkAnalog(5, analogRead(5) ), 0, 1023, part.mode.arpeggio.MAP_VALUES[5][0], part.mode.arpeggio.MAP_VALUES[5][1])*3;
			*/
			
			
 
 }else{
		 
 			byte n=0;
 			if( changeAnalogBool[n] ){  
				byte m1=map( analogRead(n) ,0,1024,2,16); //OCTSEL 
				part1.octave_select=m1;
				
 			}; 
 			 n=1;
 			if( changeAnalogBool[n] ){  
				part1.update(n);
 			};
 			 n=2;
 			if( changeAnalogBool[n] ){  
				part1.update(n);
 			};
 			 n=3;
 			if( changeAnalogBool[n] ){  
				part1.update(n);
 			};
 			 n=4;
 			if( changeAnalogBool[n] ){  
				part1.update(n);
 			};
 			 n=5;
 			if( changeAnalogBool[n] ){  
				part1.update(n);
 			};
 			
 /*
 			part1.octave_select=map(checkAnalog( 0, analogRead(2) ),0,1024,2,9);
			part1.mode.MAPPED_ARGS[0]=map(checkAnalog( 0, analogRead(0) ), 0, 1023,   part1.mode.arpeggio.MAP_VALUES[0][0], part1.mode.arpeggio.MAP_VALUES[0][1]); // mode select
			part1.mode.MAPPED_ARGS[1]=map(checkAnalog( 1, analogRead(1) ), 0, 1023,   part1.mode.arpeggio.MAP_VALUES[1][0], part1.mode.arpeggio.MAP_VALUES[1][1]); // mode select
			part1.mode.MAPPED_ARGS[3]=map(checkAnalog( 3, analogRead(3) ), 0, 1023,   part1.mode.arpeggio.MAP_VALUES[3][0], part1.mode.arpeggio.MAP_VALUES[3][1]); // mode select	
			part1.mode.MAPPED_ARGS[4]=map(checkAnalog( 4, analogRead(4) ), 0, 1023,  part1.mode.arpeggio.MAP_VALUES[4][0], part1.mode.arpeggio.MAP_VALUES[4][1]); // mode select	
			part1.mode.clockDivider=map(checkAnalog( 5, analogRead(5) ), 0, 1023, part1.mode.arpeggio.MAP_VALUES[5][0], part1.mode.arpeggio.MAP_VALUES[5][1])*3;
 
 */
 }
 
 			


}
