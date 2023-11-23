 /* File name: Lab 7.1
 *
 * Description:
 *
 *
 * Last Changed By:  $Author: $Pham Nhat Tan
 * Revision:         $Revision: $
 * Last Changed:     $Date: $Nov 19, 2023
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
/******************************************************************************/
/*                     PRIVATE TYPES and DEFINITIONS                         */
/******************************************************************************/
#define GPIO_PIN_SET 				1
#define GPIO_PIN_RESET 				0

#define LEDGREEN1_GPIO_PORT 			GPIOA
#define LEDGREEN1_GPIO_PIN				GPIO_Pin_0

#define LEDGREEN2_GPIO_PORT 			GPIOA
#define LEDGREEN2_GPIO_PIN				GPIO_Pin_11

#define LED_GPIO_RCC					RCC_AHB1Periph_GPIOA

#define TIM_RCC							RCC_APB2Periph_TIM1
#define TIM_INSTANCE					TIM1

#define TIM_PRESCALE 					83
#define TIM_PERIOD						999

#define SYSCFG_GPIO_RCC					RCC_APB2Periph_SYSCFG

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/
void 									Tim_Init();
void 									TimBasic_Init(void);
void 									Led_control(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t status);
void 									Green_control(uint8_t status);
void 									LedGreen_blink(uint8_t NumBlink);
void 									Delay(uint32_t ms);
void 									AppInitCommon(void);
static void 							Led_Init(void);

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/
int main(void)
{
	AppInitCommon();

	while (1){
		Green_control(1);
		Delay(2000);
		Green_control(0);
		Delay(2000);
   }
}
/******************************************************************************/
/**
 * @func   AppInitCommon
 * @brief  Initialize common application
 * @param  None
 * @retval None
 */
void AppInitCommon(void){
	//Init the Led
	Led_Init();

	//Init the Timer
	TimBasic_Init();

	//Init the System
	SystemCoreClockUpdate();
}

/**
 * @func   TimBasic_Init
 * @brief  Initialize the Timer Basic
 * @param  None
 * @retval None
 */
void TimBasic_Init(void){
	//Init typedef
	TIM_TimeBaseInitTypeDef TIM_Initstructe;

	RCC_APB2PeriphClockCmd(TIM_RCC, ENABLE);

	TIM_Initstructe.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_Initstructe.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_Initstructe.TIM_RepetitionCounter = 0;
	TIM_Initstructe.TIM_Prescaler = TIM_PRESCALE;
	TIM_Initstructe.TIM_Period = TIM_PERIOD;

	TIM_TimeBaseInit(TIM_INSTANCE, &TIM_Initstructe);
	TIM_Cmd(TIM_INSTANCE, ENABLE);

}
/**
 * @func   Delay
 * @brief  Delay the time using Timer.
 * @param  Time delay
 * @retval None
 */
void Delay(uint32_t ms){
	while (ms != 0){
		TIM_SetCounter(TIM_INSTANCE, 0);
		while (TIM_GetCounter(TIM_INSTANCE) != TIM_PERIOD);
		ms --;
	}
}

/**
 * @func   Led_Init
 * @brief  Initialize the Led
 * @param  None
 * @retval None
 */
static void Led_Init(void){
	//Khai bao kieu du lieu
	GPIO_InitTypeDef GPIO_Initstruct;

	//Bat block cho GPIOA va GPIOB
	RCC_AHB1PeriphClockCmd(LED_GPIO_RCC, ENABLE);

	//Khoi tao cac gia tri ban dau cho GREEN1
	GPIO_Initstruct.GPIO_Pin = LEDGREEN1_GPIO_PIN;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(LEDGREEN1_GPIO_PORT, &GPIO_Initstruct);

	//Khoi tao cac gia tri ban dau cho GREEN2
	GPIO_Initstruct.GPIO_Pin = LEDGREEN2_GPIO_PIN;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(LEDGREEN2_GPIO_PORT, &GPIO_Initstruct);

}

/**
 * @func   Led_control
 * @brief  Control the Led
 * @param  GPIOx, GPIO_Pin, status
 * @retval None.
 */
void Led_control(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t status){
	if (status == GPIO_PIN_SET){
		GPIO_SetBits(GPIOx, GPIO_Pin);
	}else if(status == GPIO_PIN_RESET){
		GPIO_ResetBits(GPIOx, GPIO_Pin);
	}
}

/**
 * @func   Green_control
 * @brief  Control the Led Green
 * @param  status
 * @retval None.
 */
void Green_control(uint8_t status){
	if (status == GPIO_PIN_SET){
		Led_control(LEDGREEN1_GPIO_PORT, LEDGREEN1_GPIO_PIN, GPIO_PIN_SET);
		Led_control(LEDGREEN2_GPIO_PORT, LEDGREEN2_GPIO_PIN, GPIO_PIN_SET);
	}else if(status == GPIO_PIN_RESET){
		Led_control(LEDGREEN1_GPIO_PORT, LEDGREEN1_GPIO_PIN, GPIO_PIN_RESET);
		Led_control(LEDGREEN2_GPIO_PORT, LEDGREEN2_GPIO_PIN, GPIO_PIN_RESET);
	}
}

/**
 * @func   LedGreen_blink
 * @brief  Blink the Green Led
 * @param  Number of Blinking
 * @retval None.
 */
void LedGreen_blink(uint8_t NumBlink){
	for (int i = 0; i < NumBlink; i++){
		Green_control(1);
		Delay(100);
		Green_control(0);
		Delay(100);
	}
}
