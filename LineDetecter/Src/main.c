 /* File name: Assignment04.IoT303x
 *
 * Description:
 *
 *
 * Last Changed By:  $Author: $Pham Nhat Tan
 * Revision:         $Revision: $
 * Last Changed:     $Date: $Nov 20, 2023
 *
 * Code sample:
 ******************************************************************************/
/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "stdio.h"
#include "stm32f401re_gpio.h"
#include "stm32f401re_rcc.h"
#include "stm32f401re_tim.h"
#include "timer.h"
#include "stm32f401re_adc.h"
#include "lightsensor.h"
#include "stdint.h"
/******************************************************************************/
/*                     PRIVATE TYPES and DEFINITIONS                         */
/******************************************************************************/
#define GPIO_PIN_SET 					1
#define GPIO_PIN_RESET 					0

#define LEDGREEN1_GPIO_PORT 			GPIOA
#define LEDGREEN1_GPIO_PIN				GPIO_Pin_0

#define LEDGREEN2_GPIO_PORT 			GPIOA
#define LEDGREEN2_GPIO_PIN				GPIO_Pin_11

#define LED_GPIO_RCC					RCC_AHB1Periph_GPIOA

#define TIM_RCC							RCC_APB2Periph_TIM1
#define TIM_INSTANCE					TIM1

#define TIM_PRESCALE 					0
#define TIM_PERIOD						8399

#define ADC_GPIO_PORT					GPIOC
#define ADC_GPIO_PIN					GPIO_Pin_5
#define ADC_CHANNEL						ADC_Channel_15
#define ADC_RCC							RCC_APB2Periph_ADC1
#define ADC_INSTANCE					ADC1

#define SYSCFG_GPIO_RCC					RCC_APB2Periph_SYSCFG

uint16_t 	ADC_Val[5];
uint16_t  	Kalman_light;

/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/
uint32_t Calculate_time(uint32_t TimeInit, uint32_t TimeCurrent){
	uint32_t TimeTotal;
	if (TimeInit >= TimeCurrent){
		TimeTotal = TimeCurrent - TimeInit;
	}else {
		TimeTotal = 0xFFFFFFFFU + TimeCurrent - TimeInit;
	}
	return TimeTotal;
}

void Delay(uint32_t ms){
	uint32_t buff = GetMilSecTick();
	while (Calculate_time(buff, GetMilSecTick()) <= ms);
}

/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/

/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/
void TimPWM_Init(void);
static void Led_ControlPWM(uint8_t dutyCycle);
uint16_t ADC_GetValue(uint16_t ADC_Channel);
void ADC1_LightInit(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t ADC_Channel);

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/
uint16_t Time_now = 0;
int main(void)
{
	SystemCoreClockUpdate();
	TimerInit();
	TimPWM_Init();
//	ADC1_LightInit(GPIOC, GPIO_Pin_5, ADC_Channel_15);
	ADC1_LightInit(GPIOA, GPIO_Pin_6, ADC_Channel_6);
	ADC1_LightInit(GPIOA, GPIO_Pin_7, ADC_Channel_7);
	ADC1_LightInit(GPIOA, GPIO_Pin_5, ADC_Channel_5);
	ADC1_LightInit(GPIOB, GPIO_Pin_0, ADC_Channel_8);
	ADC1_LightInit(GPIOC, GPIO_Pin_1, ADC_Channel_11);
	while (1){
		if (Calculate_time(Time_now, GetMilSecTick()) >100){
		ADC_Val[0] = 	ADC_GetValue(ADC_Channel_6);
		ADC_Val[1] = 	ADC_GetValue(ADC_Channel_7);
		ADC_Val[2] = 	ADC_GetValue(ADC_Channel_5);
		ADC_Val[3] = 	ADC_GetValue(ADC_Channel_8);
		ADC_Val[4] = 	ADC_GetValue(ADC_Channel_11);
		Led_ControlPWM(ADC_Val[1]*100/4095);
		Time_now = GetMilSecTick();
		}
   }
}
/******************************************************************************/
void TimPWM_Init(void){
	//Init typedef
	TIM_TimeBaseInitTypeDef TIM_Initstructe;
	GPIO_InitTypeDef		GPIO_Initstructe;
	TIM_OCInitTypeDef		Tim_OCInittructure;

	//Cau hinh chan GPIO
	RCC_AHB1PeriphClockCmd(LED_GPIO_RCC, ENABLE);

	GPIO_Initstructe.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Initstructe.GPIO_OType = GPIO_OType_PP;
	GPIO_Initstructe.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Initstructe.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_TIM1);

	GPIO_Initstructe.GPIO_Pin = GPIO_Pin_11;
	GPIO_Init(GPIOA, &GPIO_Initstructe);

	//Cau hinh Timer basic
	RCC_APB2PeriphClockCmd(TIM_RCC, ENABLE);

	TIM_Initstructe.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_Initstructe.TIM_ClockDivision = 0;
	TIM_Initstructe.TIM_RepetitionCounter = 0;
	TIM_Initstructe.TIM_Prescaler = TIM_PRESCALE;
	TIM_Initstructe.TIM_Period = TIM_PERIOD;

	TIM_TimeBaseInit(TIM_INSTANCE, &TIM_Initstructe);

	//Cau hinh PWM
	Tim_OCInittructure.TIM_OCMode = TIM_OCMode_PWM1;
	Tim_OCInittructure.TIM_OutputState = TIM_OutputState_Enable;
	Tim_OCInittructure.TIM_Pulse = 0;
	Tim_OCInittructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC4Init(TIM_INSTANCE, &Tim_OCInittructure);

	TIM_Cmd(TIM_INSTANCE, ENABLE);

	TIM_CtrlPWMOutputs(TIM_INSTANCE, ENABLE);
}

void ADC1_LightInit(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t ADC_Channel){
	ADC_InitTypeDef 		ADC_Initstructure;
	ADC_CommonInitTypeDef	ADC_CommonInitstructure;
	GPIO_InitTypeDef		GPIO_Initstructure;

	//Cap xung clock
	RCC_APB2PeriphClockCmd(ADC_RCC, ENABLE);
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
			break;
		case (uint32_t)GPIOB:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
			break;
		case (uint32_t)GPIOC:
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
			break;
		default:
			break;
	}


	//Khoi tao chan GPIO
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin;
	GPIO_Initstructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOx, &GPIO_Initstructure);

	ADC_DeInit();

	//Khoi tao ADC common
	ADC_CommonInitstructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitstructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitstructure.ADC_Prescaler = ADC_Prescaler_Div2;
	ADC_CommonInitstructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;

	ADC_CommonInit(&ADC_CommonInitstructure);

	//Khoi tao ADC1
	ADC_Initstructure.ADC_ContinuousConvMode = ENABLE;
	ADC_Initstructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_Initstructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
	ADC_Initstructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_Initstructure.ADC_NbrOfConversion = 1;
	ADC_Initstructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_Initstructure.ADC_ScanConvMode = DISABLE;

	ADC_Init(ADC1, &ADC_Initstructure);

	//Polling
	ADC_EOCOnEachRegularChannelCmd(ADC1, ENABLE);
	ADC_ContinuousModeCmd(ADC1, DISABLE);
	ADC_DiscModeChannelCountConfig(ADC1, 1);
	ADC_DiscModeCmd(ADC1, ENABLE);

	ADC_RegularChannelConfig(ADC1, ADC_Channel, 1, ADC_SampleTime_15Cycles);

	ADC_Cmd(ADC1, ENABLE);
}

uint16_t ADC_GetValue(uint16_t ADC_Channel){
	uint16_t ADC_Value = 0;

	ADC_RegularChannelConfig(ADC1, ADC_Channel, 1, ADC_SampleTime_15Cycles);

	ADC_Cmd(ADC1, ENABLE);

	ADC_SoftwareStartConv(ADC1);

	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);

	ADC_Value = ADC_GetConversionValue(ADC1);


	return ADC_Value;
}

static void Led_ControlPWM(uint8_t dutyCycle){
	static uint32_t pulse_length = 0;
	if (dutyCycle >= 100) return;
	pulse_length = ((TIM_PERIOD *dutyCycle)/100);

	TIM_SetCompare4(TIM_INSTANCE, pulse_length);
}
