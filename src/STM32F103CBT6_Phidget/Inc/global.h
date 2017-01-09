#ifndef __GLOBAL__
#define __GLOBAL__
#include "stm32f1xx_hal.h"

/* Hal Level Varibles names match generated varible names*/
extern RTC_HandleTypeDef hrtc;
extern I2C_HandleTypeDef hi2c1;
extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

/* Application Level Macros */
#define BUFFERSIZE	COUNTOF(aTxBuffer) 
#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))
#define DHIGH(x) ((x&0xff0000)>>16)
#define DMID(x) ((x&0xff00)>>8)
#define DLOW(x) (x&0xff)
#define HIGH 1
#define LOW 0

/* GPIO PINS */
#define LED_0 GPIO_PIN_12
#define LED_1 GPIO_PIN_1
#define LED_2 GPIO_PIN_11
#define LED_3 GPIO_PIN_3
#define CS_FLASH GPIO_PIN_4


#endif
