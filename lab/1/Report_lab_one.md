|Ex.1| Test your LED by connecting the orange wire to the red bus (VCC). Is it work? Document it in your GitHub repository using [this format](https://github.com/efrei-paris-sud/2019-sample-project/tree/master/lab/1). |
|--|--|

If we connect the red cable to the VCC, the LED keeps on.

|Ex.2| Turn on and off an LED in port 4. Is it work? Please don't forget to document it with [this format](https://github.com/efrei-paris-sud/2019-sample-project/tree/master/lab/1). |
|--|--|

We just need to change the LED to 4 instead of 6

![Image one](IMG_3330.jpg?raw=true)

|Ex.3| Is it work? Please don't forget to document it with [this format](https://github.com/efrei-paris-sud/2019-sample-project/tree/master/lab/1). |
|--|--|

Yes is work
```C
const int buttonPin = 2;
const int LEDPIN= 13;
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(buttonPin, INPUT);   
   pinMode(LEDPIN, OUTPUT);   
   Serial.begin(9600);
}
 
// the loop routine runs over and over again forever:
void loop() {
  int buttonState = -1;
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  digitalWrite(LEDPIN, buttonState);
  delay(100);
  
}
```

|Ex.4| Is it work? Please don't forget to document it with [this format](https://github.com/efrei-paris-sud/2019-sample-project/tree/master/lab/1). |
|--|--|

It works with this code
```C
const int LEDPIN = 13;
int stateCurr;
int value;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  stateCurr = 0;
  value = analogRead(A0);
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);  
}
 
// the loop routine runs over and over again forever:
void loop() {
  value = analogRead(A0);
  stateCurr = (stateCurr + 1) % 2;
  digitalWrite(LEDPIN, stateCurr);
  delay(value);
}
```

|Ex.5| Is it work? Please don't forget to document it with [this format](https://github.com/efrei-paris-sud/2019-sample-project/tree/master/lab/1). |
|--|--|
The code is

```C
const int pin = 5;
int value = 0;
bool increase = true;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(pin, OUTPUT);
  Serial.begin(9600);  
}
 
// the loop routine runs over and over again forever:
void loop() {
  if(increase && value < 255) {
    value++;
  } else if (increase && value == 255) {
    increase = false;
  } else if(!increase && value > 0) {
    value--;
  } else if (!increase && value == 0) {
    increase = true;
  } 
  analogWrite(pin, value);
  delay(10);
}
```

|Ex.6| Is it work? Please don't forget to document it with [this format](https://github.com/efrei-paris-sud/2019-sample-project/tree/master/lab/1). |
|--|--|

Yes it works

```C
const int pin = 5;
#define TIME 2000

//to generates a 400Hz tone in output pin 8 with 2000ms of duration you can use tone(8, 400, 2000);
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  
}
 
// the loop routine runs over and over again forever:
void loop() {
  tone(pin, 400, TIME);
  delay(3000);
 }
```

|Ex.7| prepare a program to have different colors (at least 5) with a delay of 1000 ms . Is it work? Please don't forget to document it with [this format](https://github.com/efrei-paris-sud/2019-sample-project/tree/master/lab/1). |
|--|--|

It works
```C
const int red_pin = 11;
const int green_pin = 10;
const int blue_pin = 9;

//to generates a 400Hz tone in output pin 8 with 2000ms of duration you can use tone(8, 400, 2000);
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
   pinMode(red_pin, OUTPUT);
   pinMode(green_pin, OUTPUT);
   pinMode(blue_pin, OUTPUT);
}
 
// the loop routine runs over and over again forever:
void loop() {
  setColor(100, 60, 150);
  setColor(60, 130, 150);
  setColor(110, 230, 40);
  setColor(230, 200, 120);
  setColor(200, 20, 110);
 }

void setColor(int red, int green, int blue) {
  analogWrite(red_pin, red);
  analogWrite(green_pin, green);
  analogWrite(blue_pin, blue);
  delay(1000);
}

```