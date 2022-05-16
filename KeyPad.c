#include "tm4c123gh6pm.h"
#include "Delays.h"
#include "stdint.h"

void Keypad_Init(){
SYSCTL_RCGCGPIO_R|=0X14;								//ENABLE CLOCK FOR PORT C ,E
while((SYSCTL_PRGPIO_R&0X14)==0){};			//WAIT UNTIL ENABLED
GPIO_PORTE_LOCK_R= GPIO_LOCK_KEY; 			//need to be checked if portE is locked or not?
GPIO_PORTE_CR_R|=0X0F;									//ENABLE CR FOR PE3-0
GPIO_PORTE_AFSEL_R&=~0X0F;							//DISABLE ALTERNATE FUNCTION FOR PE3-0
GPIO_PORTE_PCTL_R&=~0X0000FFFF;					//GPIO FOR PE3-0
GPIO_PORTE_AMSEL_R&=~0X0F;							//DISABLE ANALOG FOR PE3-0
GPIO_PORTE_DIR_R&=~0X0F;								//PE3-0 IS INPUT
GPIO_PORTE_DEN_R|=0X0F;									//ENABLE DIGITAL FOR PE3-0
GPIO_PORTE_PDR_R|=0X0F;									//ENABEL PULL DOWN FOR PE3-0 *****IMPORTANT WE ARE NOW WORKING POSITIVE LOGIC

GPIO_PORTC_LOCK_R= GPIO_LOCK_KEY;			 	//need to be checked if portC is locked or not?
GPIO_PORTC_CR_R|=0XF0;									//ENABLE CR FOR PC7-4
GPIO_PORTC_AFSEL_R&=~0XF0;							//DISABLE ALTERNATE FUNCTION FOR PC7-4
GPIO_PORTC_PCTL_R&=~0XFFFF0000;					//GPIO FOR PC7-4
GPIO_PORTC_AMSEL_R&=~0XF0;							//DISABLE ANALOG FOR PC7-4
GPIO_PORTC_DIR_R|=0XF0; 								//PC7-4 IS OUTPUT
GPIO_PORTC_DEN_R|=0XF0;									//ENABLE DIGITAL FOR PC7-4
}

unsigned char KeyPad_u8Read(void){
	//to remember portC (pins 4-7 are rows) , portE (pins 0-3 are columns)
	unsigned char array [4][4] = {
	{ '1', '2', '3', 'A'},
	{ '4', '5', '6', 'B'},
	{ '7', '8', '9', 'C'},
	{ '*', '0', '#', 'D'},
	};
	int Row,Column;//counters
	unsigned char Returned_Button;//HOLD THE MATRIX ELEMENT THAT CORRESPONDS TO THE PREESED KEY
	while(1)
	{
		//LETS CHECK FIRSTLY WHETHER THERE IS A KEY PRESSED OR NOT
		GPIO_PORTC_DATA_R|=0XF0;												//ENABLE ALL ROWS
		if((GPIO_PORTE_DATA_R&0X0F)==0X00)
			{continue;}	//HERE WE CHECK IF ANY KEY IS PRESSED ,IF ANY IS PRESSED THEN CORRESPONDING BIT IS SET SO IN CASE KEY IS PRESSED WE WILL START DETECTING IT
		GPIO_PORTC_DATA_R&=~0XF0;												//DISABLE ALL ROWS
		for(Row=0; Row<4; Row++){
			if(Row>0)
				{GPIO_PORTC_DATA_R&=~(0X10<<(Row-1));} //TO AVOID 2 ROWS BEING ENABLE AT THE SAME TIME SO EACH ITERATION DISABLE THE PREVIOUS ITERATION ROW
			GPIO_PORTC_DATA_R|=(0X10<<Row);//HERE WE ENABLE ROW BY ROW
			for(Column=0 ; Column<4; Column++){//LOOP ON ALL COLUMNS IN ROW i TO SEE WHICH KEY IS PRESSED
				if((GPIO_PORTE_DATA_R&0X0F)==(0X01<<Column)){
				Returned_Button = array[Row][Column];//GETTING THE ELEMENT CORRESPONDING TO THE PRESSED KEY AND PASSING TO PRESSED_BUTTON VARIABLE
				}
			}
		}
		delay_ms(20);
		return Returned_Button;
	}
}
