#include <HCSR04.h>
//Since there are two ultrasound detectors, we will only use two colors and connect the green to the VCC
const int red_pin = 11;
const int blue_pin = 10;

//The two ultrasound sensors
UltraSonicDistanceSensor distanceSensor(4, 5);
UltraSonicDistanceSensor distanceSensor2(2, 3);


void setup () {
    Serial.begin(9600);
    pinMode(red_pin, OUTPUT);
    pinMode(blue_pin, OUTPUT);
}

void loop () {
    int sr_01_dist = (int) distanceSensor.measureDistanceCm()*100;
    int sr_02_dist = (int) distanceSensor2.measureDistanceCm()*100;
    // Measure the distance in the console.
    Serial.println("SR_01: " + String(distanceSensor.measureDistanceCm(), 6));
    Serial.println("SR_02: " + String(distanceSensor2.measureDistanceCm(), 6));

    //Place these values into the colors
    setColor(sr_01_dist, sr_02_dist);
    
    delay(250);
}

void setColor (int red, int blue) {
  analogWrite(red_pin, red);
  analogWrite(blue_pin, blue);
}
