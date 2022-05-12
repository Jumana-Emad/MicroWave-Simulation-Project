#include "DIO.h"
#include "LCD_config.h"
#define Dataport 'B'
#define CTRLPort 'E'
#include "delayofLCD.h"
enum control {E,RS,RW};
//intialization to LCD
//LCD will take the ports of Port B and its control port on Port E

//sending pulse to enable
static void Send_Pulse(void){ 
DIO_vWRITEPIN(CTRLPort,E,1);
delay_ms(2);
DIO_vWRITEPIN(CTRLPort,E,0);
delay_ms(2);
}
//send command to LCD
void LCD_Send_cmd(char cmd){
DIO_vWRITEPORT(Dataport,cmd);
DIO_vWRITEPIN(CTRLPort,RS,0); // Rs takes 0 if it is command
Send_Pulse();
SysTick_wait_1ms();

}
//intialization to LCD
void LCD_vInit(void){
DIO_vSETPORTDIR(Dataport,0xFF);
DIO_vSETPINDIRECTION(CTRLPort,E,1); 	//Enable on pin 0
DIO_vSETPINDIRECTION(CTRLPort,RS,1);	//RS on pin 1
DIO_vSETPINDIRECTION(CTRLPort,RW,1);	//RW on pin 2
DIO_vWRITEPIN(CTRLPort,RW,0); // 0 always to write
LCD_Send_cmd(Function_8_bit);
SysTick_wait_1ms();
LCD_Send_cmd(cursorOff);
SysTick_wait_1ms();
LCD_Send_cmd(clear_display);
delay_ms(10);
LCD_Send_cmd(Entry_mode);
SysTick_wait_1ms();
	
}
//fn to send char
void LCD_Send_char(char chr){
DIO_vWRITEPORT(Dataport,chr);
DIO_vWRITEPIN(CTRLPort,RS,1);
Send_Pulse();
SysTick_wait_1ms();

}
//fn to send String
void Send_string(char *data){
while ((*data)!= '\0'){}
LCD_Send_char ((*data));
data++;
}
//fn to clear screen
void LCD_clearscreen(void){
LCD_Send_cmd(clear_display);
delay_ms(10);
}
//fn to move a cursor to a certain position
void LCD_MoveCursor(char row, char col) //no of row 1 or 2 & no of cols 1 to 16
	{ 
char position=0;
	if (row==1)
	position=0x80+col-1;
	else if (row==2)
	position=0xC0+col-1;
	else
	position=0x80+col-1;
LCD_Send_cmd(position);
delay_ms(10);
}
	//fn to shift the cursor right
void Lcd_Shift_Right()
{
	LCD_Send_cmd(shiftDisplayRight);
}
//fn to shift the cursor left
void Lcd_Shift_Left()
{
	LCD_Send_cmd(shiftDisplayLeft);
}
