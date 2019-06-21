/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "bsp.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;

SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  bsp_Init();

  /* Initialize all configured peripherals */
//  MX_GPIO_Init();
//  MX_I2C1_Init();
//  MX_I2C2_Init();
//  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    uint8_t ctrl=1;
    /* USER CODE END WHILE */
  uint8_t tmp[40]={12,2,3,4,5,6,7,8,9,10,\
  11,12,13,14,15,16,17,18,19,20,21,22,\
  23,24,25,26,27,28,29,30,31,32,33,34,\
  35,36,37,38,39,40};
//  ee_WriteBytes(&I2c1Handle, tmp,0,40);


  uint8_t tmp1[120]={0};

  ee_WriteBytes(&I2c2Handle, tmp, 78, sizeof(tmp));
//  if(ctrl)
//  {
//  do
//  {
//  if(HAL_I2C_Master_Transmit_IT(&I2c1Handle, EE_DEV_ADDR, tmp, 40) != HAL_OK)
//  //  if(HAL_I2C_Mem_Write_IT(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size)!= HAL_OK)
//  {
//    /* Error_Handler() function is called when error occurs. */
//    Error_Handler(__FILE__, __LINE__);
//    return 1;
//  }
//
//  /*##-5- Wait for the end of the transfer #################################*/
//  /*  Before starting a new communication transfer, you need to check the current
//    state of the peripheral; if it�s busy you need to wait for the end of current
//    transfer before starting a new one.
//    For simplicity reasons, this example is just waiting till the end of the
//    transfer, but application may perform other tasks while transfer operation
//    is ongoing. */
//  while (HAL_I2C_GetState(&I2c1Handle) != HAL_I2C_STATE_READY)
//  {
//  }
//
//  /* When Acknowledge failure occurs (Slave don't acknowledge it's address)
//     Master restarts communication */
//  }
//  while(HAL_I2C_GetError(&I2c1Handle) == HAL_I2C_ERROR_AF);
//  }

  HAL_Delay(100);
  ee_ReadBytes(&I2c2Handle, tmp1, 0, sizeof(tmp1));
  HAL_Delay(100);

//  do
//  {
//    if(HAL_I2C_Mem_Read_IT(&I2c1Handle, (uint16_t)EE_DEV_ADDR, 20, I2C_MEMADD_SIZE_8BIT, (uint8_t*)tmp1, sizeof(tmp1))!= HAL_OK)
//    {
//    /* Error_Handler() function is called when error occurs. */
//    Error_Handler(__FILE__, __LINE__);
//    }
//
//    /*  Before starting a new communication transfer, you need to check the current
//      state of the peripheral; if it抯 busy you need to wait for the end of current
//      transfer before starting a new one.
//      For simplicity reasons, this example is just waiting till the end of the
//      transfer, but application may perform other tasks while transfer operation
//      is ongoing. */
//    while (HAL_I2C_GetState(&I2c1Handle) != HAL_I2C_STATE_READY)
//    {
//    }
//
//    /* When Acknowledge failure occurs (Slave don't acknowledge it's address)
//     Master restarts communication */
//  }
//  while(HAL_I2C_GetError(&I2c1Handle) == HAL_I2C_ERROR_AF);
//  HAL_Delay(100);

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
