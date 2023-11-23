 /* File name: Assignment02.IoT303x
 *
 * Description:
 *
 *
 * Last Changed By:  Author: Pham Nhat Tan
 * Revision:         Revision:
 * Last Changed:     Date: Nov 17, 2023
 *
 ******************************************************************************/
/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include <stdint.h>
#include "timer.h"
#include "Ucglib.h"
#include "stm32f401re_gpio.h"
#include "stm32f401re_rcc.h"
#include <string.h>
#include <stdio.h>
#include "temhumsensor.h"
#include "stm32f401re_i2c.h"
/******************************************************************************/
/*                     PRIVATE TYPES and DEFINITIONS                         */
/******************************************************************************/
static ucg_t ucg;

#define GPIO_PIN_SET					1
#define GPIO_PIN_RESET					0

#define I2C_MASTER_RCC					RCC_APB1Periph_I2C1
#define I2C_MASTER_INSTANCE				I2C1

#define I2C_MASTER_GPIO_RCC				RCC_AHB1Periph_GPIOB
#define I2C_MASTER_PORT					GPIOB
#define SDA_MASTER_PIN					GPIO_Pin_9
#define SCL_MASTER_PIN					GPIO_Pin_8

#define I2C_SPEED						400000 //400KB/s

#define SLAVE_ADDRESS					0x40<<1

static uint32_t reciveData[5];

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/
void 		AppInitCommon();
void 		I2C1_Init(void);
void 		I2C_Start(uint8_t direction);
void 		I2C_SendAddress(uint8_t address);
void 		I2C_TransmitData(uint8_t data);
void 		Delay(uint32_t ms);
void 		I2C_Stop(void);
uint8_t 	I2C_Recevie_nack(void);
uint8_t 	I2C_Recevie_ack(void);
uint32_t 	Calculate_time(uint32_t TimeInit, uint32_t TimeCurrent);

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/
int main(void)
{
	I2C1_Init();
	TimerInit();
	SystemInit();
	char buffer1[256] = "b0";
	char buffer2[256] = "b0";
	uint32_t Timetick = 0;
	AppInitCommon();
    /* Loop forever */
	while (1){

		if (Calculate_time(Timetick, GetMilSecTick()) >= 1000){
			I2C_Start(I2C_Direction_Transmitter);
			I2C_TransmitData(0xE5);
			I2C_Stop();

			I2C_Start(I2C_Direction_Receiver);
			reciveData[0] = (I2C_Recevie_ack()<<8)*100/65536 - 6;
			I2C_Stop();

			I2C_Start(I2C_Direction_Transmitter);
			I2C_TransmitData(0xE3);
			I2C_Stop();

			I2C_Start(I2C_Direction_Receiver);
			reciveData[1] = (I2C_Recevie_ack()<<8)*175.72/65536 - 46.85;
			I2C_Stop();
			Timetick = GetMilSecTick();
			memset(buffer1,0,sizeof(buffer1));
			sprintf(buffer1,"HUMI: %0.2d %%",reciveData[0]);
			memset(buffer2,0,sizeof(buffer2));
			sprintf(buffer2,"TEMP: %d oC",reciveData[1]);
			ucg_DrawString(&ucg, 10, 35, 0,"Assignment 2");
			ucg_DrawString(&ucg, 10, 65, 0,buffer1);
			ucg_DrawString(&ucg, 10, 100, 0,buffer2);
		}
		processTimerScheduler();
	}
}
/******************************************************************************/
/**
 * @func   AppInitCommon
 * @brief  Initzation all Parameter
 * @param  None
 * @retval None
 */
void AppInitCommon(){
	TimerInit();
	Ucglib4WireSWSPI_begin(&ucg, UCG_FONT_MODE_SOLID);
	ucg_ClearScreen(&ucg);
	ucg_SetFont(&ucg, ucg_font_ncenR12_hr);
	ucg_SetColor(&ucg, 0, 255, 255, 255);
	ucg_SetColor(&ucg, 1, 0, 0, 0);
	ucg_SetRotate180(&ucg);
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
 * @func   I2C1Init
 * @brief  Initzation parameter of I2C1.
 * @param  None
 * @retval None
 */
void I2C1_Init(void){
	GPIO_InitTypeDef	GPIO_InitStructure;
	I2C_InitTypeDef		I2C_InitStructure;

	//Khoi tao GPIO
	//Cap clock cho AHB1
	RCC_APB1PeriphClockCmd(I2C_MASTER_RCC, ENABLE);
	RCC_AHB1PeriphClockCmd(I2C_MASTER_GPIO_RCC, ENABLE);

	//Khoi tao cac tham so ban dau
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;


	GPIO_InitStructure.GPIO_Pin = SCL_MASTER_PIN | SDA_MASTER_PIN;
	GPIO_Init(I2C_MASTER_PORT, &GPIO_InitStructure);

	//Chon PA8 lam chan SCL
	GPIO_PinAFConfig(I2C_MASTER_PORT, GPIO_PinSource8, GPIO_AF_I2C1);
	//Chon PB9 lam chan SDA
	GPIO_PinAFConfig(I2C_MASTER_PORT, GPIO_PinSource9, GPIO_AF_I2C1);

	//Khoi tao ngoai vi I2C3 su dung che do Master
	//Khoi tao cac tham so ban dau
	//Khoi tao mode master
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_ClockSpeed = I2C_SPEED;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1 = 0x00;
	I2C_InitStructure.I2C_Ack = I2C_Ack_Disable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

	//Khoi tao I2C
	I2C_Init(I2C_MASTER_INSTANCE, &I2C_InitStructure);

	//Bat I2C
	I2C_Cmd(I2C_MASTER_INSTANCE, ENABLE);
}

/**
 * @func   I2C start
 * @brief  Start I2C, Send 7 bit address to Slave and wating slave in Idle status.
 * @param  direction
 * @retval None
 */
void I2C_Start(uint8_t direction){
	//Doi I2Cx khong ban
	while (I2C_GetFlagStatus(I2C_MASTER_INSTANCE, I2C_FLAG_BUSY));

	I2C_GenerateSTART(I2C_MASTER_INSTANCE, ENABLE);

	while (!I2C_CheckEvent(I2C_MASTER_INSTANCE, I2C_EVENT_MASTER_MODE_SELECT));

	//gui dia chi Slave de ghi
	I2C_Send7bitAddress(I2C_MASTER_INSTANCE, SLAVE_ADDRESS, direction);


	if(direction == I2C_Direction_Transmitter){
		while(!I2C_CheckEvent(I2C_MASTER_INSTANCE, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	}
	else if(direction == I2C_Direction_Receiver){
		while(!I2C_CheckEvent(I2C_MASTER_INSTANCE, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	}
}

/**
 * @func   I2C transmitData
 * @brief  Send data to Slave and save data in return data
 * @param  data
 * @retval data
 */
void I2C_TransmitData(uint8_t data){
	I2C_SendData(I2C_MASTER_INSTANCE, data);

	while (!I2C_CheckEvent(I2C_MASTER_INSTANCE, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
}

uint8_t I2C_Recevie_nack(void){
	//Bat ACK cua recevie data
	I2C_AcknowledgeConfig(I2C_MASTER_INSTANCE, ENABLE);

	I2C_GenerateSTOP(I2C_MASTER_INSTANCE, ENABLE);
	//Doi khi nhan dc 1 byte
	while (!I2C_CheckEvent(I2C_MASTER_INSTANCE, I2C_EVENT_MASTER_BYTE_RECEIVED));

	uint8_t data = I2C_ReceiveData(I2C_MASTER_INSTANCE);
	return data;
}

/**
 * @func   I2C Recevie ack
 * @brief  Recevie bit ack from slave
 * @param  None
 * @retval Bit ack (data)
 */
uint8_t I2C_Recevie_ack(void){
	//Bat ACK cua recevie data
	I2C_AcknowledgeConfig(I2C_MASTER_INSTANCE, DISABLE);

	//Doi khi nhan dc 1 byte
	while (!I2C_CheckEvent(I2C_MASTER_INSTANCE, I2C_EVENT_MASTER_BYTE_RECEIVED));

	uint8_t data = I2C_ReceiveData(I2C_MASTER_INSTANCE);

	return data;
}

/**
 * @func   I2C Recevie ack
 * @brief  Recevie bit ack from slave
 * @param  None
 * @retval Bit ack (data)
 */
void I2C_Stop(void){
	I2C_GenerateSTOP(I2C_MASTER_INSTANCE, ENABLE);
}

