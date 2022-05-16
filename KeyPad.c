#include "DIO.h"

void Keypad_Init()
{
	//PORT_INIT(PortName);
	DIO_vSETPINDIRECTION('E', 0, 1);
	DIO_vSETPINDIRECTION('E', 1, 1);
	DIO_vSETPINDIRECTION('E', 2, 1);
	DIO_vSETPINDIRECTION('E', 3, 1);
	DIO_vSETPINDIRECTION('A', 4, 0);
	DIO_vSETPINDIRECTION('A', 5, 0);
	DIO_vSETPINDIRECTION('A', 6, 0);
	DIO_vSETPINDIRECTION('A', 7, 0);
	DIO_uEnablePullUp('A', 4);
	DIO_uEnablePullUp('A', 5);
	DIO_uEnablePullUp('A', 6);
	DIO_uEnablePullUp('A', 7);
}

unsigned char KeyPad_u8Read(unsigned char PortName)
{
	unsigned char array [4] [4] =
		{{'1','2','3','A'},
		 {'4','5','6','B'},
		 {'7','8','9','C'},
		 {'*','0','#','D'},
		};
	char Row, Column, x;
	char value_Returned = 0xFF;
	for (Row = 0; Row < 4; Row++)
		{
			DIO_uWriteLowNibble('E', 0xFF);
			DIO_vWRITEPIN ('E', Row, 0);
			for(Column = 4; Column < 8; Column++)
			{
				x = GPIO_u8READPIN('A', Column);
				if(x == 0)
				{value_Returned = array [Row] [Column-4];}
				break;
			}
			if(x == 0)
				{break;}
			return value_Returned;
		}
return 0;
}
