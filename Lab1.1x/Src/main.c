/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

//---------------------Include-----------------
#include <stdint.h>
#include "timer.h"
#include "Ucglib.h"
#include "stm32f401re_gpio.h"
#include "stm32f401re_rcc.h"


//--------------------Macro------------------
#define GPIO_PIN_SET 			1
#define GPIO_PIN_RESET 			0

#define BUZZER_GPIO_PORT 		GPIOA
#define BUZZER_GPIO_PIN			GPIO_Pin_0
#define BUZZER_GPIO_RCC			RCC_AHB1Periph_GPIOA

#define BUTTON_GPIO_PORT 		GPIOB
#define BUTTON_GPIO_PIN			GPIO_Pin_4
#define BUTTON_GPIO_RCC			RCC_AHB1Periph_GPIOB


//-----------------Nguyen mau ham---------------
void 					AppInitCommon();
static void 			Buzzer_Init(void);
static void 			Button_Init(void);
static void 			Buzzer_control(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t status);
static uint8_t 			Button_GetLogic(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

//----------------------------------------------
int main(void)
{
	//Init the parameter
	AppInitCommon();

	while (1){
	uint8_t sta = Button_GetLogic(BUTTON_GPIO_PORT, BUTTON_GPIO_PIN);
	Buzzer_control(BUZZER_GPIO_PORT, BUZZER_GPIO_PIN, sta);
	}
}

//---------------------------------------------------
/**
 * @func   AppInitCommon
 * @brief  Initialize common application
 * @param  None
 * @retval None
 */
void AppInitCommon(){

	//Initzation the Buzzer
	Buzzer_Init();

	//initzation the Button
	Button_Init();
}

/**
 * @func   Buzzer_Init
 * @brief  Initialize the buzzer
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
 * @func   Button_Init
 * @brief  Initialize button
 * @param  None
 * @retval None
 */
static void Button_Init(void){
	//Khai bao kieu du lieu
	GPIO_InitTypeDef GPIO_Initstruct2;

	//Bat block cho GPIOA
	RCC_AHB1PeriphClockCmd(BUTTON_GPIO_RCC, ENABLE);

	//Khai bao pin cua led
	GPIO_Initstruct2.GPIO_Pin = BUTTON_GPIO_PIN;

	//Khai bao GPIO input
	GPIO_Initstruct2.GPIO_Mode = GPIO_Mode_IN;

	//Cau hinh toc do
	GPIO_Initstruct2.GPIO_Speed = GPIO_Speed_50MHz;

	//Chon kieu pull up
	GPIO_Initstruct2.GPIO_PuPd = GPIO_PuPd_UP;

	//Cau hinh chan cho GPIO
	GPIO_Init(BUTTON_GPIO_PORT, &GPIO_Initstruct2);
}

/**
 * @func   Buzzer_control
 * @brief  Control the Buzzer
 * @param  None
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
 * @func   Button_GetLogic
 * @brief  Get logic of the Button.
 * @param  Port, Pin
 * @retval Status of Button.(0 or 1)
 */
static uint8_t Button_GetLogic(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	return GPIO_ReadInputDataBit(GPIOx, GPIO_Pin);
}
