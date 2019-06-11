/**
  ******************************************************************************
  * @file    bsp_led.h
  * @author  Andreas
  * @version V1.0
  * @date    05-June-2019
  * @brief   BSP led driver header.
  ******************************************************************************
*/
#ifndef __BSP_LED_H
#define __BSP_LED_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "bsp.h"


typedef enum
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  LED4 = 3
} Led_TypeDef;


#ifdef STM32_V5

  /*
      armfly STM32-V5 has 4 user LEDs：
      LD1     : PI10/TP_NCS          (low on，high off)
      LD2     : PF7/NRF24L01_CSN     (low on，high off)
      LD3     : PF8/SF_CS            (low on，high off)
      LD4     : PC2/NRF905_CSN/VS1053_XCS  (low on，high off)
  */


  #define LEDn  4

  #define GPIO_PORT_LED1  GPIOI
  #define GPIO_PIN_LED1 GPIO_PIN_10

  #define GPIO_PORT_LED2  GPIOF
  #define GPIO_PIN_LED2 GPIO_PIN_7

  #define GPIO_PORT_LED3  GPIOF
  #define GPIO_PIN_LED3 GPIO_PIN_8

  #define GPIO_PORT_LED4  GPIOC
  #define GPIO_PIN_LED4 GPIO_PIN_2

  #define GPIO_CLK_ENABLE_LED1()           __HAL_RCC_GPIOI_CLK_ENABLE()
  #define GPIO_CLK_DISABLE_LED1()          __HAL_RCC_GPIOI_CLK_DISABLE()

  #define GPIO_CLK_ENABLE_LED2()           __HAL_RCC_GPIOF_CLK_ENABLE()
  #define GPIO_CLK_DISABLE_LED2()          __HAL_RCC_GPIOF_CLK_DISABLE()

  #define GPIO_CLK_ENABLE_LED3()           __HAL_RCC_GPIOF_CLK_ENABLE()
  #define GPIO_CLK_DISABLE_LED3()          __HAL_RCC_GPIOF_CLK_DISABLE()

  #define GPIO_CLK_ENABLE_LED4()           __HAL_RCC_GPIOC_CLK_ENABLE()
  #define GPIO_CLK_DISABLE_LED4()          __HAL_RCC_GPIOC_CLK_DISABLE()


  #define ALL_LED_GPIO_CLK_ENABLE() { \
    __HAL_RCC_GPIOC_CLK_ENABLE(); \
    __HAL_RCC_GPIOF_CLK_ENABLE(); \
    __HAL_RCC_GPIOI_CLK_ENABLE(); \
  };

#endif // STM32_V5

  #define GPIO_CLK_ENABLE_LEDx(__INDEX__) do{if((__INDEX__) == 0) GPIO_CLK_ENABLE_LED1(); else \
                                           if((__INDEX__) == 1) GPIO_CLK_ENABLE_LED2(); else \
                                           if((__INDEX__) == 2) GPIO_CLK_ENABLE_LED3(); else \
                                           if((__INDEX__) == 3) GPIO_CLK_ENABLE_LED4(); \
                                           }while(0)

  #define GPIO_CLK_DISABLE_LEDx(__INDEX__) do{if((__INDEX__) == 0) GPIO_CLK_DISABLE_LED1(); else \
                                            if((__INDEX__) == 1) GPIO_CLK_DISABLE_LED2(); else \
                                            if((__INDEX__) == 2) GPIO_CLK_DISABLE_LED3(); else \
                                            if((__INDEX__) == 3) GPIO_CLK_DISABLE_LED4(); \
                                            }while(0)


void     BSP_LED_Init(Led_TypeDef Led);
void     BSP_LED_On(Led_TypeDef Led);
void     BSP_LED_Off(Led_TypeDef Led);
void     BSP_LED_Toggle(Led_TypeDef Led);
void bsp_InitLed(void);
void bsp_LedOn(uint8_t _no);
void bsp_LedOff(uint8_t _no);
void bsp_LedToggle(uint8_t _no);
uint8_t bsp_IsLedOn(uint8_t _no);

#endif // __BSP_LED_H

