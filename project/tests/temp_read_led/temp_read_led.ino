/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com
*********/

// Load libraries
#include "BluetoothSerial.h"
#include <OneWire.h>

// Check if Bluetooth configs are enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Bluetooth Serial object
BluetoothSerial SerialBT;

// GPIO where LED is connected to
const int ledPin =  25;

// GPIO where the DS18B20 is connected to
const int oneWireBus = 32;          
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Handle received and sent messages
String message = "";
char incomingChar;
String temperatureString = "";

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  // Bluetooth device name
  SerialBT.begin("ESP32");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
 
  // Read received messages (LED control command)
  if (SerialBT.available()){
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }
  // Check received message and control output accordingly
  if (message =="led_on"){
    Serial.println("\n on");
    digitalWrite(ledPin, HIGH);
  }
  else if (message =="led_off"){
    Serial.println("\n off");
    digitalWrite(ledPin, LOW);
  }
  delay(20);
}
