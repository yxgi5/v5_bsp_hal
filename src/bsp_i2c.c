/*
 * bsp_i2c.c
 *
 *  Created on: Jun 21, 2019
 *      Author: andy
 */

#include "bsp.h"

#if I2C1_EN == 1
I2C_HandleTypeDef I2c1Handle;
#define I2C1_ADDRESS        0x1E
#endif
#if I2C2_EN == 1
I2C_HandleTypeDef I2c2Handle;
#define I2C2_ADDRESS        0x2E
#endif
#if I2C3_EN == 1
I2C_HandleTypeDef I2c3Handle;
#define I2C3_ADDRESS        0x3E
#endif

#if I2C1_EN == 1
void bsp_InitI2C1(void)
{
  I2c1Handle.Instance             = I2C1;

  I2c1Handle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
  I2c1Handle.Init.ClockSpeed      = 100000;
  I2c1Handle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  I2c1Handle.Init.DutyCycle       = I2C_DUTYCYCLE_16_9;
  I2c1Handle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  I2c1Handle.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;
  I2c1Handle.Init.OwnAddress1     = I2C1_ADDRESS;
  I2c1Handle.Init.OwnAddress2     = 0xFE;

  if(HAL_I2C_Init(&I2c1Handle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler(__FILE__, __LINE__);
  }
}

#endif // I2C1_EN

#if I2C2_EN == 1
void bsp_InitI2C2(void)
{
  I2c2Handle.Instance             = I2C2;

  I2c2Handle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
  I2c2Handle.Init.ClockSpeed      = 100000;
  I2c2Handle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  I2c2Handle.Init.DutyCycle       = I2C_DUTYCYCLE_16_9;
  I2c2Handle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  I2c2Handle.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;
  I2c2Handle.Init.OwnAddress1     = I2C2_ADDRESS;
  I2c2Handle.Init.OwnAddress2     = 0xFE;

  if(HAL_I2C_Init(&I2c2Handle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler(__FILE__, __LINE__);
  }
}

#endif // I2C2_EN

#if I2C3_EN == 1
void bsp_InitI2C3(void)
{
  I2c3Handle.Instance             = I2C3;

  I2c3Handle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
  I2c3Handle.Init.ClockSpeed      = 100000;
  I2c3Handle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  I2c3Handle.Init.DutyCycle       = I2C_DUTYCYCLE_16_9;
  I2c3Handle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  I2c3Handle.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;
  I2c3Handle.Init.OwnAddress1     = I2C3_ADDRESS;
  I2c3Handle.Init.OwnAddress2     = 0xFE;

  if(HAL_I2C_Init(&I2c3Handle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler(__FILE__, __LINE__);
  }
}

#endif // I2C3_EN

/**
  * @brief I2C MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  *           - DMA configuration for transmission request by peripheral
  *           - NVIC configuration for DMA interrupt request enable
  * @param hi2c: I2C handle pointer
  * @retval None
  */
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c)
{
  GPIO_InitTypeDef  GPIO_InitStruct = {0};

#if I2C1_EN == 1
//  if(hi2c->Instance==I2C1)
//  {
    /*##-1- Enable GPIO Clocks #################################################*/
    /* Enable GPIO TX/RX clock */
    I2C1_SCL_GPIO_CLK_ENABLE();
    I2C1_SDA_GPIO_CLK_ENABLE();

    /*##-2- Configure peripheral GPIO ##########################################*/
    /* I2C TX GPIO pin configuration  */
    GPIO_InitStruct.Pin       = I2C1_SCL_PIN;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = I2C1_SCL_SDA_AF;
    HAL_GPIO_Init(I2C1_SCL_GPIO_PORT, &GPIO_InitStruct);

    /* I2C RX GPIO pin configuration  */
    GPIO_InitStruct.Pin = I2C1_SDA_PIN;
//    GPIO_InitStruct.Alternate = I2C1_SCL_SDA_AF;
    HAL_GPIO_Init(I2C1_SDA_GPIO_PORT, &GPIO_InitStruct);

    /*##-3- Enable I2C peripherals Clock #######################################*/
    /* Enable I2C1 clock */
    I2C1_CLK_ENABLE();

    /*##-4- Configure the NVIC for I2C #########################################*/
    /* NVIC for I2C1 */
    HAL_NVIC_SetPriority(I2C1_ER_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
    HAL_NVIC_SetPriority(I2C1_EV_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
//  }
#endif

#if I2C2_EN == 1
//  else if(hi2c->Instance==I2C2)
//  {
      /*##-1- Enable GPIO Clocks #################################################*/
      /* Enable GPIO TX/RX clock */
      I2C2_SCL_GPIO_CLK_ENABLE();
      I2C2_SDA_GPIO_CLK_ENABLE();

      /*##-2- Configure peripheral GPIO ##########################################*/
      /* I2C TX GPIO pin configuration  */
      GPIO_InitStruct.Pin       = I2C2_SCL_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
      GPIO_InitStruct.Pull      = GPIO_PULLUP;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
      GPIO_InitStruct.Alternate = I2C2_SCL_SDA_AF;
      HAL_GPIO_Init(I2C2_SCL_GPIO_PORT, &GPIO_InitStruct);

      /* I2C RX GPIO pin configuration  */
      GPIO_InitStruct.Pin = I2C2_SDA_PIN;
  //    GPIO_InitStruct.Alternate = I2C2_SCL_SDA_AF;
      HAL_GPIO_Init(I2C2_SDA_GPIO_PORT, &GPIO_InitStruct);

      /*##-3- Enable I2C peripherals Clock #######################################*/
      /* Enable I2C2 clock */
      I2C2_CLK_ENABLE();

      /*##-4- Configure the NVIC for I2C #########################################*/
      /* NVIC for I2C2 */
      HAL_NVIC_SetPriority(I2C2_ER_IRQn, 1, 0);
      HAL_NVIC_EnableIRQ(I2C2_ER_IRQn);
      HAL_NVIC_SetPriority(I2C2_EV_IRQn, 2, 0);
      HAL_NVIC_EnableIRQ(I2C2_EV_IRQn);
//  }
#endif

#if I2C3_EN == 1
//  else if(hi2c->Instance==I2C3)
//  {
      /*##-1- Enable GPIO Clocks #################################################*/
      /* Enable GPIO TX/RX clock */
      I2C3_SCL_GPIO_CLK_ENABLE();
      I2C3_SDA_GPIO_CLK_ENABLE();

      /*##-2- Configure peripheral GPIO ##########################################*/
      /* I2C TX GPIO pin configuration  */
      GPIO_InitStruct.Pin       = I2C3_SCL_PIN;
      GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
      GPIO_InitStruct.Pull      = GPIO_PULLUP;
      GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
      GPIO_InitStruct.Alternate = I2C3_SCL_SDA_AF;
      HAL_GPIO_Init(I2C3_SCL_GPIO_PORT, &GPIO_InitStruct);

      /* I2C RX GPIO pin configuration  */
      GPIO_InitStruct.Pin = I2C3_SDA_PIN;
  //    GPIO_InitStruct.Alternate = I2C3_SCL_SDA_AF;
      HAL_GPIO_Init(I2C3_SDA_GPIO_PORT, &GPIO_InitStruct);

      /*##-3- Enable I2C peripherals Clock #######################################*/
      /* Enable I2C3 clock */
      I2C3_CLK_ENABLE();

      /*##-4- Configure the NVIC for I2C #########################################*/
      /* NVIC for I2C3 */
      HAL_NVIC_SetPriority(I2C3_ER_IRQn, 1, 0);
      HAL_NVIC_EnableIRQ(I2C3_ER_IRQn);
      HAL_NVIC_SetPriority(I2C3_EV_IRQn, 2, 0);
      HAL_NVIC_EnableIRQ(I2C3_EV_IRQn);
//  }
#endif
}

/**
  * @brief I2C MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO, DMA and NVIC configuration to their default state
  * @param hi2c: I2C handle pointer
  * @retval None
  */
void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c)
{
#if I2C1_EN == 1
//  if(hi2c->Instance==I2C1)
//  {
    /*##-1- Reset peripherals ##################################################*/
    I2C1_FORCE_RESET();
    I2C1_RELEASE_RESET();

    /*##-2- Disable peripherals and GPIO Clocks ################################*/
    /* Configure I2C Tx as alternate function  */
    HAL_GPIO_DeInit(I2C1_SCL_GPIO_PORT, I2C1_SCL_PIN);
    /* Configure I2C Rx as alternate function  */
    HAL_GPIO_DeInit(I2C1_SDA_GPIO_PORT, I2C1_SDA_PIN);

    /*##-3- Disable the NVIC for I2C ###########################################*/
    HAL_NVIC_DisableIRQ(I2C1_ER_IRQn);
    HAL_NVIC_DisableIRQ(I2C1_EV_IRQn);
//  }
#endif
#if I2C2_EN == 1
//  else if(hi2c->Instance==I2C2)
//  {
    /*##-1- Reset peripherals ##################################################*/
    I2C2_FORCE_RESET();
    I2C2_RELEASE_RESET();

    /*##-2- Disable peripherals and GPIO Clocks ################################*/
    /* Configure I2C Tx as alternate function  */
    HAL_GPIO_DeInit(I2C2_SCL_GPIO_PORT, I2C2_SCL_PIN);
    /* Configure I2C Rx as alternate function  */
    HAL_GPIO_DeInit(I2C2_SDA_GPIO_PORT, I2C2_SDA_PIN);

    /*##-3- Disable the NVIC for I2C ###########################################*/
    HAL_NVIC_DisableIRQ(I2C2_ER_IRQn);
    HAL_NVIC_DisableIRQ(I2C2_EV_IRQn);
//  }
#endif
#if I2C3_EN == 1
//  else if(hi2c->Instance==I2C3)
//  {
    /*##-1- Reset peripherals ##################################################*/
    I2C3_FORCE_RESET();
    I2C3_RELEASE_RESET();

    /*##-2- Disable peripherals and GPIO Clocks ################################*/
    /* Configure I2C Tx as alternate function  */
    HAL_GPIO_DeInit(I2C3_SCL_GPIO_PORT, I2C3_SCL_PIN);
    /* Configure I2C Rx as alternate function  */
    HAL_GPIO_DeInit(I2C3_SDA_GPIO_PORT, I2C3_SDA_PIN);

    /*##-3- Disable the NVIC for I2C ###########################################*/
    HAL_NVIC_DisableIRQ(I2C1_ER_IRQn);
    HAL_NVIC_DisableIRQ(I2C1_EV_IRQn);
//  }
#endif
}


uint8_t i2c_SendByte(I2C_HandleTypeDef *hi2c, uint8_t *_ucBuffer, uint16_t SlaveAddr)
{
  do
  {
    if(HAL_I2C_Master_Transmit_IT(hi2c, SlaveAddr, _ucBuffer, 1) != HAL_OK)
    {
      /* Error_Handler() function is called when error occurs. */
      Error_Handler(__FILE__, __LINE__);
      return 1;
    }

    /*##-5- Wait for the end of the transfer #################################*/
    /*  Before starting a new communication transfer, you need to check the current
        state of the peripheral; if it�s busy you need to wait for the end of current
        transfer before starting a new one.
        For simplicity reasons, this example is just waiting till the end of the
        transfer, but application may perform other tasks while transfer operation
        is ongoing. */
    while (HAL_I2C_GetState(hi2c) != HAL_I2C_STATE_READY)
    {
    }

    /* When Acknowledge failure occurs (Slave don't acknowledge it's address)
       Master restarts communication */
  }
  while(HAL_I2C_GetError(hi2c) == HAL_I2C_ERROR_AF);

  return 0;
}

uint8_t i2c_ReadByte(I2C_HandleTypeDef *hi2c, uint8_t *_ucBuffer, uint16_t SlaveAddr)
{
  do
  {
    if(HAL_I2C_Master_Receive_IT(hi2c, SlaveAddr, _ucBuffer, 1) != HAL_OK)
    {
      /* Error_Handler() function is called when error occurs. */
      Error_Handler(__FILE__, __LINE__);
      return 1;
    }

    /*##-5- Wait for the end of the transfer #################################*/
    /*  Before starting a new communication transfer, you need to check the current
        state of the peripheral; if it�s busy you need to wait for the end of current
        transfer before starting a new one.
        For simplicity reasons, this example is just waiting till the end of the
        transfer, but application may perform other tasks while transfer operation
        is ongoing. */
    while (HAL_I2C_GetState(hi2c) != HAL_I2C_STATE_READY)
    {
    }

    /* When Acknowledge failure occurs (Slave don't acknowledge it's address)
       Master restarts communication */
  }
  while(HAL_I2C_GetError(hi2c) == HAL_I2C_ERROR_AF);

  return 0;
}

uint8_t i2c_SendBytes(I2C_HandleTypeDef *hi2c, uint8_t *_ucBuffer, uint16_t ByteCount, uint16_t SlaveAddr)
{
  do
  {
    if(HAL_I2C_Master_Transmit_IT(hi2c, SlaveAddr, _ucBuffer, ByteCount) != HAL_OK)
//  if(HAL_I2C_Mem_Write_IT(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size)!= HAL_OK)
    {
      /* Error_Handler() function is called when error occurs. */
      Error_Handler(__FILE__, __LINE__);
      return 1;
    }

    /*##-5- Wait for the end of the transfer #################################*/
    /*  Before starting a new communication transfer, you need to check the current
        state of the peripheral; if it�s busy you need to wait for the end of current
        transfer before starting a new one.
        For simplicity reasons, this example is just waiting till the end of the
        transfer, but application may perform other tasks while transfer operation
        is ongoing. */
    while (HAL_I2C_GetState(hi2c) != HAL_I2C_STATE_READY)
    {
    }

    /* When Acknowledge failure occurs (Slave don't acknowledge it's address)
       Master restarts communication */
  }
  while(HAL_I2C_GetError(hi2c) == HAL_I2C_ERROR_AF);

  return 0;
}

uint8_t i2c_ReadBytes(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size)
{

  do
  {
    if(HAL_I2C_Mem_Read_IT(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size)!= HAL_OK)
    {
    /* Error_Handler() function is called when error occurs. */
    Error_Handler(__FILE__, __LINE__);
    return 1;
    }

    /*  Before starting a new communication transfer, you need to check the current
      state of the peripheral; if it抯 busy you need to wait for the end of current
      transfer before starting a new one.
      For simplicity reasons, this example is just waiting till the end of the
      transfer, but application may perform other tasks while transfer operation
      is ongoing. */
    while (HAL_I2C_GetState(hi2c) != HAL_I2C_STATE_READY)
    {
    }

    /* When Acknowledge failure occurs (Slave don't acknowledge it's address)
     Master restarts communication */
  }
  while(HAL_I2C_GetError(hi2c) == HAL_I2C_ERROR_AF);

  return 0;
}

uint8_t i2c_CheckDevice(I2C_HandleTypeDef *hi2c, uint8_t _Address)
{
  uint8_t tmp,ret;
  ret=i2c_ReadByte(hi2c, &tmp,_Address);

  return ret; // 1 为异常
}

#if I2C1_EN == 1
/**
  * @brief  This function handles I2C event interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C data transmission
  */
void I2C1_EV_IRQHandler(void)
{
  HAL_I2C_EV_IRQHandler(& I2c1Handle);
}

/**
  * @brief  This function handles I2C error interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C error
  */
void I2C1_ER_IRQHandler(void)
{
  HAL_I2C_ER_IRQHandler(& I2c1Handle);
}
#endif

#if I2C2_EN == 1
/**
  * @brief  This function handles I2C event interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C data transmission
  */
void I2C2_EV_IRQHandler(void)
{
  HAL_I2C_EV_IRQHandler(& I2c2Handle);
}

/**
  * @brief  This function handles I2C error interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C error
  */
void I2C2_ER_IRQHandler(void)
{
  HAL_I2C_ER_IRQHandler(& I2c2Handle);
}
#endif

#if I2C3_EN == 1
/**
  * @brief  This function handles I2C event interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C data transmission
  */
void I2C3_EV_IRQHandler(void)
{
  HAL_I2C_EV_IRQHandler(& I2c3Handle);
}

/**
  * @brief  This function handles I2C error interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C error
  */
void I2C3_ER_IRQHandler(void)
{
  HAL_I2C_ER_IRQHandler(& I2c3Handle);
}
#endif
