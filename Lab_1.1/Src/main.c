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

#include <stdint.h>

//----------------------Define---------------
#define RCC_BASE_ADDR				0x40023800UL
#define RCC_CFGR_REG_OFFSET 		0x08UL

#define RCC_CFGR_REG_ADDR 			(RCC_BASE_ADDR + RCC_CFGR_REG_OFFSET)
#define GPIOA_BASE_ADDR 			0x40020000UL

uint32_t *pRccCfgrReg = (uint32_t *)RCC_CFGR_REG_ADDR;

int main(void)
{
	*pRccCfgrReg &= ~(0x3 << 21); // Clear 21 and 22 bit positions

	//Chinh prescale
	*pRccCfgrReg |= (1 << 25);
	*pRccCfgrReg |= (1 << 26);

	//Cap xung cho port A
	uint32_t *pRCCAhb1Enr = (uint32_t*)(RCC_BASE_ADDR + 0x30);
	*pRCCAhb1Enr |= ( 1 << 0);

	//Cai dat chan PA8 o che do AF
	uint32_t *pGPIOAModeReg = (uint32_t*)(GPIOA_BASE_ADDR + 00);
	*pGPIOAModeReg &= ~( 0x3 << 16);
	*pGPIOAModeReg |= ( 0x2 << 16);

	//Cai dat che do
	uint32_t *pGPIOAAltFunHighReg = (uint32_t*)(GPIOA_BASE_ADDR + 0x24);
	*pGPIOAAltFunHighReg &= ~( 0x0f << 0);
    /* Loop forever */
	while (1){

	}
}
