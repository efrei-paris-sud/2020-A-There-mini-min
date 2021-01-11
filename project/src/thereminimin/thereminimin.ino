#include <HCSR04.h>

float currVol = 0;
int volume = 0;
float currFreq = 0;
int frequency = 0;

//The two ultrasound sensors
UltraSonicDistanceSensor distanceSensorVolume(34, 35); //(Trig, Echo)
UltraSonicDistanceSensor distanceSensorFrequency(32, 33); //(Trig, Echo)

void setup() {
  Serial.begin(115200);
  ledcSetup(0, 2000, 8); //Channel, Freq, Resolution
  ledcAttachPin(25, 0); //Pin, Channel
}

void loop() {
  //currVol   = distanceSensorVolume.measureDistanceCm();
  currFreq  = distanceSensorFrequency.measureDistanceCm();

  //currVol   -= 5; //Remove the first 5 centimeters
  currFreq  -= 5;

  //volume    = (int) currVol;
  frequency = (int) currFreq;
  
  //Trunkate the values from 5 to 50cm
  //volume    = (volume < 1) ? 1 : volume;
  //volume    = (volume > 45) ? 45 : volume;

  frequency = (frequency < 1) ? 1 : frequency;
  frequency = (frequency > 45) ? 45 : frequency;

  //volume    *= 5; //To access all audible notes
  frequency *= 20;

  //The minimal value
  frequency += 300;

  Serial.print("f=");
  Serial.println(frequency);
  //Serial.print(" | v=");
  //Serial.println(volume);

  //For the buzzer
  //ledcWrite(0, volume);
  ledcWriteTone(0, frequency);
}
