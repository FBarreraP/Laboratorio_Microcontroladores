//Ejemplo Hola mundo con led de usuario de la tarjeta
//Fabián Barrera Prieto
//UMNG
//STM32F303K8T6

#include <stdio.h>
#include "STM32F3xx.h"

int time = 500000;

int main(){
	int i = 0;
	int cont = 0;
	
	/************** STEPS TO FOLLOW *****************
	1. Enable GPIOD clock
	2. Set the PIN PD13 as output
	3. Configure the output mode i.e state, speed, and pull
	************************************************/
	//Reference manual chip
	//Step 1
	RCC->AHB1ENR |= (1<<20);  // Enable the GPIOD clock (user led LD3 is connected to D13)
	//Step 2
	GPIOD->MODER |= (1<<26); //pin PD13(bits 27:26) as Output (01)
	//Step 3
	GPIOD->OTYPER &= ~(1<<13);  // bit 13=0 --> Output push pull (HIGH or LOW)
	GPIOD->OSPEEDR |= (1<<11);  // Pin PA5 (bits 11:10) as Fast Speed (1:0)
	GPIOD->PUPDR &= ~((1<<10) | (1<<11));  // Pin PA5 (bits 11:10) are 0:0 --> no pull up or pulldown
	
	while(1){
		GPIOD->BSRR |= (1<<5); // Set the Pin PA5
		GPIOD->ODR |= 1<<5; // Set the Pin PA5
		wait
		GPIOD->BSRR |= (1<<21); // Reset the Pin PA5
		GPIOD->ODR &= ~(1<<5); // Reset the Pin PA5
		wait
	}

}
