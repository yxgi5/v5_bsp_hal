/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "bsp.h"

#define EXAMPLE_NAME  "V5-基于Systick滴答定时器的多组软件定时器实现"
#define EXAMPLE_DATE  "2018-12-12"
#define DEMO_VER    "1.0"

static void PrintfLogo(void);
static void PrintfHelp(void);


/*
*********************************************************************************************************
* 函 数 名: main
* 功能说明: c程序入口
* 形    参: 无
* 返 回 值: 错误代码(无需处理)
*********************************************************************************************************
*/
int main(void)
{
  uint8_t ucKeyCode;    /* 按键代码 */

  bsp_Init();   /* 硬件初始化 */

  PrintfLogo(); /* 打印例程名称和版本等信息 */
  PrintfHelp(); /* 打印操作提示 */


  bsp_StartAutoTimer(0, 100); /* 启动1个100ms的自动重装的定时器，软件定时器0 */
  bsp_StartAutoTimer(1, 100); /* 启动1个100ms的自动重装的定时器，软件定时器1 */


  /* 进入主程序循环体 */
  while (1)
  {
    bsp_Idle();   /* 这个函数在bsp.c文件。用户可以修改这个函数实现CPU休眠和喂狗 */

    /* 判断软件定时器0是否超时 */
    if (bsp_CheckTimer(0))
    {
      /* 每隔100ms 进来一次 */
      bsp_LedToggle(1);
    }

    /* 判断软件定时器1超时 */
    if (bsp_CheckTimer(1))
    {
      /* 每隔100ms 进来一次 */
      bsp_LedToggle(2);
    }

    /* 判断软件定时器2是否超时 */
    if (bsp_CheckTimer(2))
    {
      /* 单次模式，按下K1按键后，定时1秒进入 */
      bsp_LedToggle(3);
    }

    /* 判断软件定时器3是否超时 */
    if (bsp_CheckTimer(3))
    {
      /* 单次模式，按下K2按键后，定时2秒进入 */
      bsp_LedToggle(4);
    }


    /* 按键滤波和检测由后台systick中断服务程序实现，我们只需要调用bsp_GetKey读取键值即可。 */
    ucKeyCode = bsp_GetKey(); /* 读取键值, 无键按下时返回 KEY_NONE = 0 */
    if (ucKeyCode != KEY_NONE)
    {
      switch (ucKeyCode)
      {
        case KEY_DOWN_K1:     /* K1键按下，启动软件定时2，单次模式，定时0.5时间 */
          printf("K1键按下\r\n");
          bsp_StartTimer(2, 500);
          break;

        case KEY_DOWN_K2:     /* K2键按下，启动软件定时3，单次模式，定时1s时间  */
          printf("K2键按下\r\n");
          bsp_StartTimer(3, 1000);
          break;

        default:
          /* 其它的键值不处理 */
          break;
      }

    }
  }
}

/*
*********************************************************************************************************
* 函 数 名: PrintfHelp
* 功能说明: 打印操作提示
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
static void PrintfHelp(void)
{
  printf("操作提示:\r\n");
  printf("1. 启动一个自动重装软件定时器，每100ms翻转一次LED1和LED2\r\n");
  printf("2. 再启动一个自动重装软件定时器，每500ms翻转一次LED3和LED4\r\n");
}

/*
*********************************************************************************************************
* 函 数 名: PrintfLogo
* 功能说明: 打印例程名称和例程发布日期, 接上串口线后，打开PC机的超级终端软件可以观察结果
* 形    参: 无
* 返 回 值: 无
*********************************************************************************************************
*/
static void PrintfLogo(void)
{
  printf("*************************************************************\n\r");

  /* 检测CPU ID */
  {
    uint32_t CPU_Sn0, CPU_Sn1, CPU_Sn2;

    CPU_Sn0 = *(__IO uint32_t*)(0x1FFF7A10);
    CPU_Sn1 = *(__IO uint32_t*)(0x1FFF7A10 + 4);
    CPU_Sn2 = *(__IO uint32_t*)(0x1FFF7A10 + 8);

    printf("\r\nCPU : STM32F407IGT6, LQFP176, 主频: %dMHz\r\n", SystemCoreClock / 1000000);
    printf("UID = %08X %08X %08X\n\r", CPU_Sn2, CPU_Sn1, CPU_Sn0);
  }

  printf("\n\r");
  printf("*************************************************************\n\r");
  printf("* 例程名称   : %s\r\n", EXAMPLE_NAME);  /* 打印例程名称 */
  printf("* 例程版本   : %s\r\n", DEMO_VER);    /* 打印例程版本 */
  printf("* 发布日期   : %s\r\n", EXAMPLE_DATE);  /* 打印例程日期 */

  /* 打印ST的HAL库版本 */
  printf("* HAL库版本  : V1.3.0 (STM32H7xx HAL Driver)\r\n");
  printf("* \r\n"); /* 打印一行空格 */
  printf("* QQ    : 1295744630 \r\n");
  printf("* 旺旺  : armfly\r\n");
  printf("* Email : armfly@qq.com \r\n");
  printf("* 微信公众号: armfly_com \r\n");
  printf("* 淘宝店: armfly.taobao.com\r\n");
  printf("* Copyright www.armfly.com 安富莱电子\r\n");
  printf("*************************************************************\n\r");
}

