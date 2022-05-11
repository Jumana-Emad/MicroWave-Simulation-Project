#include "DIO.h"


void BUTTON_vINIT(unsigned char PortName, unsigned char PIN_NO){
	PORT_INIT(PortName); //intialize port
	DIO_vSETPINDIRECTION(PortName, PIN_NO, 0); //input pin
}

void BUUTON_vINITPULLUP(unsigned char PortName, unsigned char PIN_NO){
	PORT_INIT(PortName); //intialize port
	DIO_vSETPINDIRECTION(PortName, PIN_NO, 0); //input pin
               DIO_uEnablePullUp(PortName, PIN_NO); //active Pull up Resistor
}

unsigned char BUTTON_u8READ(unsigned char PortName, unsigned char PIN_NO){
	return  GPIO_u8READPIN(PortName, PIN_NO);
}



