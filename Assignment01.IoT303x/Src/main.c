 /* File name: Assignment01.IoT303x
 *
 * Description:
 *
 *
 * Last Changed By:  $Author: Pham Nhat Tan
 * Revision:         $Revision:
 * Last Changed:     $Date: $Nov 15, 2023
 *
 ******************************************************************************/
/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include <stdint.h>
#include "stm32f401re_gpio.h"
#include "stm32f401re_rcc.h"
#include "misc.h"
#include "stm32f401re_exti.h"
#include "stm32f401re_syscfg.h"
#include "timer.h"
#include "led.h"

/******************************************************************************/
/*                     PRIVATE TYPES and DEFINITIONS                         */
/******************************************************************************/
#define GPIO_PIN_SET 					1
#define GPIO_PIN_RESET 					0

#define LEDGREEN1_GPIO_PORT 			GPIOA
#define LEDGREEN1_GPIO_PIN				GPIO_Pin_0

#define LEDGREEN2_GPIO_PORT 			GPIOA
#define LEDGREEN2_GPIO_PIN				GPIO_Pin_11

#define LEDRED1_GPIO_PORT 				GPIOA
#define LEDRED1_GPIO_PIN				GPIO_Pin_1

#define LEDRED2_GPIO_PORT 				GPIOB
#define LEDRED2_GPIO_PIN				GPIO_Pin_13

#define LEDBLUE1_GPIO_PORT 				GPIOA
#define LEDBLUE1_GPIO_PIN				GPIO_Pin_3

#define LEDBLUE2_GPIO_PORT 				GPIOA
#define LEDBLUE2_GPIO_PIN				GPIO_Pin_10

#define LED_GPIOA_RCC					RCC_AHB1Periph_GPIOA
#define LED_GPIOB_RCC					RCC_AHB1Periph_GPIOB

#define BUZZER_GPIO_PORT 				GPIOC
#define BUZZER_GPIO_PIN					GPIO_Pin_9
#define BUZZER_GPIO_RCC					RCC_AHB1Periph_GPIOC

#define BUTTON2_IT_GPIO_PORT 			GPIOB
#define BUTTON2_IT_GPIO_PIN				GPIO_Pin_3

#define BUTTON3_IT_GPIO_PORT 			GPIOA
#define BUTTON3_IT_GPIO_PIN				GPIO_Pin_4

#define BUTTON4_IT_GPIO_PORT 			GPIOB
#define BUTTON4_IT_GPIO_PIN				GPIO_Pin_0

#define BUTTON_IT_GPIO_RCCB				RCC_AHB1Periph_GPIOB
#define BUTTON_IT_GPIO_RCCA				RCC_AHB1Periph_GPIOA

#define SYSCFG_GPIO_RCC					RCC_APB2Periph_SYSCFG

/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/
volatile 	uint8_t 	statusOfButton2 = 0;
volatile 	uint8_t 	statusOfButton3 = 0;
volatile 	uint8_t 	statusOfButton4 = 0;
static __IO uint32_t 	timeDelay;
uint8_t					countB3			= 0;
uint8_t					countB2			= 0;
uint8_t					countB4			= 0;
uint16_t 				timePressB3		   ;
uint8_t					staB3			= 0;
uint16_t 				timeStartPressB2   ;
uint16_t				timeStartpressB4   ;
uint8_t					statusTerminalB2	= 0		   ;
uint8_t					statusTerminalB4  = 0		   ;
/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/
static void 		Button_IT_Init();
static void 		Led_Init();
static void 		Buzzer_Init(void);
static void 		Buzzer_control(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t status);
static uint8_t		Button_GetLogic(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void 				EXTI0_IRQHandler(void);
void 				EXTI4_IRQHandler(void);
void 				EXTI3_IRQHandler(void);
void 				Blue_control(uint8_t status);
void 				Green_control(uint8_t status);
void 				Red_control(uint8_t status);
void 				Led_control(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t status);
void 				Delay(uint32_t ms);
void 				LedGreen_blink(uint8_t NumBlink);
void 				Buzzer_blink(uint8_t BuzzerBlink);
uint32_t 			Calculate_time(uint32_t TimeInit, uint32_t TimeCurrent);

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

int main(void)
{
	//--------------Init cac gia tri-------------


	//-------------Khoi dong---------------------
	LedGreen_blink(4);
    /* Loop forever */
	while (1){
		statusOfButton2 = !Button_GetLogic(BUTTON2_IT_GPIO_PORT, BUTTON2_IT_GPIO_PIN);
		statusOfButton4 = !Button_GetLogic(BUTTON4_IT_GPIO_PORT, BUTTON4_IT_GPIO_PIN);
		if (staB3 == 1){
			LedGreen_blink(5);
			Buzzer_blink(2);
			staB3 = 0;
		}
		if ((statusOfButton4 == 1) && (Calculate_time(timeStartpressB4, GetMilSecTick())>500)){
			Red_control(1);
			statusTerminalB4 = 1;
		}
		if ((statusTerminalB4 == 1) && (statusOfButton4 == 0)){
			Red_control(0);
			statusTerminalB4 = 0;
		}
		if (statusOfButton3 == 1) {
		Green_control(1);
		statusOfButton3 = 0;
		}
		if ((statusOfButton2 == 1) && (Calculate_time(timeStartPressB2, GetMilSecTick())>500)) {

			Blue_control(1);
			statusTerminalB2 = 1;
		}

		if ((statusTerminalB2 == 1) && (statusOfButton2 == 0)){
			Blue_control(0);
			statusTerminalB2 = 0;
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
	//Khoi tao Led
	Led_Init();

	//Khoi tao Button
	Button_IT_Init();

	//Khoi tao coi
	Buzzer_Init();

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
//Tinh toan thoi gian
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
//Khoi tao ham Delay
void Delay(uint32_t ms){
	uint32_t buff = GetMilSecTick();
	while (Calculate_time(buff, GetMilSecTick()) <= ms);
}

/**
 * @func   LedInit
 * @brief  Initialize the parameter of the Led
 * @param  None
 * @retval None
 */
//Khoi tao ham led
static void Led_Init(void){
	//Khai bao kieu du lieu
	GPIO_InitTypeDef GPIO_Initstruct;

	//Bat block cho GPIOA va GPIOB
	RCC_AHB1PeriphClockCmd(LED_GPIOA_RCC, ENABLE);
	RCC_AHB1PeriphClockCmd(LED_GPIOB_RCC, ENABLE);

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

	//Khoi tao cac gia tri ban dau cho RED1
	GPIO_Initstruct.GPIO_Pin = LEDRED1_GPIO_PIN;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(LEDRED1_GPIO_PORT, &GPIO_Initstruct);

	//Khoi tao cac gia tri ban dau cho RED2
	GPIO_Initstruct.GPIO_Pin = LEDRED2_GPIO_PIN;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(LEDRED2_GPIO_PORT, &GPIO_Initstruct);

	//Khoi tao cac gia tri ban dau cho BLUE1
	GPIO_Initstruct.GPIO_Pin = LEDBLUE1_GPIO_PIN;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(LEDBLUE1_GPIO_PORT, &GPIO_Initstruct);

	//Khoi tao cac gia tri ban dau cho BLUE2
	GPIO_Initstruct.GPIO_Pin = LEDBLUE2_GPIO_PIN;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(LEDBLUE2_GPIO_PORT, &GPIO_Initstruct);
}

/**
 * @func   ButtonItInit
 * @brief  Initialize the Button as a IT button
 * @param  None
 * @retval None
 */
static void Button_IT_Init(void){
	//Khai bao kieu du lieu
	GPIO_InitTypeDef GPIO_Initstruct2;
	EXTI_InitTypeDef EXTI_Initstruct2;
	NVIC_InitTypeDef NVIC_Initstruct2;

	//Bat Clock cho GPIOC
	RCC_AHB1PeriphClockCmd(LED_GPIOA_RCC, ENABLE);
	RCC_AHB1PeriphClockCmd(LED_GPIOB_RCC, ENABLE);

	//Khoi tao ngat cho nut nhan 2
	//Khoi tao cac gia tri ban dau cho chan GPIO
	GPIO_Initstruct2.GPIO_Pin = BUTTON2_IT_GPIO_PIN;
	GPIO_Initstruct2.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Initstruct2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct2.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(BUTTON2_IT_GPIO_PORT, &GPIO_Initstruct2);

	//Cau hinh line ngat 3
	RCC_APB2PeriphClockCmd(SYSCFG_GPIO_RCC, ENABLE);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource3);					//Cap clock cho ngoai vi SYSCFG

	//Cau hinh su dung ngat
	EXTI_Initstruct2.EXTI_Line = EXTI_Line3;
	EXTI_Initstruct2.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_Initstruct2.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Initstruct2.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_Initstruct2);

	//Cau hinh trinh phuc vu ngat NVIC
	NVIC_Initstruct2.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_Initstruct2.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_Initstruct2.NVIC_IRQChannelSubPriority = 0;
	NVIC_Initstruct2.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_Initstruct2);

	//Khoi tao ngat cho nut nhan 3
	//Khoi tao cac gia tri ban dau cho chan GPIO
	GPIO_Initstruct2.GPIO_Pin = BUTTON3_IT_GPIO_PIN;
	GPIO_Initstruct2.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Initstruct2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct2.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(BUTTON3_IT_GPIO_PORT, &GPIO_Initstruct2);

	//Cau hinh line ngat 3
	RCC_APB2PeriphClockCmd(SYSCFG_GPIO_RCC, ENABLE);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource4);					//Cap clock cho ngoai vi SYSCFG

	//Cau hinh su dung ngat
	EXTI_Initstruct2.EXTI_Line = EXTI_Line4;
	EXTI_Initstruct2.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_Initstruct2.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Initstruct2.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_Initstruct2);

	//Cau hinh trinh phuc vu ngat NVIC
	NVIC_Initstruct2.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_Initstruct2.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_Initstruct2.NVIC_IRQChannelSubPriority = 0;
	NVIC_Initstruct2.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_Initstruct2);

	//Khoi tao ngat cho nut nhan 4
	//Khoi tao cac gia tri ban dau cho chan GPIO
	GPIO_Initstruct2.GPIO_Pin = BUTTON4_IT_GPIO_PIN;
	GPIO_Initstruct2.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Initstruct2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct2.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(BUTTON4_IT_GPIO_PORT, &GPIO_Initstruct2);

	//Cau hinh line ngat 4
	RCC_APB2PeriphClockCmd(SYSCFG_GPIO_RCC, ENABLE);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource0);					//Cap clock cho ngoai vi SYSCFG

	//Cau hinh su dung ngat
	EXTI_Initstruct2.EXTI_Line = EXTI_Line0;
	EXTI_Initstruct2.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_Initstruct2.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Initstruct2.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_Initstruct2);

	//Cau hinh trinh phuc vu ngat NVIC
	NVIC_Initstruct2.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_Initstruct2.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_Initstruct2.NVIC_IRQChannelSubPriority = 0;
	NVIC_Initstruct2.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_Initstruct2);
}

/**
 * @func   BuzzerBlink
 * @brief  Blink the buzzer
 * @param  None
 * @retval None
 */
void Buzzer_blink(uint8_t BuzzerBlink){
	for (int i = 0; i < BuzzerBlink; i++){
		Buzzer_control(BUZZER_GPIO_PORT, BUZZER_GPIO_PIN, GPIO_PIN_SET);
		Delay(100);
		Buzzer_control(BUZZER_GPIO_PORT, BUZZER_GPIO_PIN, GPIO_PIN_RESET);
		Delay(100);
	}
}

/**
 * @func   BuzzerInit
 * @brief  Initialize the Button
 * @param  None
 * @retval None
 */
static void Buzzer_Init(void){
	//Khai bao kieu du lieu
	GPIO_InitTypeDef GPIO_Initstruct;

	//Bat block cho GPIOA
	RCC_AHB1PeriphClockCmd(BUZZER_GPIO_RCC, ENABLE);

	//Khai bao pin cua led
	GPIO_Initstruct.GPIO_Pin = BUZZER_GPIO_PIN;

	//Khai bao GPIO output
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_OUT;

	//Cau hinh toc do
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;

	//Chon kieu push pull
	GPIO_Initstruct.GPIO_OType = GPIO_OType_PP;

	//Cau hinh chan cho GPIO
	GPIO_Init(BUZZER_GPIO_PORT, &GPIO_Initstruct);
}

/**
 * @func   LedGreenBlink
 * @brief  Blink all Green Led
 * @param  Number of blinking
 * @retval None
 */
void LedGreen_blink(uint8_t NumBlink){
	for (int i = 0; i < NumBlink; i++){
		Green_control(1);
		Delay(100);
		Green_control(0);
		Delay(100);
	}
}

/**
 * @func   BuzzerControl
 * @brief  Control the Buzzer.(On or Off)
 * @param  Port, Pin, Status of Buzzer.
 * @retval None
 */
static void Buzzer_control(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t status){
	if (status == GPIO_PIN_SET){
		GPIO_SetBits(GPIOx, GPIO_Pin);
	}else if(status == GPIO_PIN_RESET){
		GPIO_ResetBits(GPIOx, GPIO_Pin);
	}
}

/**
 * @func   LedControl
 * @brief  Control the Led.(On or Off)
 * @param  Port, Pin, Status of Led.
 * @retval None
 */
void Led_control(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t status){
	if (status == GPIO_PIN_SET){
		GPIO_SetBits(GPIOx, GPIO_Pin);
	}else if(status == GPIO_PIN_RESET){
		GPIO_ResetBits(GPIOx, GPIO_Pin);
	}
}

/**
 * @func   RedControl
 * @brief  Control the Red Led.(On or Off)
 * @param  Status of Led.
 * @retval None
 */
void Red_control(uint8_t status){
	if (status == GPIO_PIN_SET){
		Led_control(LEDRED1_GPIO_PORT, LEDRED1_GPIO_PIN, GPIO_PIN_SET);
		Led_control(LEDRED2_GPIO_PORT, LEDRED2_GPIO_PIN, GPIO_PIN_SET);
	}else if(status == GPIO_PIN_RESET){
		Led_control(LEDRED1_GPIO_PORT, LEDRED1_GPIO_PIN, GPIO_PIN_RESET);
		Led_control(LEDRED2_GPIO_PORT, LEDRED2_GPIO_PIN, GPIO_PIN_RESET);
	}
}

/**
 * @func   GreenControl
 * @brief  Control the Green Led.(On or Off)
 * @param  Status of Led.
 * @retval None
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
 * @func   BlueControl
 * @brief  Control the Blue Led.(On or Off)
 * @param  Status of Led.
 * @retval None
 */
void Blue_control(uint8_t status){
	if (status == GPIO_PIN_SET){
		Led_control(LEDBLUE1_GPIO_PORT, LEDBLUE1_GPIO_PIN, GPIO_PIN_SET);
		Led_control(LEDBLUE2_GPIO_PORT, LEDBLUE2_GPIO_PIN, GPIO_PIN_SET);
	}else if(status == GPIO_PIN_RESET){
		Led_control(LEDBLUE1_GPIO_PORT, LEDBLUE1_GPIO_PIN, GPIO_PIN_RESET);
		Led_control(LEDBLUE2_GPIO_PORT, LEDBLUE2_GPIO_PIN, GPIO_PIN_RESET);
	}
}

/**
 * @func   ButtonGetLogic
 * @brief  Get the logic form Button.(On or Off)
 * @param  Port of Button, Pin of Button
 * @retval On or Off. (O or 1)
 */
static uint8_t Button_GetLogic(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	return GPIO_ReadInputDataBit(GPIOx, GPIO_Pin);
}

/**
 * @func   EXTI3 IT Handler
 * @brief  When get Interupt from EXTI3. This code in function will running.
 * @param  None
 * @retval None
 */
void EXTI3_IRQHandler(void){
	if (EXTI_GetFlagStatus(EXTI_Line3) == SET){
		//Button 2;
		if (countB2 == 0){
			timeStartPressB2 = GetMilSecTick();
			countB2 ++;
		}else if (countB2 == 1){
			if (Calculate_time(timeStartPressB2, GetMilSecTick()) <= 400){
				Blue_control(1);
				timeStartPressB2 = GetMilSecTick();
				countB2 ++;
			}else {
				timeStartPressB2 = GetMilSecTick();
				countB2 = 0;
			}
		}else {
			timeStartPressB2 = GetMilSecTick();
			Blue_control(0);
			countB2 = 0;
		}
	}
	EXTI_ClearFlag(EXTI_Line3);
}

/**
 * @func   EXTI4 IT Handler
 * @brief  When get Interupt from EXTI4. This code in function will running.
 * @param  None
 * @retval None
 */
void EXTI4_IRQHandler(void){
	if (EXTI_GetFlagStatus(EXTI_Line4) == SET){
		//Button 3
		if (countB3 == 0){
			countB3 ++;
			timePressB3 = GetMilSecTick();
		}else if(countB3 >= 1 && (Calculate_time(timePressB3, GetMilSecTick()) <= 400)){
			timePressB3 = GetMilSecTick();
			countB3 ++;
		}
		if (Calculate_time(timePressB3, GetMilSecTick()) > 400){
			countB3 = 0;
		}
		if (countB3 == 5){
			staB3 = 1;
			countB3 = 0;
		}
	}
	EXTI_ClearFlag(EXTI_Line4);
}

/**
 * @func   EXTI0 IT Handler
 * @brief  When get Interupt from EXTI0. This code in function will running.
 * @param  None
 * @retval None
 */
void EXTI0_IRQHandler(void){
	if (EXTI_GetFlagStatus(EXTI_Line0) == SET){
		//Button 4
		if (countB4 == 0){
			timeStartpressB4 = GetMilSecTick();
			countB4 ++;
		}else if (countB4 == 1){
			if (Calculate_time(timeStartpressB4, GetMilSecTick()) <= 400){
				Red_control(1);
				timeStartpressB4 = GetMilSecTick();
				countB4 ++;
			}else {
				timeStartpressB4 = GetMilSecTick();
				countB4 = 0;
			}
		}else {
			timeStartpressB4 = GetMilSecTick();
			Red_control(0);
			countB4 = 0;
		}
	}
	EXTI_ClearFlag(EXTI_Line0);
}
