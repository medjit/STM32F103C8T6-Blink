	//include libraries
#include "stm32f10x_gpio.h"
#include "stm32f10x_conf.h"
#include "stm32f10x_rcc.h"


	//create wait function
void waitForMoment(long iterations){
	unsigned long a = iterations * 10000;
	for(unsigned long i = 0; i <= a; i++){
	}
}

int main(void){
	//set registers
	RCC ->APB2ENR |= (1<<4);	//set GPIO clock max speed 2MHz
	GPIOC ->CRH |= (0X02<<20);	//set pin PC13 to output

    while(1){
    	//turn on the led
    	GPIOC->ODR |= (1<<13);
    	//wait
    	waitForMoment(100);
    	//turn off the led
    	GPIOC->ODR &=~(1<<13);
    	//wait
    	waitForMoment(100);
    }
}
