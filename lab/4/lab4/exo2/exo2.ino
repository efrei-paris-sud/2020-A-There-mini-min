#include <Wire.h>
#include <Adafruit_SH1106.h>
#include <Adafruit_GFX.h>

Adafruit_SH1106 display(22); 

const unsigned char myBitmap [] PROGMEM = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xc0, 0xe1, 0xff, 0xff, 0xff, 0xc0, 0x80, 0x7f, 0xff, 0xff, 0xc0, 0x00, 0x1f, 0xff, 0xff, 0xc0, 
  0x00, 0x07, 0xff, 0xff, 0xc0, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 
  0x00, 0x1f, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1c, 0x00, 
  0x7f, 0xff, 0x00, 0x1c, 0x00, 0x7f, 0xff, 0x00, 0x1c, 0x00, 0x7f, 0xff, 0x00, 0x1c, 0x00, 0x7f, 
  0xff, 0x00, 0x1c, 0x00, 0x7f, 0xff, 0x00, 0x1f, 0xf0, 0x7f, 0xff, 0x00, 0x1f, 0xf0, 0x7f, 0xff, 
  0x00, 0x18, 0x30, 0x7f, 0xff, 0x00, 0x18, 0x30, 0x7f, 0xff, 0x00, 0x18, 0x30, 0x7f, 0xff, 0x00, 
  0x18, 0x30, 0x7f, 0xff, 0x00, 0x18, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x1c, 0x00, 0x7f, 0xff, 0x00, 0x1c, 0x00, 
  0x7f, 0xff, 0x00, 0x1c, 0x00, 0x7f, 0xff, 0x00, 0x1c, 0x00, 0x7f, 0xff, 0x00, 0x1c, 0x00, 0x7f, 
  0xff, 0x00, 0x1c, 0x00, 0x7f, 0xff, 0x00, 0x1c, 0x00, 0x7f, 0xff, 0x00, 0x1c, 0x00, 0x7f, 0xff, 
  0x00, 0x1c, 0x00, 0x7f, 0xff, 0x00, 0x1c, 0x00, 0x7f, 0xff, 0x00, 0x1c, 0x00, 0x7f, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};


void setup()   {

  display.begin();  // initialisation de l'afficheur
  display.clearDisplay();   // ça efface à la fois le buffer et l'écran
}


void loop() {
  display.drawBitmap(0, 0, myBitmap, 40, 40, WHITE);

  display.setCursor(60, 30);  // coordonnées du point de départ du texte
  display.setTextColor(WHITE);
  display.setTextSize(2);  // taille par défaut
  display.println("Thereminimin");

  display.display();
  delay(2000);
  display.clearDisplay();

}
