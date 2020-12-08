#include <WiFi.h>
//setup OLED
void setup(){
  display.begin(); // Instead of Serial.begin(9600)
  display.setTTYMode(true); // This set the TTY mode
  
}
const char* ssid = "nouilles";
const char* password = "kkkkkkkk";

void scanNetworks() {
 
  int numberOfNetworks = WiFi.scanNetworks();
 
  display.printf("Number of networks found: %d\n",numberOfNetworks);
  
 
  for (int i = 0; i < numberOfNetworks; i++) {
 
    display.print("Network name: ");
    display.println(WiFi.SSID(i));
 
    display.print("Signal strength: ");
    display.println(WiFi.RSSI(i));
 
    display.print("MAC address: ");
    display.println(WiFi.BSSIDstr(i));
 
    //display.print("Encryption type: ");
    //display.print(WiFi.encryptionType(i)); the type is  wifi_auth_mode_t
   
    display.println("-----------------------");
 
  }
}

void connectToNetwork() {
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    display.println("Establishing connection to WiFi..");
  }
  
  display.println("Connected to network");
}

void printWiFiInfo() {
  display.println(WiFi.macAddress());
  display.println(WiFi.localIP());
}

void disconnect(){
  WiFi.disconnect(true);
  display.print("Disconnected! ip:");
  display.println(WiFi.localIP());
}
