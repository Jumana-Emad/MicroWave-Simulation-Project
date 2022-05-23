#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "Delays.h"
#include "KeyPad.h"
#include "LCD.h"
#include "LED.h"
#include "Button.h"
#include "buzz.h"
enum {Idle,Cooking,Weighing,Get_Time};
void RGB_OUTPUT (unsigned char data) {
   GPIO_PORTF_DATA_R &=~ 0x0E;
	 GPIO_PORTF_DATA_R |= data;
}

int main(){
char* str ="";
char time[5];
int weight;	
int case_d_time ;
int i;	 
int input;
int State = Idle;
char Returned_Value;
BUUTON_vINITPULLUP('F', 0); ///sw2
BUUTON_vINITPULLUP('F', 4); ////sw1
BUUTON_vINITPULLUP('A', 7);

LED_vINIT('F',1);
PORT_INIT('E');
LED_vINIT('F',2);
LED_vINIT('F',3);
LCD_vInit();	
Keypad_Init();			
	
while(1){
if ((BUTTON_u8READ('A',7)) !=0){ //not pressed door closed
switch(State){
		case(Idle):
		str = "Idle";
		LCD_String(str);
		str = "Enter Ur choice";
		LCD_String(str);		
		Returned_Value = KeyPad_u8Read();
		if (Returned_Value =='A'){State=Cooking;}		
		else if ((Returned_Value =='B'||Returned_Value =='C')){State = Weighing;}
		else if	(Returned_Value =='D'){State = Get_Time;}
		//else {State = Idle;}
		break;
       
