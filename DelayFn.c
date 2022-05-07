void SysTick_wait_1ms() { //best is to disable then to enable
	NVIC_ST_CTRL_R=0;
	NVIC_ST_RELOAD_R = 80000 - 1;
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R=0x05;
	while ((NVIC_ST_CTRL_R&0x00010000)==0){ //wait for count flag
	}		
	
}


void delay_ms (uint32_t time) {
  uint32_t i;
  for (i=0; i<time; i++){
    SysTick_wait_1ms(); 
  }
  
}


void delay_s (uint32_t time){
  uint32_t i;
  for (i=0; i<time; i++){
    delay_ms(1000); 
  }
  
}

void delay_min (uint32_t time){
  uint32_t i;
  for (i=0; i<time; i++){
    delay_s(60); 
  }
  
}
