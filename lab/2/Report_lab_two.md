|Ex.1|  Develop an arduino program which can read a byte from serial  and adjust the passive buzzer frequency with that. Write a response that your buzzer frequency changed to the read value. (`lab/2/exercise/2/code1.ino`).
---|---
||Connect your Arduino board to computer. Open a serial communication software (You can use built in serial monitor in Arduino IDE by pressing `ctrl`+`shift`+`M`

```C
int frequency;

void setup() {
  Serial.begin(9600); // initialize serial:
  frequency = 1;
}

void loop() {
  // if there's any data available, read it:
  while (Serial.available() > 0) {
 
    int i  = Serial.parseInt();    // look for the next valid integer in the incoming serial stream:
    tone(5, i, 1000);
    byte b = Serial.read();    // look for the next valid byte in the incoming serial stream:
    if (Serial.read() == '\n') // look for the newline. That's the end of your sentence:
      
    // print the three numbers in one string as hexadecimal:
    Serial.print(15, HEX);//print F
    Serial.print(10, DEC);//Print 10
    Serial.println("Hello"); //Print Hello\n
    
  }
}
```

|Ex.2|Specifiy the I2C pins (SDA and SCL) in your devices such as micro controller, sensors, actuators.
---|---

A4 and A5

