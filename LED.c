#include "DIO.h"

void LED_vINIT(unsigned char PortName, unsigned char PIN_NO){
	PORT_INIT(PortName); //intialize port
	DIO_vSETPINDIRECTION(PortName, PIN_NO, 1); //output pin
}

void LED_vON(unsigned char PortName, unsigned char PIN_NO){
	DIO_vWRITEPIN(PortName, PIN_NO, 1);
}

void LED_vOff(unsigned char PortName, unsigned char PIN_NO){
	DIO_vWRITEPIN(PortName, PIN_NO, 0);
}

void LED_vToggle(unsigned char PortName, unsigned char PIN_NO){
	DIO_vTOGGLEPIN(PortName, PIN_NO);
}




