#include<Wire.h>
#include <BMP280.h>   // include BMP280 sensor library
BMP280  bmp280;  // initialize  BMP280 library
void setup(){
  if( bmp280.begin() == 0 )// initialize the BMP280 sensor
  {  // connection error or device address wrong!
    Serial.println("The connection isn't possible !");
    while(1);  // stay here
  }
}
void loop(){
  float temp     = bmp280.readTemperature();   // get temperature
  delay(1000);  // wait a second
}
