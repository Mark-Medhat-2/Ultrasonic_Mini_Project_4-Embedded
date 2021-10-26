/*
 * Ultrasonic.h
 *
 *  Created on: Oct 25, 2021
 *      Author: marcm
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "icu.h"
#include "gpio.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use ICU/Timer1 Registers */
#include <avr/interrupt.h> /* For ICU ISR */
#include <util/delay.h>
void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
