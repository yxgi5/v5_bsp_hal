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

//static void PrintfLogo(void);
//static void PrintfHelp(void);


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

//  PrintfLogo(); /* 打印例程名称和版本等信息 */
//  PrintfHelp(); /* 打印操作提示 */


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
