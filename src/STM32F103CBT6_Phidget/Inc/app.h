#ifndef __PHIDGET_APP_H__
#define __PHIDGET_APP_H__

#include "global.h"

#ifdef __cplusplus
 extern "C" {
#endif 


/* Main Application Entry Point */
void APP_Run_StateMachine(void);

/* Handler for ALL timer releated code*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

/* Setup code for microcontroller*/
static void APP_SetupOnce(void);



#endif /* __PHIDGET_APP_H__ */
