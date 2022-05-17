#include "DIO.h"
#include "LCD_config.h"
#define Dataport 'B'
#define CTRLPort 'A'
#include "Delays.h"		
#define RS 0x01				 	//RS -> PB0 (0x01)
#define RW 0x02         //RW -> PB1 (0x02)
#define EN 0x04  		 	 	//EN -> PB2 (0x04)
//enum control {E,RS,RW};
//intialization to LCD
//LCD will take the ports of Port B and its control port on Port E

//sending pulse to enable
static void Send_Pulse(void){ 
DIO_vWRITEPIN('A',2,1);
delay_ms(2);
DIO_vWRITEPIN('A',2,0);
delay_ms(2);
}




/////////////////////////////////////////////////////
//send command to LCD
void LCD_Send_cmd(unsigned char cmd)
{
	LCD_Write4bits(cmd & 0xF0 , 0);    //upper nibble first
	LCD_Write4bits(cmd << 4 , 0);			 //then lower nibble
	
	if(cmd < 4)
		delay_ms(2);       //commands 1 and 2 need up to 1.64ms
	else
		delay_ms(40);      //all others 40 us
}
//////////////////////////////////////////////////////
//intialization to LCD
void LCD_vInit(void){
//DIO_vSETPORTDIR(Dataport,0xFF);
//DIO_vSETPINDIRECTION(CTRLPort,E,2); 	//Enable on pin 0
//DIO_vSETPINDIRECTION(CTRLPort,RS,3);	//RS on pin 1
//DIO_vSETPINDIRECTION(CTRLPort,RW,1);	//RW on pin 2
//DIO_vWRITEPIN(CTRLPort,RW,0); // 0 always to write

	SYSCTL_RCGCGPIO_R |= 0x02;    //enable clock for PORTB
	delay_ms(10);                 //delay 10 ms for enable the clock of PORTB
  GPIO_PORTB_DIR_R = 0xFF;             //let PORTB as output pins
	GPIO_PORTB_DEN_R = 0xFF;             //enable PORTB digital IO pins
	LCD_Send_cmd(0x28);          //2 lines and 5x7 character (4-bit data, D4 to D7)
	LCD_Send_cmd(0x06);          //Automatic Increment cursor (shift cursor to right)
	LCD_Send_cmd(0x01);					 //Clear display screen
	LCD_Send_cmd(0x0F);          //Display on, cursor blinking
}	
	
///////////////////////////////////////////////////////////////////////
}
//fn to send char
void LCD_Send_char(unsigned char data)
{
	LCD_Write4bits(data & 0xF0 , RS);   //upper nibble first
	LCD_Write4bits(data << 4 , RS);     //then lower nibble
	delay_ms(40);												//delay for LCD (MCU is faster than LCD)
}



////////////////////////////////////////////////////

//fn to send String

void Send_string(char * data)
{  
	volatile int i = 0;          //volatile is important 
	
	while(*(data+i) != '\0')       //until the end of the string
	{
		LCD_Send_char(*(data+i));    //Write each character of string
		i++;                        //increment for next character
	}
}

void LCD_String(char* str){
	LCD_Send_cmd(0x01);  //Clear the display
	LCD_Send_cmd(0x80);
	 delay_ms(500);											
	 Send_string(str);
	 delay_ms(500);
}

/////////////////////////////////////////////////
void LCD_Write4bits(unsigned char data, unsigned char control)
{
	data &= 0xF0;                       //clear lower nibble for control 
	control &= 0x0F;                    //clear upper nibble for data
	GPIO_PORTB_DATA_R = data | control;         //Include RS value (command or data ) with data 
	GPIO_PORTB_DATA_R = data | control | EN;    //pulse EN
	delayUs(0);													//delay for pulsing EN
	GPIO_PORTB_DATA_R = data | control;					//Turn off the pulse EN
	GPIO_PORTB_DATA_R = 0;                      //Clear the Data 
}
////////////////////////////////////////////////////
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
