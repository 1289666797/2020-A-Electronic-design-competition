/*******************************************************************************
* ��  ��	: GGTEAM
* ��  ��	: V1.0
* ��  ��	: 2020-09-03
* ��  ��	:
*******************************************************************************/
#include "led.h"
//LED IO��ʼ��
void LED_Init(void)
{

    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PB�˿�ʱ��

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;		 //IO���ٶ�Ϊ2MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    DS3 = 1;

}
