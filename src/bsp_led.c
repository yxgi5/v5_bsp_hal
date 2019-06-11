/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  Andreas
  * @version V1.0
  * @date    05-June-2019
  * @brief   BSP led driver.
  ******************************************************************************
*/


#include "bsp.h"

GPIO_TypeDef* GPIO_PORT[LEDn] = {GPIO_PORT_LED1,
                                GPIO_PORT_LED2,
                                GPIO_PORT_LED3,
                                GPIO_PORT_LED4};
const uint16_t GPIO_PIN[LEDn] = {GPIO_PIN_LED1,
                                GPIO_PIN_LED2,
                                GPIO_PIN_LED3,
                                GPIO_PIN_LED4};


void bsp_InitLed(void)
{
  BSP_LED_Init(LED1);
  BSP_LED_Init(LED2);
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED4);
}
/**
  * @brief  Configures LED GPIO.
  * @param  Led: Specifies the Led to be configured.
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  */
void BSP_LED_Init(Led_TypeDef Led)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  /* Enable the GPIO_LED Clock */
  GPIO_CLK_ENABLE_LEDx(Led);

  /* Configure the GPIO_LED pin */
  GPIO_InitStruct.Pin = GPIO_PIN[Led];
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

  bsp_LedOff(Led);
  HAL_GPIO_Init(GPIO_PORT[Led], &GPIO_InitStruct);

  HAL_GPIO_WritePin(GPIO_PORT[Led], GPIO_PIN[Led], GPIO_PIN_SET);
}


void bsp_LedOn(uint8_t _no)
{
  _no--;

  if (_no == 0)
  {
    GPIO_PORT_LED1->BSRR = (uint32_t)GPIO_PIN_LED1 << 16U;
  }
  else if (_no == 1)
  {
    GPIO_PORT_LED2->BSRR = (uint32_t)GPIO_PIN_LED2 << 16U;
  }
  else if (_no == 2)
  {
    GPIO_PORT_LED3->BSRR = (uint32_t)GPIO_PIN_LED3 << 16U;
  }
  else if (_no == 3)
  {
    GPIO_PORT_LED4->BSRR = (uint32_t)GPIO_PIN_LED4 << 16U;
  }
}
/**
  * @brief  Turns selected LED On.
  * @param  Led: Specifies the Led to be set on.
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  */
void BSP_LED_On(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(GPIO_PORT[Led], GPIO_PIN[Led], GPIO_PIN_RESET);
}


void bsp_LedOff(uint8_t _no)
{
  _no--;

  if (_no == 0)
  {
    GPIO_PORT_LED1->BSRR = GPIO_PIN_LED1;
  }
  else if (_no == 1)
  {
    GPIO_PORT_LED2->BSRR = GPIO_PIN_LED2;
  }
  else if (_no == 2)
  {
    GPIO_PORT_LED3->BSRR = GPIO_PIN_LED3;
  }
  else if (_no == 3)
  {
    GPIO_PORT_LED4->BSRR = GPIO_PIN_LED4;
  }
}
/**
  * @brief  Turns selected LED Off.
  * @param  Led: Specifies the Led to be set off.
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  */
void BSP_LED_Off(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(GPIO_PORT[Led], GPIO_PIN[Led], GPIO_PIN_SET);
}

/**
  * @brief  Toggles the selected LED.
  * @param  Led: Specifies the Led to be toggled.
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  */
void BSP_LED_Toggle(Led_TypeDef Led)
{
  HAL_GPIO_TogglePin(GPIO_PORT[Led], GPIO_PIN[Led]);
}

void bsp_LedToggle(uint8_t _no)
{
  if (_no == 1)
  {
    GPIO_PORT_LED1->ODR ^= GPIO_PIN_LED1;
  }
  else if (_no == 2)
  {
    GPIO_PORT_LED2->ODR ^= GPIO_PIN_LED2;
  }
  else if (_no == 3)
  {
    GPIO_PORT_LED3->ODR ^= GPIO_PIN_LED3;
  }
  else if (_no == 4)
  {
    GPIO_PORT_LED4->ODR ^= GPIO_PIN_LED4;
  }
}


uint8_t bsp_IsLedOn(uint8_t _no)
{
  if (_no == 1)
  {
    if ((GPIO_PORT_LED1->ODR & GPIO_PIN_LED1) == 0)
    {
      return 1;
    }
    return 0;
  }
  else if (_no == 2)
  {
    if ((GPIO_PORT_LED2->ODR & GPIO_PIN_LED2) == 0)
    {
      return 1;
    }
    return 0;
  }
  else if (_no == 3)
  {
    if ((GPIO_PORT_LED3->ODR & GPIO_PIN_LED3) == 0)
    {
      return 1;
    }
    return 0;
  }
  else if (_no == 4)
  {
    if ((GPIO_PORT_LED4->ODR & GPIO_PIN_LED4) == 0)
    {
      return 1;
    }
    return 0;
  }

  return 0;
}
