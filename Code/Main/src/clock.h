/**
  ******************************************************************************
  * @file	clock.h
  * @author	Yohanes Erwin Setiawan 歐陽文孝
  * @brief	This file contains function prototype for clock library.
  ******************************************************************************
  * @note	Before use this library, make sure the HSE_VALUE in stm32f4xx.h
  * 		file is correct according to the external crystal value of
  * 		STM32F4 Discovery board which is 8MHz.
  * 		Another way to change the HSE_VALUE is from toolchain compiler
  * 		preprocessor.
  ******************************************************************************
  */

#ifndef __CLOCK_H
#define __CLOCK_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_flash.h"

ErrorStatus CLOCK_SetClockTo168MHz(void);

#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ********************************/
