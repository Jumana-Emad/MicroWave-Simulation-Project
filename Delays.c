#include "tm4c123gh6pm.h"
#include "stdint.h"
void SysTick_wait_1ms() { //best is to disable then to enable
		NVIC_ST_CTRL_R=0;
		NVIC_ST_RELOAD_R = 16000 - 1;
		NVIC_ST_CURRENT_R=0;
		NVIC_ST_CTRL_R=0x05;
		while ((NVIC_ST_CTRL_R&0x00010000)==0){} //wait for count flag		
	}
	

	
 uint32_t i;
	void delay_ms (uint32_t time) {
	  for (i=0; i<time; i++){
	    SysTick_wait_1ms(); 
	  }	  
	}

char* formatTime(int time_seconds){
	// Change time from seconds to 00:00 format
	char time[5];
	time[0] = '0';
	time[1] = '0';
	time[2] = ':';
	time[3] = '0';
	time[4] = '0';
	
	int mins = (time_seconds / 60) ;
	int secs = (time_seconds % 60) ;
	
	char ones = (mins %10) +'0';
	char tens = ((mins /10) )+'0';
	char secones = (secs %10)+'0';
	char sectens = ((secs /10))+'0';
	
	
	time[0]=tens;
	time[1]=ones;
	time[3]=sectens;
	time[4] = secones;
	return time;
}

uint32_t j;
	void delay_s(uint32_t Time) {
	  for (j=Time; j>0 ; j--){
	    delay_ms(1000);
	    Send_string(formatTime(j));	  
	  }
	}
