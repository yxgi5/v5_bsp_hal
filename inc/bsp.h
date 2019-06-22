/**
  ******************************************************************************
  * @file    bsp.h
  * @author  Andreas
  * @version V1.0
  * @date    05-June-2019
  * @brief   BSP header all in one.
  ******************************************************************************
*/

#ifndef _BSP_H_
#define _BSP_H_

#define STM32_V5 // bsp for armfly v5 (D030-3)

// check if board model has been defined
#if !defined (STM32_V5) && !defined (STM32_X3)
  #error "Please define the board model : STM32_X3 or STM32_V5"
#endif

// define bsp version
#define __STM32F1_BSP_VERSION   "1.1"

//#define CPU_IDLE()    bsp_Idle()

// set the Priority Mask Register
#define ENABLE_INT()  __set_PRIMASK(0)
#define DISABLE_INT() __set_PRIMASK(1)

#define BSP_Printf    printf
//#define BSP_Printf(...)

#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef TRUE
  #define TRUE  1
#endif

#ifndef FALSE
  #define FALSE 0
#endif

// put EXTI9_5_IRQHandler in stm32f4xx_it.c
#define EXTI9_5_ISR_MOVE_OUT

#define DEBUG_GPS_TO_COM1

#define ERROR_HANDLER()   Error_Handler(__FILE__, __LINE__);

#define  Enable_EventRecorder  0

#if Enable_EventRecorder == 1
  #include "EventRecorder.h"
#endif

#include "bsp_uart_fifo.h"
#include "bsp_led.h"
#include "bsp_timer.h"
#include "bsp_key.h"
#include "bsp_i2c.h"
#include "bsp_i2c_eeprom_24xx.h"
#include "bsp_spi.h"
//#include "bsp_exti.h"
//#include "bsp_modbus.h"
//#include "bsp_user_lib.h"

void bsp_Idle(void);
void bsp_Init(void);
//static void NVIC_Configuration(void);
void Error_Handler(char *file, uint32_t line);

#endif // _BSP_H_
