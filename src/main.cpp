/*
 * Massively inspired by https://solarduino.com/diy-irradiation-meter-with-arduino/
 * 
 * I'm running this on one of my Heltec ESP32+LORA boards, with built in OLED.
 * 
 * 8/10/20 - So far I have a working irradiance monitor that displays current irradiance to its onboard OLED effectively.
 *           Next step is to make it log it over a network connection to a host.
 *           I’ll freeze “PJ_ESP32_Heltec_solar_baseline_monitor.ino” where it is and leave that as a working sketch for 
 *           the non networked monitor and copy that today 
 *           to “PJ_ESP32_Heltec_solar_baseline_monitor and logger.ino” and do all additional features in that code.
 * 9/10/20 - Migrated project to platformio and broke it into a bunch of sub files
 * 
 */

// setup() and loop() are now in separate cpp files, I'm just keeping this file for the history log above.


// sdkjfs jg
// sj dfjhsg dfjh