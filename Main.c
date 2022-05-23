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
       
		case(Cooking): 
switch(Returned_Value){
		case('A'):
		LCD_Send_cmd(0x01);								//Clear the display
		LCD_Send_cmd(0x80);
		str = "Popcorn";
		LCD_String(str);
		delay_ms(2000);
		while((BUTTON_u8READ('F',0)!=0)){};
		LCD_clearscreen();
		delay_s(60); 	//lazem a3mel print fe function el systick 3shan ytb3li el seconds
		while (((BUTTON_u8READ('A',7)) ==0) || ((BUTTON_u8READ('F',4)) == 0) )
		{
		End_D();
		}			

		delay_s(back);
		LCD_Send_cmd(0x01);								//Clear the display
		LCD_Send_cmd(0x80); 							//cursor right
		LCD_String("done");
		End();
		GPIO_PORTE_DATA_R&=~0x10;
		LCD_clearscreen();
			break;
		case('B'):
		while((BUTTON_u8READ('F',0)!=0)){};
		delay_s(30*weight);
		while (((BUTTON_u8READ('A',7)) ==0) || ((BUTTON_u8READ('F',4)) == 0) )
		{ 
		End_D();
		}
		delay_s(back);		
		LCD_String("done");
		End();
		GPIO_PORTE_DATA_R&=~0x10;
		delay_ms(2000);
		LCD_clearscreen();	
			break;
		case('C'): 
		while((BUTTON_u8READ('F',0)!=0)){};
		delay_s(weight*12);
		while (((BUTTON_u8READ('A',7)) ==0) || ((BUTTON_u8READ('F',4)) == 0) )
		{ 
		End_D();
		}
		delay_s(back);						
		LCD_String("done");
		End();
		GPIO_PORTE_DATA_R&=~0x10;
		delay_ms(2000);
		LCD_clearscreen();
			break;
		case('D'): 
		delay_ms(2000);
		if((BUTTON_u8READ('F',4)) != 0){
								
		while((BUTTON_u8READ('F',0)!=0)){}; //sw2
		delay_s(case_d_time);
							
		LCD_String("done");
		End();
		GPIO_PORTE_DATA_R&=~0x10;
		delay_ms(2000);

		}
		LCD_clearscreen();
			break;
							

		}
		State=Idle;
			break;
		
