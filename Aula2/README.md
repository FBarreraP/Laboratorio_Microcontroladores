<h1>Aula 2</h1>

En esta clase se presenta un instructivo de instalación en Windows del software `ARM-Keil` para programar las tarjetas STM32, además de un hola mundo con la tarjeta NUCLEO STM32F767ZI o NUCLEO STM32F756ZG o NUCLEO STM32F746ZG o NUCLEO STM32F722ZE.

<h2>Instrucciones instalación ARM-Keil</h2>

1. Ir a la página https://www.keil.com/download/product/
2. Seleccionar la opción <b>MDK-Arm</b> y diligenciar los datos requeridos
3. Descargar el archivo ejecutable (.exe)
4. Instalar el software `ARM-Keil` siguiendo el proceso de instalación e instalar el driver sugerido que aparece en la ventana emergente
5. Al finalizar la instalación, seleccionar la opción "OK" en la ventana emergente <i>Pack Installer</i>
6. Descargar los paquetes correspondientes al microcontrolador que se va a trabajar (ej: STM32F746), para lo cual se debe buscar la opción "STMIcroelectronics" en la pestaña "Devices"
7. Seleccionar el microcontrolador específico a trabajar y posteriormente instalar los paquetes requeridos, sin embargo, se recomiendan instalar y actualizar todos los paquetes para dicho microcontrolador y verificar que todos los paquetes tengan la etíqueta <i>Up to date</i>
8. Instalar y/o actualizar los paquetes seleccionados siguiendo el proceso de instalación

<h2>Ejemplo 'hola mundo'</h2>

1. Crear un nuevo proyecto seleccionando la opción "New Project" en la pestaña "Project"
2. 

```cpp

//Ejemplo Hola mundo con led de usuario de la tarjeta
//MSc. Fabián Barrera Prieto
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
```

<h3>Descargar el software STM32 ST-LINK utility</h3>

1. Descargar el software en el siguiente link: https://www.st.com/en/development-tools/stsw-link004.html
2. Instalar el software a través del proceso de instalación 



Otra información de apoyo puede ser encontrada en: <a>https://os.mbed.com/platforms/ST-Nucleo-F303K8/</a>
<li> Pines STM32F303K8</li>
    <img src="https://os.mbed.com/media/uploads/bcostm/nucleo_f303k8_2017_10_10.png" alt="STM32F303K8" caption="Hola"/>