/*
 * bsp_i2c.h
 *
 *  Created on: Jun 21, 2019
 *      Author: andy
 */

#ifndef BSP_I2C_H_
#define BSP_I2C_H_

/*
 * PB6: I2C1_SCL , PB7: I2C1_SDA, not used
 * PH4: I2C2_SCL , PH5: I2C2_SDA
 * PH7: I2C3_SCL , PH8: I2C3_SDA, not used
 */

#define I2C1_EN 0
#define I2C2_EN 1
#define I2C3_EN 0

#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))


#if I2C1_EN == 1
#define I2C1_CLK_ENABLE()               __HAL_RCC_I2C1_CLK_ENABLE()
#define I2C1_SDA_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()
#define I2C1_SCL_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()

#define I2C1_FORCE_RESET()              __HAL_RCC_I2C1_FORCE_RESET()
#define I2C1_RELEASE_RESET()            __HAL_RCC_I2C1_RELEASE_RESET()

/* Definition for I2C1 Pins */
#define I2C1_SCL_PIN                    GPIO_PIN_6
#define I2C1_SCL_GPIO_PORT              GPIOB
#define I2C1_SDA_PIN                    GPIO_PIN_7
#define I2C1_SDA_GPIO_PORT              GPIOB
#define I2C1_SCL_SDA_AF                 GPIO_AF4_I2C1

///* Definition for I2Cx's NVIC */
//#define I2Cx_EV_IRQn                    I2C1_EV_IRQn
//#define I2Cx_EV_IRQHandler              I2C1_EV_IRQHandler
//#define I2Cx_ER_IRQn                    I2C1_ER_IRQn
//#define I2Cx_ER_IRQHandler              I2C1_ER_IRQHandler

void bsp_InitI2C1(void);
extern I2C_HandleTypeDef I2c1Handle;
#endif

#if I2C2_EN == 1
#define I2C2_CLK_ENABLE()               __HAL_RCC_I2C2_CLK_ENABLE()
#define I2C2_SDA_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOH_CLK_ENABLE()
#define I2C2_SCL_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOH_CLK_ENABLE()

#define I2C2_FORCE_RESET()              __HAL_RCC_I2C2_FORCE_RESET()
#define I2C2_RELEASE_RESET()            __HAL_RCC_I2C2_RELEASE_RESET()

#define I2C2_SCL_PIN                    GPIO_PIN_4
#define I2C2_SCL_GPIO_PORT              GPIOH
#define I2C2_SDA_PIN                    GPIO_PIN_5
#define I2C2_SDA_GPIO_PORT              GPIOH
#define I2C2_SCL_SDA_AF                 GPIO_AF4_I2C2
///* Definition for I2Cx's NVIC */
//#define I2Cx_EV_IRQn                    I2C2_EV_IRQn
//#define I2Cx_EV_IRQHandler              I2C2_EV_IRQHandler
//#define I2Cx_ER_IRQn                    I2C2_ER_IRQn
//#define I2Cx_ER_IRQHandler              I2C2_ER_IRQHandler


void bsp_InitI2C2(void);
extern I2C_HandleTypeDef I2c2Handle;

#endif

#if I2C3_EN == 1
#define I2C3_CLK_ENABLE()               __HAL_RCC_I2C3_CLK_ENABLE()
#define I2C3_SDA_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOH_CLK_ENABLE()
#define I2C3_SCL_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOH_CLK_ENABLE()

#define I2C3_FORCE_RESET()              __HAL_RCC_I2C3_FORCE_RESET()
#define I2C3_RELEASE_RESET()            __HAL_RCC_I2C3_RELEASE_RESET()

#define I2C3_SCL_PIN                    GPIO_PIN_7
#define I2C3_SCL_GPIO_PORT              GPIOH
#define I2C3_SDA_PIN                    GPIO_PIN_8
#define I2C3_SDA_GPIO_PORT              GPIOH
#define I2C3_SCL_SDA_AF                 GPIO_AF4_I2C3
///* Definition for I2Cx's NVIC */
//#define I2Cx_EV_IRQn                    I2C3_EV_IRQn
//#define I2Cx_EV_IRQHandler              I2C3_EV_IRQHandler
//#define I2Cx_ER_IRQn                    I2C3_ER_IRQn
//#define I2Cx_ER_IRQHandler              I2C3_ER_IRQHandler

void bsp_InitI2C2(void);
extern I2C_HandleTypeDef I2c2Handle;

#endif

uint8_t i2c_SendByte(I2C_HandleTypeDef *hi2c, uint8_t *_ucBuffer, uint16_t SlaveAddr);
uint8_t i2c_ReadByte(I2C_HandleTypeDef *hi2c, uint8_t *_ucBuffer, uint16_t SlaveAddr);
uint8_t i2c_SendBytes(I2C_HandleTypeDef *hi2c, uint8_t *_ucBuffer, uint16_t ByteCount, uint16_t SlaveAddr);
uint8_t i2c_ReadBytes(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);
uint8_t i2c_CheckDevice(I2C_HandleTypeDef *hi2c, uint8_t _Address);

#endif /* BSP_I2C_H_ */
