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
//------------------------Inc--------------------------------------------------
#include <stdint.h>
#include "stm32f401re_rcc.h"
#include "stm32f401re_gpio.h"
#include "stm32f401re_i2c.h"
#include "misc.h"
#include "led.h"
#include "timer.h"

//------------------------Def--------------------------------------------------
#define GPIO_PIN_SET 					1
#define GPIO_PIN_RESET					0

#define LEDGREEN1_GPIO_PORT 			GPIOA
#define LEDGREEN1_GPIO_PIN				GPIO_Pin_0

#define LEDGREEN2_GPIO_PORT 			GPIOA
#define LEDGREEN2_GPIO_PIN				GPIO_Pin_11

#define LED_GPIO_RCC					RCC_AHB1Periph_GPIOA

#define BUTTON_GPIO_PORT 				GPIOB
#define BUTTON_GPIO_PIN					GPIO_Pin_3

#define BUTTON_GPIO_RCC					RCC_AHB1Periph_GPIOB

#define I2C_SPEED						400000 //400KB/s

#define I2C_MASTER_RCC					RCC_APB1Periph_I2C3
#define I2C_MASTER_INSTANCE				I2C3

#define I2C_MASTER_GPIO_RCC				RCC_AHB1Periph_GPIOA
#define I2C_MASTER_PORT					GPIOA
#define SDA_MASTER_PIN					GPIO_Pin_9
#define SCL_MASTER_PIN					GPIO_Pin_8

#define I2C_SLAVE_RCC					RCC_APB1Periph_I2C1
#define I2C_SLAVE_INSTANCE				I2C1

#define I2C_SLAVE_GPIO_RCC				RCC_AHB1Periph_GPIOB
#define I2C_SLAVE_PORT					GPIOB
#define SDA_SLAVE_PIN					GPIO_Pin_9
#define SCL_SLAVE_PIN					GPIO_Pin_8

#define SERIAL_ADR						0x02
#define DATA_RCV_VALID					0x10
#define DATA_RCV_IDLE					0x00

//--------------------Nguyen mau ham------------------------------
void 					I2C3_Init(void);
void 					I2C1_Init(void);
void 					I2C1_EV_IRQHandler(void);
void 					I2C_Start(void);
void 					I2C_SendAddress(uint8_t address);
void 					I2C_TransmitData(uint8_t data);
void 					I2C_Stop(void);
void 					Led_control(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t status);
void 					Green_control(uint8_t status);
void 					Delay(uint32_t ms);
void 					AppInitCommon(void);
static void 			Led_Init(void);
static void 			Button_Init(void);
static uint8_t 			Button_GetLogic(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
static uint32_t 		Calculate_time(uint32_t TimeInit, uint32_t TimeCurrent);

static uint16_t 		reciveData = DATA_RCV_IDLE;

//------------------------------------------------------------------
int main(void)
{
	AppInitCommon();

	while (1){
		if (Button_GetLogic(BUTTON_GPIO_PORT, BUTTON_GPIO_PIN) == Bit_RESET){
			I2C_Start();
			I2C_SendAddress(SERIAL_ADR);
			I2C_TransmitData(DATA_RCV_VALID);
			I2C_Stop();
		}
		if (reciveData == DATA_RCV_VALID)
		{
			for (int i = 0; i<5; i++){
				Green_control(1);
				Delay(1000);
				Green_control(0);
				Delay(1000);
			}
			reciveData = DATA_RCV_IDLE;
		}
	}
}


//----------------------Cac ham-----------------------------------
/**
 * @func   AppInitCommon
 * @brief  Initialize common application
 * @param  None
 * @retval None
 */
void AppInitCommon(void){

	//Init the I2C1
	I2C1_Init();

	//Init the I2C3
	I2C3_Init();

	//Init the led
	Led_Init();

	//Init the button
	Button_Init();

	//Init the timer
	TimerInit();

	//Init the system
	SystemCoreClockUpdate();
	SystemInit();
}

/**
 * @func   I2C3_Init
 * @brief  Initialize the I2C3
 * @param  None
 * @retval None
 */
void I2C3_Init(void){
	GPIO_InitTypeDef	GPIO_InitStructure;
	I2C_InitTypeDef		I2C_InitStructure;

	//Khoi tao GPIO
	//Cap clock cho AHB1
	RCC_APB1PeriphClockCmd(I2C_MASTER_RCC, ENABLE);
	RCC_AHB1PeriphClockCmd(I2C_MASTER_GPIO_RCC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	//Khoi tao cac tham so ban dau
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;


	GPIO_InitStructure.GPIO_Pin = SCL_MASTER_PIN;
	GPIO_Init(I2C_MASTER_PORT, &GPIO_InitStructure);

	GPIO_Init(I2C_MASTER_PORT, &GPIO_InitStructure);

	//Chon PA8 lam chan SCL
	GPIO_PinAFConfig(I2C_MASTER_PORT, GPIO_PinSource8, GPIO_AF_I2C3);
	//Chon PB9 lam chan SDA
	GPIO_PinAFConfig(I2C_MASTER_PORT, GPIO_PinSource9, GPIO_AF_I2C3);

	//Khoi tao ngoai vi I2C3 su dung che do Master
	//Khoi tao cac tham so ban dau
	//Khoi tao mode master
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_ClockSpeed = I2C_SPEED;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1 = 0x00;
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

	//Khoi tao I2C
	I2C_Init(I2C_MASTER_INSTANCE, &I2C_InitStructure);

	//Bat I2C
	I2C_Cmd(I2C_MASTER_INSTANCE, ENABLE);
}

/**
 * @func   I2C1_Init
 * @brief  Initialize the I2C1
 * @param  None
 * @retval None
 */
void I2C1_Init(void){
	GPIO_InitTypeDef	GPIO_InitStructure;
	I2C_InitTypeDef		I2C_InitStructure;
	NVIC_InitTypeDef	NVIC_InitStructure;

	//Khoi tao GPIO
	//Cap clock cho AHB1
	RCC_APB1PeriphClockCmd(I2C_SLAVE_RCC, ENABLE);
	RCC_AHB1PeriphClockCmd(I2C_SLAVE_GPIO_RCC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	//Khoi tao cac tham so ban dau
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;


	GPIO_InitStructure.GPIO_Pin = SCL_SLAVE_PIN |SDA_SLAVE_PIN;
	GPIO_Init(I2C_SLAVE_PORT, &GPIO_InitStructure);

	GPIO_Init(I2C_SLAVE_PORT, &GPIO_InitStructure);

	//Chon PA8 lam chan SCL
	GPIO_PinAFConfig(I2C_SLAVE_PORT, GPIO_PinSource8, GPIO_AF_I2C1);
	//Chon PB9 lam chan SDA
	GPIO_PinAFConfig(I2C_SLAVE_PORT, GPIO_PinSource9, GPIO_AF_I2C1);

	//Khoi tao ngoai vi I2C1 su dung che do SLAVE
	//Khoi tao cac tham so ban dau
	//Khoi tao mode master
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_ClockSpeed = I2C_SPEED;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1 = SERIAL_ADR;
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

	//Khoi tao I2C
	I2C_Init(I2C_SLAVE_INSTANCE, &I2C_InitStructure);

	//Bat I2C
	I2C_Cmd(I2C_SLAVE_INSTANCE, ENABLE);

	//Bat ngat cho chan
	I2C_ITConfig(I2C_SLAVE_INSTANCE, I2C_IT_EVT, ENABLE);
	I2C_ITConfig(I2C_SLAVE_INSTANCE, I2C_IT_BUF, ENABLE);

	NVIC_InitStructure.NVIC_IRQChannel = I2C1_EV_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);
}

/**
 * @func   I2C1_EV_IRQHandler
 * @brief  The Interupt function of I2C1
 * @param  None
 * @retval None
 */
void I2C1_EV_IRQHandler(void){
	switch (I2C_GetLastEvent(I2C_SLAVE_INSTANCE)){
	case I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED:
		//Dia chi gui boi master trung voi dia chi

		I2C_ClearFlag(I2C_SLAVE_INSTANCE, I2C_FLAG_ADDR);
		break;
	case I2C_EVENT_SLAVE_BYTE_RECEIVED:

		reciveData = I2C_ReceiveData(I2C_SLAVE_INSTANCE);

		I2C_ClearFlag(I2C_SLAVE_INSTANCE, I2C_FLAG_RXNE);
		break;
	case I2C_EVENT_SLAVE_STOP_DETECTED:
		//Huy bo bit stop

		I2C_AcknowledgeConfig(I2C_SLAVE_INSTANCE, ENABLE);
		break;
	default:
		break;
	}
	I2C_ClearITPendingBit(I2C_SLAVE_INSTANCE, I2C_IT_RXNE);
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

	//Bat block cho GPIO
	RCC_AHB1PeriphClockCmd(LED_GPIO_RCC, ENABLE);

	//Khoi tao cac gia tri ban dau cho GREEN1
	GPIO_Initstruct.GPIO_Pin = LEDGREEN1_GPIO_PIN | LEDGREEN2_GPIO_PIN;
	GPIO_Initstruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(LEDGREEN1_GPIO_PORT, &GPIO_Initstruct);
}

/**
 * @func   Button_Init
 * @brief  Initialize the Button
 * @param  None
 * @retval None
 */
static void Button_Init(void){
	//Khai bao kieu du lieu
	GPIO_InitTypeDef GPIO_Initstruct2;

	//Bat Clock cho GPIOB
	RCC_AHB1PeriphClockCmd(BUTTON_GPIO_RCC, ENABLE);

	//Khoi tao ngat cho nut nhan 2
	//Khoi tao cac gia tri ban dau cho chan GPIO
	GPIO_Initstruct2.GPIO_Pin = BUTTON_GPIO_PIN;
	GPIO_Initstruct2.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Initstruct2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Initstruct2.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(BUTTON_GPIO_PORT, &GPIO_Initstruct2);
}

/**
 * @func   I2C_Start
 * @brief  Start the I2C
 * @param  None
 * @retval None
 */
void I2C_Start(void){
	//Doi I2Cx khong ban
	while (I2C_GetFlagStatus(I2C_MASTER_INSTANCE, I2C_FLAG_BUSY));

	I2C_GenerateSTART(I2C_MASTER_INSTANCE, ENABLE);

	while (!I2C_CheckEvent(I2C_MASTER_INSTANCE, I2C_EVENT_MASTER_MODE_SELECT));
}

/**
 * @func   I2C_SendAddress
 * @brief  Send the Address of slave to SDA line.
 * @param  address
 * @retval None
 */
void I2C_SendAddress(uint8_t address){
	I2C_Send7bitAddress(I2C_MASTER_INSTANCE, address, I2C_Direction_Transmitter);

	while (!I2C_CheckEvent(I2C_MASTER_INSTANCE, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
}

/**
 * @func   I2C_TransmitData
 * @brief  Send the data to slave
 * @param  data
 * @retval None
 */
void I2C_TransmitData(uint8_t data){
	I2C_SendData(I2C_SLAVE_INSTANCE, data);

	while (!I2C_CheckEvent(I2C_MASTER_INSTANCE, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
}

/**
 * @func   I2C_Stop
 * @brief  Stop the I2C
 * @param  None
 * @retval None
 */
void I2C_Stop(void){
	I2C_GenerateSTOP(I2C_MASTER_INSTANCE, ENABLE);
}

/**
 * @func   Button_GetLogic
 * @brief  Get the status of button
 * @param  GPIOx, GPIO_Pin.
 * @retval Status of Button.(0 or 1)
 */
static uint8_t Button_GetLogic(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	return GPIO_ReadInputDataBit(GPIOx, GPIO_Pin);
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
 * @func   CalculateTime
 * @brief  Calculate the time betwen 2 time.
 * @param  Time now, Time Miles
 * @retval Timenow - Time Miles
 */
static uint32_t Calculate_time(uint32_t TimeInit, uint32_t TimeCurrent){
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
