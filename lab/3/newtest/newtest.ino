#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

Adafruit_SH1106 display(23); 

void setup()   {
  display.begin();
  display.setTextColor(WHITE);
  display.setTextSize(2);
}


void loop() {
  display.setCursor(0, 0);
  display.clearDisplay();
  display.println("THE");
  display.display();

  delay(1000);

  display.clearDisplay();
  display.println("Worldooooo");
  display.display();
  delay(1000);
}
