#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "LED.h"
#include "Delays.h"
#include "Button.h"
int z;
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



void End()
{
DIO_vSETPINDIRECTION('E',4,1);
	GPIO_PORTE_DATA_R|=0x10;
	for (z=0;z<7;z++){
	LED_vToggle('F' , 1);
	LED_vToggle('F' , 2);
	LED_vToggle('F' , 3);
	delay_ms(500);	//delay0.5sec
	}										


}



void End_D()
{
DIO_vSETPINDIRECTION('E',4,1);
	
	for (z=0;z<100;z++){
	LED_vToggle('F' , 1);
	LED_vToggle('F' , 2);
	LED_vToggle('F' , 3);
	delay_ms(500);							//delay0.5sec
	if(BUTTON_u8READ('F',0)==0){break;}
	}							

		
}
