#include "tm4c123gh6pm.h"
#include "Macros.c"

void PORT_INIT(unsigned char portName){ 
     switch(portName){
		case 'A':
		case 'a':
			{
			SET_BIT(SYSCTL_RCGCGPIO_R ,0);
			while (READ_BIT(SYSCTL_RCGCGPIO_R ,0)==0);
			GPIO_PORTA_LOCK_R = 0x4C4F434B;
			GPIO_PORTA_CR_R = 0xFF; // Note number of available pins in each port before calling
			GPIO_PORTA_DEN_R = 0xFF;  
			} break;
		case 'B':
		case 'b':
		        {
			SET_BIT(SYSCTL_RCGCGPIO_R ,1);
			while (READ_BIT(SYSCTL_RCGCGPIO_R ,1)==0);
			GPIO_PORTB_LOCK_R = 0x4C4F434B;
			GPIO_PORTB_CR_R = 0xFF;
			GPIO_PORTB_DEN_R = 0xFF;  
			} break;
                case 'C':
		case 'c':
			{
			SET_BIT(SYSCTL_RCGCGPIO_R ,2);
			while (READ_BIT(SYSCTL_RCGCGPIO_R ,2)==0);
			GPIO_PORTC_LOCK_R = 0x4C4F434B;
			GPIO_PORTC_CR_R = 0xFF;
			GPIO_PORTC_DEN_R = 0xFF;  
			} break;
		case 'D':
		case 'd':
			{
			SET_BIT(SYSCTL_RCGCGPIO_R ,3);
			while (READ_BIT(SYSCTL_RCGCGPIO_R ,3)==0);
			GPIO_PORTD_LOCK_R = 0x4C4F434B;
			GPIO_PORTD_CR_R = 0xFF;
			GPIO_PORTD_DEN_R = 0xFF;  
			} break;
		case 'E':
		case 'e':
			{
			SET_BIT(SYSCTL_RCGCGPIO_R ,4);
			while (READ_BIT(SYSCTL_RCGCGPIO_R ,4)==0);
			GPIO_PORTE_LOCK_R = 0x4C4F434B;
			GPIO_PORTE_CR_R = 0xFF;
			GPIO_PORTE_DEN_R = 0xFF; 
			} break;
		case 'F':
		case 'f':
			{
			SET_BIT(SYSCTL_RCGCGPIO_R ,5);
			while (READ_BIT(SYSCTL_RCGCGPIO_R ,5)==0);
			GPIO_PORTF_LOCK_R = 0x4C4F434B;
			GPIO_PORTF_CR_R = 0xFF;
			GPIO_PORTF_DEN_R = 0xFF;  
			} break;
		 
		 }
}

void DIO_vSETPINDIRECTION (unsigned char portName, unsigned char pinNumber, unsigned char direction){
	switch(portName){
		case 'A':
		case 'a':
			{
			if(direction == 1){SET_BIT(GPIO_PORTA_DIR_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTA_DIR_R, pinNumber);} 
			} break;
		case 'B':
		case 'b':
			{
			if(direction == 1){SET_BIT(GPIO_PORTB_DIR_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTB_DIR_R, pinNumber);} 
			} break;
		case 'C':
		case 'c':
			{
			if(direction == 1){SET_BIT(GPIO_PORTC_DIR_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTC_DIR_R, pinNumber);} 
			} break;
		case 'D':
		case 'd':
			{
			if(direction == 1){SET_BIT(GPIO_PORTD_DIR_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTD_DIR_R, pinNumber);} 
			} break;
		case 'E':
		case 'e':
			{
			if(direction == 1){SET_BIT(GPIO_PORTE_DIR_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTE_DIR_R, pinNumber);} 
			} break;
		case 'F':
		case 'f':
			{
			if(direction == 1){SET_BIT(GPIO_PORTF_DIR_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTF_DIR_R, pinNumber);}
			} break;

		}

}

void DIO_vWRITEPIN (unsigned char portName, unsigned char pinNumber, unsigned char data){
        switch(portName){
		case 'A':
		case 'a':
			{
			if(data == 1){SET_BIT(GPIO_PORTA_DATA_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTA_DATA_R,pinNumber);}
			} break;
		case 'B':
		case 'b':
			{
			if(data == 1){SET_BIT(GPIO_PORTB_DATA_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTB_DATA_R,pinNumber);}
			} break;
		case 'C':
		case 'c':
			{
			if(data == 1){SET_BIT(GPIO_PORTC_DATA_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTC_DATA_R,pinNumber);}
			} break;
		case 'D':
		case 'd':
			{
			if(data == 1){SET_BIT(GPIO_PORTD_DATA_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTD_DATA_R,pinNumber);}
			} break;
		case 'E':
		case 'e':
			{
			if(data == 1){SET_BIT(GPIO_PORTE_DATA_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTE_DATA_R,pinNumber);}
			} break;
		case 'F':
		case 'f':
			{
			if(data == 1){SET_BIT(GPIO_PORTF_DATA_R, pinNumber);}
			else {CLR_BIT(GPIO_PORTF_DATA_R,pinNumber);}
			} break;
      }
}				
void DIO_vTOGGLEPIN(unsigned char portName, unsigned char pinNumber){
      switch(portName){ 
		case 'A':
		case 'a':
			{ TOG_BIT(GPIO_PORTA_DATA_R, pinNumber); } break;
		case 'B':
		case 'b':
			{ TOG_BIT(GPIO_PORTB_DATA_R, pinNumber); } break;
		case 'C':
		case 'c':
			{ TOG_BIT(GPIO_PORTC_DATA_R, pinNumber); } break;
		case 'D':
		case 'd':
			{ TOG_BIT(GPIO_PORTD_DATA_R, pinNumber); } break;
		case 'E':
		case 'e':
			{ TOG_BIT(GPIO_PORTE_DATA_R, pinNumber); } break;
		case 'F':
		case 'f':
			{ TOG_BIT(GPIO_PORTF_DATA_R, pinNumber); } break;

	}
}


void DIO_vSETPORTDIR(unsigned char portname, unsigned char direction){
	switch(portname){
		case'A':
		case'a':{
			GPIO_PORTA_DIR_R = direction;
		break;	
		}
		case'B':
		case'b':{
			GPIO_PORTB_DIR_R = direction;
		break;	
		}
		case'C':
		case'c':{
			GPIO_PORTC_DIR_R = direction;
		break;	
		}
		case'D':
		case'd':{
			GPIO_PORTD_DIR_R = direction;
		break;	
		}
		case'E':
		case'e':{
			GPIO_PORTB_DIR_R = direction;
		break;	
		}
		case'F':
		case'f':{
			GPIO_PORTB_DIR_R = direction;
		break;	
		}
	}
}
void DIO_vWRITEPORT(unsigned char portname , unsigned char data){
switch(portname){
	case'A':
	case'a':{
			GPIO_PORTA_DATA_R = data;
		break;	
		}
	case'B':
	case'b':{
			GPIO_PORTB_DATA_R = data;
		break;	
		}
	case'C':
	case'c':{
			GPIO_PORTC_DATA_R = data;
		break;	
		}
	case'D':
	case'd':{
			GPIO_PORTD_DATA_R = data;
		break;	
		}
	case'E':
	case'e':{
			GPIO_PORTE_DATA_R = data;
		break;	
		}
	case'F':
	case'f':{
			GPIO_PORTF_DATA_R = data;
		break;	
		}

}
}
unsigned char GPIO_u8READPIN(unsigned char portname, unsigned char pinnumber){
	switch(portname){
		case'A':
		case'a':{
		return	READ_BIT(GPIO_PORTA_DATA_R,pinnumber);
		
	}
		case'B':
		case'b':{
		return	READ_BIT(GPIO_PORTB_DATA_R,pinnumber);
}
		case'C':
		case'c':{
		return	READ_BIT(GPIO_PORTC_DATA_R,pinnumber);
		
}
		case'D':
		case'd':{
		return	READ_BIT(GPIO_PORTD_DATA_R,pinnumber);

}
		case'E':
		case'e':{
		return	READ_BIT(GPIO_PORTE_DATA_R,pinnumber);
}
		case'F':
		case'f':{
		return	READ_BIT(GPIO_PORTF_DATA_R,pinnumber);
}
		//break;
		}
	}