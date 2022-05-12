#include "DIO.h"
#include "Button.h"

void Keypad_Init(unsigned char PortName)
{
	Port_Init(PortName);
	DIO_vSETPINDIRECTION("D", 0, 1);
	DIO_vSETPINDIRECTION("D", 1, 1);
	DIO_vSETPINDIRECTION("D", 2, 1);
	DIO_vSETPINDIRECTION("D", 3, 1);
	DIO_vSETPINDIRECTION("A", 4, 0);
	DIO_vSETPINDIRECTION("A", 5, 0);
	DIO_vSETPINDIRECTION("A", 6, 0);
	DIO_vSETPINDIRECTION("A", 7, 0);
	DIO_uEnablePullUp(PortName, 4);
	DIO_uEnablePullUp(PortName, 5);
	DIO_uEnablePullUp(PortName, 6);
	DIO_uEnablePullUp(PortName, 7);
}

unsigned char KeyPad_u8Read(unsigned char PortName)
{
	unsigned char array [4] [4] =
		{{'1','2','3','A'},
		 {'4','5','6','B'},
		 {'7','8','9','C'},
		 {'*','0','#','D'},
		}
	char Row, Column, x;
	char value_Returned = oxFF;
	for (Row = 0; Row < 4; Row++)
		{
			DIO_uWriteLowNibble(PortName) = oxFF;
			DIO_vWRITEPIN (PortName, Row, 0);
			for(Column = 4; Column < 8; Column++)
			{
				x = GPIO_u8READPIN(PortName, Column);
				if(x == 0)
				{value_Returned = array [Row] [Column];}
				break;
			}
			if(x == 0)
				{break;}
			return value_Returned;
		}
}
