#include "loop.h"

void loop(void) 
{
  currentReading = ina260a.readCurrent()/1000; // sample the current from INA (which reads in mA) and convert to Amps
  Irradiation = (currentReading/ShortCircuitCurrentSTC*1000); // convert Current (A) to Irradiation (W/m2)
  Serial.print("Current: ");  
  Serial.print(currentReading);
  Serial.print("A  Irradiation: ");
  Serial.print(Irradiation);
  Serial.println("W/m2");

  // crude way to clear just the bit of the OLED rows that have the previous current and irradiation readings already displayed there.
  Heltec.display->setColor(BLACK);
  Heltec.display->fillRect(0, 40, 120, 20);  // startX, startY, endX, endY
  Heltec.display->setColor(WHITE);
  // display the recent values
  Heltec.display->drawString(0, 40, "Current:            A");  
  Heltec.display->drawString(50, 40, String(currentReading));
  Heltec.display->drawString(0, 50, "Irradiance:            W/m2");  
  Heltec.display->drawString(50, 50, String(Irradiation));
  
  Heltec.display->display();  // write the buffer to the display

  delay(100);
  
} // END - loop()
