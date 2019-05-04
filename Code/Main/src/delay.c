/**
  ******************************************************************************
  * @file	delay.h
  * @author	Yohanes Erwin Setiawan æ­�é™½æ–‡å­�
  * @brief	This file contains functions for making delay (us and ms).
  ******************************************************************************
  */

#include "delay.h"

static __IO uint32_t usTick;

void DELAY_Init()
{
	// Configure the SysTick timer to overflow every 1 us
	SysTick_Config(SystemCoreClock / 1000000);
}

// SysTick_Handler function will be called every 1 us
void SysTick_Handler()
{
	if (usTick != 0)
	{
		usTick--;
	}
}

void DELAY_Us(uint32_t us)
{
	// Reload us value
	usTick = us;
	// Wait until usTick reach zero
	while (usTick);
}

void DELAY_Ms(uint32_t ms)
{
	// Wait until ms reach zero
	while (ms--)
	{
		// Delay 1ms
		DELAY_Us(1000);
	}
}

/********************************* END OF FILE ********************************/
