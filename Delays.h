#include "tm4c123gh6pm.h"
#include "stdint.h"
void SysTick_wait_1ms();
void delay_ms (uint32_t time);
void delay_s(uint32_t Time);
char* formatTime(int time_seconds);
extern int back;
