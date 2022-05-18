


static void Send_Pulse(void);
void LCD_Send_cmd(char cmd);
void LCD_vInit(void);
void LCD_Send_char(unsigned char chr);
void Send_string(char *data);
void LCD_Count(char* str);
void LCD_String(char* str);
void LCD_Write4bits(unsigned char data, unsigned char control);
void LCD_clearscreen(void);
void LCD_MoveCursor(char row, char col);
void Lcd_Shift_Right();
void Lcd_Shift_Left();

