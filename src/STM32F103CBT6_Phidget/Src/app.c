#include "app.h"


static void APP_SetupOnce(void)
{

}

void APP_Run_StateMachine(void)
{
	APP_SetupOnce();
	while(1)
	{

	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{	

	// Timer 1
	if (htim->Instance == TIM1)
	{
		HAL_GPIO_TogglePin(GPIOA, LED_0);		
	}
	
	// Timer 2
	/*else if (htim->Instance == TIM2)
	{		
		HAL_GPIO_TogglePin(GPIOB, LED_1);	
	}
	
	// Timer 3
	else if (htim->Instance == TIM3)
	{	
		HAL_GPIO_TogglePin(GPIOA, LED_2);	
	}
	
	// Timer 4
	else if (htim->Instance == TIM4)
	{			
		HAL_GPIO_TogglePin(GPIOA, LED_3);	
	}			*/
}
