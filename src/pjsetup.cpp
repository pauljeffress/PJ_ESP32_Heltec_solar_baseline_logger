#include "pjsetup.h"

 


void setup(void) 
{
  Serial.begin(115200);
  delay(3000);  // wait for serial to get up and running
  Serial.println("Hello!");
    
  // Initialise the Heltec ESP32 Lora built in display, but not the LORA module on it.
  // Note, the below Heltec initiaizsr code just takes over and reassigns the 
  // default I2C port to the I2C port found on 4 & 15!
  // It looks like that’s because the where the Heltec’s I2C OLED is wired.
  // So, when using Heltec.begin I need to use 4 & 15 for my I2C devices!
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRaEnable Disable*/, true /*SerialEnable Enable*/);  
  // set OLED font and text alignment
  Heltec.display->setFont(ArialMT_Plain_10);
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
  // clear the display
  Heltec.display->clear();

  Heltec.display->drawString(0, 0, "PJ Solar Baseline Monitor");
  Heltec.display->display();  // write the buffer to the display
  Serial.println("PJ Solar Baseline Monitor");

  // There is a hardcoded value that has to match the solar panel that is used to test for Irradiance
  // It is the Isc value from the panel and it is hard coded above in 
  // float ShortCircuitCurrentSTC
  // so here I'm going to display what panel its based on etc.
  // As a reminder which exact panel this code works with.
  Heltec.display->drawString(0, 10, "Isc hard coded to 1.21A");
  Heltec.display->display();  // write the buffer to the display
  Serial.println("PJ Solar Baseline Monitor");

  // check that INA still connected properly
  Heltec.display->drawString(0, 20, "Testing if INA260 detected...");
  Heltec.display->display();  // write the buffer to the display
  Serial.println("Testing if INA260 detected...");
  if (!ina260a.begin()) {
    Heltec.display->drawString(0, 30, "Couldn't find INA260 chip");
    Heltec.display->display();  // write the buffer to the display
    Serial.println("Couldn't find INA260 chip");
    while (1);
  }
  Heltec.display->drawString(0, 30, "Found INA260 chip");
  Heltec.display->display();  // write the buffer to the display
  Serial.println("Found INA260 chip");

  delay(3000);  // so I have time to read the fact that INA chip was found  :)

  // Now that INA def found,configure it
  // set the number of samples to average
  ina260a.setAveragingCount(INA260_COUNT_4);   // 1 sample is the default.
  // set the time over which to measure the current and bus voltage
  // ina260.setVoltageConversionTime(INA260_TIME_140_us);  // not using voltage measurements in this project
  ina260a.setCurrentConversionTime(INA260_TIME_1_1_ms);    // 1.1mS is the default
  ina260a.setMode(INA260_MODE_CONTINUOUS); // the default continuous mode, just setting/showing here for the sake of it.
  
} // END - setup()