#include "globals.h"

float currentReading; //  store a Current sample from the INA
float ShortCircuitCurrentSTC = 1.21;      // Key in the Short Circuit Current (At STC condition) of your Solar Panel or Solar Cell. Value 9 showing 9.0A Isc Panel.
                                          // My PowerTech 20W ZM-9052 panel label has Isc=1.21A
float Irradiation = 0.00;                 // This shows the irradiation level in W/m2.

Adafruit_INA260 ina260a = Adafruit_INA260();  // instantiate the 1st INA260 (default I2C address 0x40), sometimes I use more than one
