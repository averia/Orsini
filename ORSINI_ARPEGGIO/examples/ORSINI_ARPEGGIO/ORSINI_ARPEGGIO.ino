#include <Part.h>
#include <MIDI.h>
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 7;
byte selected_part=  0;
byte shiftOn=0;

bool changeAnalogBool[6]={false , false , false , false , false , false };// changed
int changeAnalogVal[6]={analogRead(0), analogRead(2), analogRead(3), analogRead(4), analogRead(5), analogRead(6) };//lastval, changed


//Part[3] parts={part(5), part(5), part(5)};


Part part;
Part part1;
//Part part2;
//Part part2;
// the setup routine runs once when you press reset:
void setup() { 
	setupMidi();  
	//parts[0]=part;
	part.init(1);
	part.myPart=0;
	part1.init(2);
	part1.myPart=1;
	
//	part2.init(2);
 
  // initialize the digital pin as an output.
 //	part.init();
 	//part2.init();
  
 // part.newSequence();
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
//  MIDI.sendNoteOn(12,100,1);
//  delay(10);
	MIDI.read();
	
	
	//part1.update(selected_part);
	control();
 	//midiLoop();
 // wait for a second
  //trace(56, map(freeRam(), 0,2048,0,127));
 //   Serial.println(freeRam());
}

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

