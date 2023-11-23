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


/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/
void 				Appinit_Common();
void 				TimPWM_Init(void);
void 				ADC_LightInit();
void 				Delay(uint32_t ms);
static void 		Led_ControlPWM(uint8_t dutyCycle);
uint16_t 			ADC_GetValue(void);
uint32_t 			Calculate_time(uint32_t TimeInit, uint32_t TimeCurrent);

uint16_t 			getAdcVal;
uint16_t 			timeNow = 0;
/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/
int main(void)
{
	//Khoi tao cac thong so ban dau.
	Appinit_Common();

	while (1){
		if (Calculate_time(timeNow, GetMilSecTick()) >100){
		getAdcVal =  ADC_GetValue();
		Led_ControlPWM(getAdcVal*100/4095);
		timeNow = GetMilSecTick();
		}
   }
}

/******************************************************************************/
/**
 * @func   AppInitCommon
 * @brief  Initialize common application
 * @param  None
 * @retval None
 */
void Appinit_Common(){
	//Khoi tao ADC
	ADC_LightInit();

	//Khoi tao PWM
	TimPWM_Init();

	//Khoi tao system clock
	SystemCoreClockUpdate();

	//Khoi tao Timer
	TimerInit();

	//Khoi tao system
	SystemInit();
}

/**
 * @func   CalculateTime
 * @brief  Calculate the time betwen 2 time.
 * @param  Time now, Time Miles
 * @retval Timenow - Time Miles
 */
uint32_t Calculate_time(uint32_t TimeInit, uint32_t TimeCurrent){
	uint32_t TimeTotal;
	if (TimeInit >= TimeCurrent){
		TimeTotal = TimeCurrent - TimeInit;
	}else {
		TimeTotal = 0xFFFFFFFFU + TimeCurrent - TimeInit;
	}
	return TimeTotal;
}

/**
 * @func   Delay
 * @brief  Delay the time
 * @param  Time delay
 * @retval None
 */
void Delay(uint32_t ms){
	uint32_t buff = GetMilSecTick();
	while (Calculate_time(buff, GetMilSecTick()) <= ms);
}

/**
 * @func   TimPWMInit
 * @brief  Initzation the PWM.
 * @param  None
 * @retval None
 */
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

/**
 * @func   ADC Light Init
 * @brief  Initzation the ADC read from GPIO
 * @param  None
 * @retval None
 */
void ADC_LightInit(){
	ADC_InitTypeDef 		ADC_Initstructure;
	ADC_CommonInitTypeDef	ADC_CommonInitstructure;
	GPIO_InitTypeDef		GPIO_Initstructure;

	//Cap xung clock
	RCC_APB2PeriphClockCmd(ADC_RCC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	//Khoi tao chan GPIO
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_Initstructure.GPIO_Pin = ADC_GPIO_PIN;
	GPIO_Initstructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOC, &GPIO_Initstructure);

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

	ADC_Init(ADC_INSTANCE, &ADC_Initstructure);

	//Polling
	ADC_EOCOnEachRegularChannelCmd(ADC_INSTANCE, ENABLE);
	ADC_ContinuousModeCmd(ADC_INSTANCE, DISABLE);
	ADC_DiscModeChannelCountConfig(ADC_INSTANCE, 1);
	ADC_DiscModeCmd(ADC_INSTANCE, ENABLE);

	ADC_RegularChannelConfig(ADC_INSTANCE, ADC_CHANNEL, 1, ADC_SampleTime_15Cycles);

	ADC_Cmd(ADC_INSTANCE, ENABLE);
}

/**
 * @func   ADC Get Value
 * @brief  Get the Value of the ADC
 * @param  None
 * @retval ADC read
 */
uint16_t ADC_GetValue(void){
	uint16_t getAdcValue = 0;

	ADC_SoftwareStartConv(ADC_INSTANCE);

	while (ADC_GetFlagStatus(ADC_INSTANCE, ADC_FLAG_EOC) == RESET);

	getAdcValue = ADC_GetConversionValue(ADC_INSTANCE);


	return getAdcValue;
}

/**
 * @func   Led Control PWM
 * @brief  Control the Amplitude light of Led
 * @param  dutyCycle
 * @retval None
 */
static void Led_ControlPWM(uint8_t dutyCycle){
	static uint32_t pulse_length = 0;
	if (dutyCycle >= 100) return;
	pulse_length = ((TIM_PERIOD *dutyCycle)/100);

	TIM_SetCompare4(TIM_INSTANCE, pulse_length);
}
