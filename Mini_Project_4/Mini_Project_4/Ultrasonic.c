/*
 * Ultrasonic.c
 *
 *  Created on: Oct 25, 2021
 *      Author: Mark Medhat Makram
 */
#include "Ultrasonic.h"
Icu_ConfigType Config;
uint16 period;
uint16 distance;

void Ultrasonic_init(void){
	Config.clock=F_CPU_8;
	Config.edge=RISING;
	Icu_init(&Config);
	Icu_setCallBack(&Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTD_ID,PIN6_ID,PIN_INPUT);
	GPIO_writePin(PORTB_ID,PIN5_ID, LOGIC_LOW);
}

void Ultrasonic_Trigger(void){
	GPIO_writePin(PORTB_ID,PIN5_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORTB_ID,PIN5_ID, LOGIC_LOW);
}
uint16 Ultrasonic_readDistance(void){
	Ultrasonic_Trigger();
	distance=period/58.8;
	return distance;
}

void Ultrasonic_edgeProcessing(void){
	if(Config.edge==RISING){
		Icu_clearTimerValue();
		Config.edge=FALLING;
		Icu_setEdgeDetectionType(FALLING);
	}
	else {
		period=Icu_getInputCaptureValue();
		Config.edge=RISING;
		Icu_setEdgeDetectionType(RISING);
	}
}
