#include "tm4c123gh6pm.h"
#include "stdint.h"
void SysTickWait1msec(){
		NVIC_ST_CTRL_R=0;
		NVIC_ST_RELOAD_R = 16000 - 1;
		NVIC_ST_CURRENT_R=0;
		NVIC_ST_CTRL_R=0x05;
		while((NVIC_ST_CTRL_R&0x00010000)==0){}		
	}
	

	
uint32_t j;
	void count_msec(uint32_t Time) {
	  for (j=0; j<Time; j++){
	    SysTickWait1msec(); 
	  }
	 }
uint32_t i;
	void count_sec(uint32_t Time) {
	  for (i=0; i<Time; i++){
	    count_msec(time); 
	  }
	}