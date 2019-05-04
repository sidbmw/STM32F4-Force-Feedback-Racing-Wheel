/**
  ******************************************************************************
  * @file	clock.c
  * @author	Yohanes Erwin Setiawan 歐陽文孝
  * @brief	This file contains function for setting the system clock
  * 		frequency to 168MHz.
  ******************************************************************************
  * @note	Before use this library, make sure the HSE_VALUE in stm32f4xx.h
  * 		file is correct according to the external crystal value of
  * 		STM32F4 Discovery board which is 8MHz.
  * 		Another way to change the HSE_VALUE is from toolchain compiler
  * 		preprocessor.
  ******************************************************************************
  */

#include "clock.h"

ErrorStatus CLOCK_SetClockTo168MHz()
{
	// Resets the clock configuration to the default reset state
	RCC_DeInit();

	// Enable external crystal (HSE)
	RCC_HSEConfig(RCC_HSE_ON);
	// Wait until HSE ready to use or not
	ErrorStatus errorStatus = RCC_WaitForHSEStartUp();

	if (errorStatus == SUCCESS)
	{
		// Configure the PLL for 168MHz SysClk and 48MHz for USB OTG, SDIO
		RCC_PLLConfig(RCC_PLLSource_HSE, 8, 336, 2, 7);
		// Enable PLL
		RCC_PLLCmd(ENABLE);
		// Wait until main PLL clock ready
		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);

		// Set flash latency
		FLASH_SetLatency(FLASH_Latency_5);

		// AHB 168MHz
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		// APB1 42MHz
		RCC_PCLK1Config(RCC_HCLK_Div4);
		// APB2 84 MHz
		RCC_PCLK2Config(RCC_HCLK_Div2);

		// Set SysClk using PLL
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

/********************************* END OF FILE ********************************/
