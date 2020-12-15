|Ex.1| Remember Lab 1, upload the Blink LED source code. build the circut and see if it works.
|--|--|
![image one](ressources/image_one.jpg?raw=true)
We used the same code as for lab 1, changing the input pin to 1, the entry of the anode while puting the cathode on the ground.
```C
const int led = 1;
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}
 
// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);      // turn the LED on (HIGH is the voltage level)
  delay(1000);                  // wait for a second
  digitalWrite(led, LOW);       // turn the LED off by making the voltage LOW
  delay(1000);                  // wait for a second
}
```


|Ex.2| Remember Lab 3, Upload the code of Ex.3 there. build the circut and see if it works.
|--|--|
![image two](ressources/image_two.jpg?raw=true)

It didn't work.


|Ex.3| Build circuit of [Step 6 in Lab1](https://github.com/efrei-paris-sud/2020-lab-one#step-6-read-an-analog-value). Send its data to thingspeak dashboard! Take a photo of the dashboard
|--|--|
![image three](ressources/image_three.jpg?raw=true)

At first we had trouble because we had reproduces the whole circuit on the arduino and only connected the output of the Variable to the nodeMCU. But since the arduino work at 5.5V and the node work at less, all the input received exceded the node capacity and read as 4095, the maximum possible input. 
At first we through that we had the wrong pin and tried changing it , renaming the analogRead parameter... However we needed to switch the input woltage from the Arduino to the node, once we did that our system worked.


|Advanced topic| Add the plugin to your dashboard. is it working?
|--|--|
![image four](ressources/image_four.jpg?raw=true)

Once added the plugin only allow to be checked when the sensor is at 1 and unchecked when it is at 0.