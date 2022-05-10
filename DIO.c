#include "tm4c123gh6pm.h"
#include "Macros.c"
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
unsigned char GPIO_u8READPIN(unsigned char portname, unsigned char bitnumber){
	switch(portname){
		case'A':
		case'a':{
		return	READ_BIT(GPIO_PORTA_DATA_R,bitnumber);
		//break;
	}
		case'B':
		case'b':{
		return	READ_BIT(GPIO_PORTB_DATA_R,bitnumber);
}
		case'C':
		case'c':{
		return	READ_BIT(GPIO_PORTC_DATA_R,bitnumber);
		//break;
}
		case'D':
		case'd':{
		return	READ_BIT(GPIO_PORTD_DATA_R,bitnumber);

}
		case'E':
		case'e':{
		return	READ_BIT(GPIO_PORTE_DATA_R,bitnumber);
}
		case'F':
		case'f':{
		return	READ_BIT(GPIO_PORTF_DATA_R,bitnumber);
}
		//break;
		}
	}