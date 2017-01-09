#include "app.h"
/*#include "Driver_M25P16.h"
#include "Driver_DS1820B.h"
#include "Driver_LCD.h"
*/
// System Drivers
//M25P16 flash; 
//LCD lcd;
//DS1820B ds1820;


static void APP_SetupOnce(void)
{

}

void APP_Run_StateMachine(void)
{
	APP_SetupOnce();
	while(1)
	{
		// Do some work here.
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{	
	// Timer 1 (1.0000Hz)
	if (htim->Instance == TIM1)
	{
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
	}
	
	// Timer 2 (50.0000Hz)
	else if (htim->Instance == TIM2)
	{		
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
	}
	
	// Timer 3 (10.0000Hz)
	else if (htim->Instance == TIM3)
	{	
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
	}
	
	// Timer 4 (5.0000Hz)
	else if (htim->Instance == TIM4)
	{			
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
	}	
}


