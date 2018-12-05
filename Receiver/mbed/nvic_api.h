/* mbed Microcontroller Library - nvic_api
 * Copyright (c) 2006-2009 ARM Limited. All rights reserved.
 * sford
 */ 
 
// GENERIC (M3 only? maybe also ARM7 abstraction)

#ifndef MBED_NVIC_API_H
#define MBED_NVIC_API_H

#include "PinNames.h"
#include "PeripheralNames.h"

#ifdef __cplusplus
extern "C" {
#endif 

typedef enum IRQn IRQn;

void nvic_init(); 
uint32_t nvic_read(IRQn irq);
void NVIC_Vector(IRQn irq, uint32_t vector);

#ifdef __cplusplus
}
#endif 

#endif
