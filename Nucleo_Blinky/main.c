#include <stdlib.h>
#include "Board_LED.h"
#include "Board_Buttons.h"

void delay(void);
void func1(void);
void func2(void);
void func3(void);
void ram_read(void);
int value = 0;
void ram_read(void){
	uint32_t *ram_ptr = (uint32_t *)0x20000000;
	value = *ram_ptr;
}	

void delay(void){
	for(int i = 0;i < 500000;i++);
}

void func1(void){
	func2();
}

void func2(void){
	func3();
}

void func3(void){
	void (*goto_func)(void) = 0x00000000;
	goto_func();
}

int main(void){
	LED_Initialize();
	ram_read();
//	Buttons_Initialize();
	while(1){
			func1();
//		if(Buttons_GetState() == 1){
			LED_On(0);
			delay();
			LED_Off(0);
			delay();
//		}
	}
	return 0;
}
