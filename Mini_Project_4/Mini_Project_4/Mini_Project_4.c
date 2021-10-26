/*
 * Mini_Project_4.c
 *
 *  Created on: Oct 25, 2021
 *      Author: marcm
 */
#include "lcd.h"
#include "Ultrasonic.h"
uint16 distance=0;
int main(void){
	LCD_init();					 /* Initiating lcd driver*/
	Ultrasonic_init();			 /* Initiating Ultrasonic sensor driver*/
	LCD_displayString("distance=");
	while(1){
		LCD_moveCursor(0,10);
		distance=Ultrasonic_readDistance();		/*to read from ultrasonic sensor*/
		if(distance<=104){
			LCD_intgerToString(distance+1); /*due to calibration error in ultrasonic sensor*/
		}
		else{
			LCD_intgerToString(distance); 	/* displaying sensor reading*/
		}
		if(distance<=99){
			LCD_displayStringRowColumn(0,12," "); /*for clearing remaining values on lcd when number decreases*/
			}
		if(distance<=9){
			LCD_displayStringRowColumn(0,11," ");/*for clearing remaining values on lcd when number decreases*/
		}
		}
	}
}
