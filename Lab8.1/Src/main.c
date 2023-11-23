 /* File name: Lab 8.1
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

#define SYSCFG_GPIO_RCC					RCC_APB2Periph_SYSCFG

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/
void 				TimPWM_Init(void);
void 				Delay(uint32_t ms);
void 				AppInitCommon();
static void 		Led_ControlPWM(uint8_t dutyCycle);
uint32_t 			Calculate_time(uint32_t TimeInit, uint32_t TimeCurrent);

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/
int main(void)
{
	AppInitCommon();

	while (1){
		for (int i = 0; i< 100 ; i++){
			Led_ControlPWM(i);
			Delay(100);
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
void AppInitCommon(){
	//Init the System
	SystemCoreClockUpdate();

	//Init the Timer in PWM mode
	TimPWM_Init();

	//Init the Timer Basic
	TimerInit();

	//Init the System
	SystemInit();
}

/**
 * @func   TimPWM_Init
 * @brief  Initialize the Timer in PWM mode
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
 * @func   Led_ControlPWM
 * @brief  Control the Amplititude light of Led using PWM
 * @param  dutyCycle
 * @retval None
 */
static void Led_ControlPWM(uint8_t dutyCycle){
	static uint32_t pulse_length = 0;
	if (dutyCycle >= 100) return;
	pulse_length = ((TIM_PERIOD *dutyCycle)/100);

	TIM_SetCompare4(TIM_INSTANCE, pulse_length);
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
