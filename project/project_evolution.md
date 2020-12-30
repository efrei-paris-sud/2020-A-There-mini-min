# Project Title: Thereminimin
 **Description**: Our project is about making a Theremin, an electrical music instrument that crosses all frequencies (like a violin). It uses a proximity sensor as it is controlled by distance.

# First tests for the project
Before doing the project itself, we did some tests that will be related in this document.

## Testing the HC-SR04
The HC-SR04 is a small digital module that reflects an ultrasound to a surface. 

![HCSR04](https://projetsdiy.fr/data/uploads/2020/05/hc-sr04-arduino-schema-principe-trig-echo.jpg.webp?raw=true)

Our first test was about testing its ability to measure distance in cm. 
As a HCSR04 library is available in the Arduino Library Store, there was some examples of its usage like the "Simple" program that writes the distance.

After testing it in real life, we found out that the measures were correct.

![Image test](img/IMG_3523.PNG?raw=true)
![Cover GIF](img/screen_firsttest.png?raw=true)

We redid it with the ESON Board
![Image test](img/wifi_distance.PNG?raw=true)
![Image test](img/wifi_distance_pic.PNG?raw=true)


## Testing two HC-SR04
Since a Theremin works with two inputs (volume and frequency), we borrowed a second ultrasound sensor to our classmates.
Now, we want to use two of these and see how they behave together. They work fine together.

![Image test](img/2020-12-1509.56.01.jpeg?raw=true)
![Cover GIF](img/screen_secondtest.png?raw=true)

Here is the code for this second test: 

```Arduino
#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(4, 5);
UltraSonicDistanceSensor distanceSensor2(2, 3);


void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    Serial.println("SR_01: " + String(distanceSensor.measureDistanceCm(), 6));
    Serial.println("SR_02: " + String(distanceSensor2.measureDistanceCm(), 6));
    delay(500);
}
```

## Testing the output

we tried to make the RGB LED vary with the ultrasound sensors, however we couldn't appreciate well the results.

![RGB LED Test](img/2020-12-1510.58.51.jpeg?raw=true)

# Design the prototype

We used Fritzing in order to vizualize the design of our module

The schema prototype
![Schema prototype](img/Prototype_schema.png?raw=true)
The breadboard prototype
![BB prototype](img/Prototype_bb.png?raw=true)

# Test the bluetooth
## Basic testing

We connected the ESP32S to an android bluetooth (classic protocol) and tried to send and receive message through the application Serial Bluetooth Terminal.

![Phone side](img/esp32phone.png?raw=true) 
![Computer side](img/esp32pc.png?raw=true)

We then coded a way to control our system through the app with a simple on/off option for a led.
![Led testing](img/esp32led.png?raw=true)

From then we needed to find a way to control our device from the esp32, we found the library Ble Keyboard who allow us to input keys in our device. It worked on computer but didn't on smartphone. We could abandon the idea of using our smartphone and using our computer instead, seen as once we have control over keys input we can do pretty much everything in a computer.
(As we can see, the library convert character to their mapped key, since it's of english origin it uses the qwerty format and not the azerty one, thus when we write "w" it read the corresponding key emplacement wich is a "z" on a qwerty keyboard)
![Led testing](img/blekeyboard.png?raw=true)


# DES MATH


# Remerciement
Remerciement spécial à Nice for What pour leur contribution matérielle et morale à notre projet