#pragma once

#include "../nucleo/nucleo-64.h"

#define ADC_RCC RCC_ADC12
#define ADC_CCR_PRESCALE ADC_CCR_CKMODE_DIV1
#define ADC_CHANNEL 1

#define ADC_OPAMP_CHANNEL 13

#define BUTTON_GPIO_RCC RCC_GPIOA
#define BUTTON_GPIO_PORT GPIOA
#define BUTTON_GPIO_PIN GPIO0
#define BUTTON_EXTI EXTI0
#define BUTTON_EXTI_IRQ NVIC_EXTI0_IRQ

#include <libopencm3/stm32/rcc.h>
void initializeSystemClocks() {
  rcc_clock_setup(&rcc_clock_config[RCC_CLOCK_CONFIG_HSI_PLL_170MHZ]);
  // enable rcc peripheral clock for dmamux
  *(uint32_t*)0x40021048 |= 0b100;
}
