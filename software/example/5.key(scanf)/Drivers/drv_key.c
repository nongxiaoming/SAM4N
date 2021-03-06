#include "drv_key.h"
/************************************************************************************
*文件名  ：drv_key.c															                                    *
*文件作用：按键查询驱动																                                *
*作者    ：农晓明																	                                  *
*作者QQ  ：382421307																                                  *
*文件创建时间：2013/10/11															                              *	
*************************************************************************************/

/************************************************************************************************************
*函数名： Key_GPIO_Config()
*参 数 ：void
*返回值：void
*功 能 ：按键GPIO的初始化函数，使用按键前必须先调用此函数进行初始化
************************************************************************************************************/
void Key_GPIO_Config(void)
{
		/*禁止外设管理控制寄存器(PMC)写保护*/
  PMC->PMC_WPMR = 0x504D4300; 
    /*使能PIOA时钟*/	
  PMC->PMC_PCER0 = (1UL << ID_PIOA);  
	/*使能外设管理控制寄存器(PMC)写保护*/
  PMC->PMC_WPMR = 0x504D4301;  
  /*使能USER_BUTTON管脚,对应为PA30*/
 PIOA->PIO_PER=(USER_BUTTON);
	/*禁止USER_BUTTON管脚*/
 PIOA->PIO_ODR=(USER_BUTTON);
	/*使能USER_BUTTON管脚的上拉电阻，设置为上拉*/
	PIOA->PIO_PUER=(USER_BUTTON);
}

/************************************************************************************************************
*函数名： Key_Scan()
*参数  ：void
*返回值：uint8_t  返回0为按下，1为没按下
*功能：按键GPIO的初始化函数，使用按键前必须先调用此函数进行初始化
************************************************************************************************************/
uint8_t  Key_Scan(void)
{

	if(0==(PIOA->PIO_PDSR&USER_BUTTON))	                  //判断按键是否被按下
	{																				
		delay_ms(10);															         //如果是，延时进行按键软件消抖
		if(0==(PIOA->PIO_PDSR&USER_BUTTON))					         //再次判断是否是按下 
		{
		 while(0==(PIOA->PIO_PDSR&USER_BUTTON));             //如果是，等待按键松开
		 return 0;
		}																			
		
	return 1;
  }
}