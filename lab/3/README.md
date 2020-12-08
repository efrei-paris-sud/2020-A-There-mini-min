# A bit from the Lab 2

Please read the document carefully from [Lab 2](https://github.com/efrei-paris-sud/2020-lab-two).

Now we want to use I2C LCD. 

> We can write a code to comunicate with the LCD with Bare I2C protocol. However it is time consuming. Therefore, We will use [Oled library](https://github.com/durydevelop/arduino-lib-oled/). 

# STEP 1: Importing Library:
Please follow [this link](https://learn.adafruit.com/adafruit-all-about-arduino-libraries-install-use/installing-a-library) and install [Oled library](https://github.com/durydevelop/arduino-lib-oled/)

# STEP 2: 
Connect the Oled Display using our last schematic: (please connect only Arduino and Oled and needed wires) 

![schematic](https://github.com/efrei-paris-sud/2020-lab-two/blob/main/chapter4_no_mpu5060.png?raw=true).

Is it okay? Let's go...

# STEP 3: Print on screen
You can easily print text on the screen in TTY mode by following codes.

```Arduino
#include <Arduino.h>
#include <oled.h>

OLED display=OLED(4,5);
void setup(){
    delay(1000);
    display.begin();
    display.setTTYMode(true); //To use display similar to a console.
    display.printf("Hello\n");
    display.printf("World %d!", 2020);
}
void loop(){
}
```

|Ex.1|Write a program that writes something on the display every 1000 ms.
---|---

# STEP 4: Display shapes and bitmaps
|Ex.2| Upload [oledtest.ino](oledtest.ino?raw=true), see the result and describe shortly the functionality of following functions in home! ([HINT](https://github.com/durydevelop/arduino-lib-oled/blob/master/src/oled.h))
---|---
```Arduino
    display.display();
    display.scroll_up(32,20);
    display.draw_string(4,2,"Hello");
    display.draw_string(4,2,"Hello",OLED::DOUBLE_SIZE);
    display.draw_string_P(16,15,PSTR("World!"),OLED::DOUBLE_SIZE);
    display.draw_bitmap_P(0,0,128,64,bitmap);
    display.set_scrolling(OLED::HORIZONTAL_RIGHT);
    display.set_invert(true);
    display.set_contrast(value);

    //optional
    display.draw_line(16,31,88,15);
    display.draw_pixel(127,0);
    display.draw_circle(36,16,14,OLED::SOLID);
    display.draw_rectangle(64,0,98,31);
```

# STEP 5: Display a custom image
As you can see in the last example we use Efrei photo. Now we want to use our own image!!!

when you see line 7 of [oledtest.ino](oledtest.ino), you can see the image bytes. To build your own one :
1. upload you image [here](https://javl.github.io/image2cpp/), 
2. specify the `width` and `height` (less than 128 x 64), 
3. choose proper `threshold` (between 0 and 255)
4. select `scale to fit, keeping proportions` option.
5. click on `generate code`. 
6. Use the generated content instead of the old one
7. don't forget to specify the `width` and `height`  used in the second item here: `display.draw_bitmap_P(0,0, width,height,bitmap);`

|Ex.3| Display your team name on the Oled with big font and add a random logo (Search for a `single color logo` or build you own logo and display it in the screen.)
---|---

