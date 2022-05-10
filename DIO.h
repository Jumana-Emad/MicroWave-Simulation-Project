#include "DIO.c"


void PORT_INIT(unsigned char portName);
void DIO_vSETPINDIRECTION (unsigned char portName, unsigned char pinNumber, unsigned char direction);
void DIO_vWRITEPIN (unsigned char portName, unsigned char pinNumber, unsigned char data);
void DIO_vTOGGLEPIN(unsigned char portName, unsigned char pinNumber);