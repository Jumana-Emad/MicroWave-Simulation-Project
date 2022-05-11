#include "lcd.c"


static void Send_Pulse(void);
void LCD_Send_cmd(char cmd);
void LCD_vInit(void);
void LCD_Send_char(char chr);
void Send_string(char *data);
void LCD_clearscreen(void);
void LCD_MoveCursor(char row, char col);
void Lcd_Shift_Right();
void Lcd_Shift_Left();

