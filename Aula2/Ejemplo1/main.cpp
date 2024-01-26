//Ejemplo Hola mundo con led de usuario de la tarjeta
//Fabián Barrera Prieto
//UMNG
//STM32F303K8T6
//operation 'or' (|) for set bit and operation 'and' (&) for clear bit

#include <stdio.h>
#include "stm32f3xx.h"

void Delay (uint32_t time)
{
	while (time--);  
}

int main(){
	
	/************** STEPS TO FOLLOW *****************
	1. Enable GPIOD clock
	2. Set the PIN PD13 as output
	3. Configure the output mode i.e state, speed, and pull
	************************************************/
	//Reference manual chip
	//Step 1
	RCC->AHBENR |= (1<<20);  // Enable the GPIOD clock (user led LD3 is connected to D13)
	//Step 2
	GPIOD->MODER |= (1<<26); //pin PD13(bits 27:26) as Output (01)
	//Step 3
	GPIOD->OTYPER &= ~(1<<13);  // bit 13=0 --> Output push pull (HIGH or LOW)
	GPIOD->OSPEEDR |= ((1<<27)|(1<<26));//(11<<26)  // Pin PD13 (bits 27:26) as High Speed (11)
	GPIOD->PUPDR &= ~((1<<27)|(1<<26)); //~(11<<26) // Pin PD13 (bits 27:26) are 0:0 --> no pull up or pull down
	
	while(1){
		//GPIOD->BSRR |= (1<<13); // Set the Pin PD13
		GPIOD->ODR |= 1<<13; // Set the Pin PD13
		Delay(1000000);
		//GPIOD->BSRR |= (1<<29); // Reset the Pin PD13
		GPIOD->ODR &= ~(1<<13); // Reset the Pin PD13
		Delay(1000000);
	}

}
