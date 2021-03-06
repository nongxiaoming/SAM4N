#ifndef __DRV_KEY_H
#define __DRV_KEY_H
/************************************************************************************
*文件名  ：drv_key.h																 *
*文件作用：按键查询驱动																 *
*作者    ：农晓明																	 *
*作者QQ  ：382421307																 *
*文件创建时间：2013/10/11															 *																					 *
*************************************************************************************/
#include "sam4n.h"
#include "delay.h"

#define USER_BUTTON (0x01UL<<30)


/************************************************************************************************************
*函数名： Key_Scan()
*参数  ：void
*返回值：uint8_t  返回0为按下，1为没按下
*功能：按键GPIO的初始化函数，使用按键前必须先调用此函数进行初始化
************************************************************************************************************/
uint8_t Key_Scan(void);
/************************************************************************************************************
*函数名： Key_GPIO_Config()
*参数：void
*返回值：void
*功能：按键GPIO的初始化函数，使用按键前必须先调用此函数进行初始化
************************************************************************************************************/
void Key_GPIO_Config(void);
#endif
