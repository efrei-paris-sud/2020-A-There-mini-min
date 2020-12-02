#include<Wire.h>
#include <Adafruit_BMP280.h>   // include BMP280 sensor library
Adafruit_BMP280  bmp280;  // initialize  BMP280 library
void setup(){
  if( bmp280.begin() == 0 )// initialize the BMP280 sensor
  {  // connection error or device address wrong!
  //ToDo: Show error in LCD
  while(1);  // stay here
  }
}
void loop(){
  float temp     = bmp280.readTemperature();   // get temperature
  float pressure = bmp280.readPressure();      // get pressure
  float humidity = bmp280.readHumidity();      // get humidity
  float altitude= bmp.readAltitude(seaLevelPressure) // get Altitude. The generic seaLevelPressure is 1013.25. If you put the current pressure of your city, you can find the Altitude of your place!
  delay(1000);  // wait a second
}
