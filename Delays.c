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
uint32_t i;
	void delay_s(uint32_t Time) {
	  for (i=Time; i>0 ; i--){
	    delay_ms(1000); 
	  }
	}

