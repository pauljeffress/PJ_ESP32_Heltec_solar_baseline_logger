#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

#include <heltec.h>   // PJ - brings in Heltec OLED stuff I need
#include <Adafruit_INA260.h>  // For the Adafruit INA260 I2C modules

/*
 *  Define global variables for entire project
 */

extern float currentReading; //  store a Current sample from the INA
extern float ShortCircuitCurrentSTC;      // Key in the Short Circuit Current (At STC condition) of your Solar Panel or Solar Cell. Value 9 showing 9.0A Isc Panel.
                                          // My PowerTech 20W ZM-9052 panel label has Isc=1.21A
extern float Irradiation;                 // This shows the irradiation level in W/m2.

extern Adafruit_INA260 ina260a;  // instantiate the 1st INA260 (default I2C address 0x40), sometimes I use more than one

#endif

