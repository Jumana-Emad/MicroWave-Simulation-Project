#include "DIO.h"

void Buzz_vINIT(){
	PORT_INIT('A'); //intialize port
	DIO_vSETPINDIRECTION('A', 6, 1); //output pin
}

void Buzz_vON(){
	DIO_vWRITEPIN('A', 6, 1);
}

void Buzz_vOff(){
	DIO_vWRITEPIN('A', 6, 0);
}

void Buzz_vToggle(){
	DIO_vTOGGLEPIN('A', 6);
}
