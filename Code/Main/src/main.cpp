#include "stm32f4xx.h"

volatile unsigned int i;
int main(void)
{
    SystemInit();

    RCC -> AHB1ENR |= RCC_AHB1ENR_GPIODEN;                  // Enable usage of GPIOD
    RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;                   // Enable usage of TIM4

    GPIOD -> MODER = (0b10 << 24);                          // Alternate function for PWM on PD12
    GPIOD -> OSPEEDR = (0xFF << 24);                        // High Speed on PD12
    GPIOD -> AFR[1] |= (0x2 << 16);                         // AFRH selected AF2 (TIM4; CH1) for PB6

    TIM4 -> CCMR1 |= (0x7 << 4) | (0x1 << 3);               // PWM Mode 2, channel 1 output compare preload enabled
    TIM4 -> CCR1 = 0x0199;                                  // 10% duty cycle (arbitrary)
    TIM4 -> PSC = 0x0000;                                   // No pre-scaler
    TIM4 -> ARR = 0x1000;                                   // Reload at 0x1000


    (*TIM4).CCER |= TIM_CCER_CC1E;                          // Enable CH1 output
    (*TIM4).CR1 |= (0x2 << 8) | TIM_CR1_ARPE | TIM_CR1_CEN; // Divide clock by 4, auto-reload, and start timer

    while(1) {
        // Do nothing, used for debug
        i++;
    }
}