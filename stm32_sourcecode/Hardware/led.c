/*******************************************************************************
* 作  者	: GGTEAM
* 版  本	: V1.0
* 日  期	: 2020-09-03
* 描  述	:
*******************************************************************************/
#include "led.h"
//LED IO初始化
void LED_Init(void)
{

    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB端口时钟

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;		 //IO口速度为2MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    DS3 = 1;

}

