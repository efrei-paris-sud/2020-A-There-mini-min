#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <HCSR04.h>

#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" //UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E" //Sender
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E" //Receiver

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
float currVol = 0;
int volume = 0;
float currFreq = 0;
int frequency = 0;
const int readPin = 32; // Use GPIO number. See ESP32 board pinouts

//The two ultrasound sensors
UltraSonicDistanceSensor distanceSensorVolume(34, 35); //(Trig, Echo)
UltraSonicDistanceSensor distanceSensorFrequency(32, 33); //(Trig, Echo)

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

class MyCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic)
  {
    std::string rxValue = pCharacteristic->getValue();

    if (rxValue.length() > 0)
    {
    
      Serial.println("*********");
      Serial.print("Received Value: ");
      for (int i = 0; i < rxValue.length(); i++)
      {
        Serial.print(rxValue[i]);
      }
      Serial.println();
      Serial.println("*********");
    }
  }
};

int convertFreq(float currFreq) {
  if(0 <= currFreq < 5) {
    return 0;
  } else if(5 <= currFreq < 10) {
    return 1;
  } else if(10 <= currFreq < 15) {
    return 2;
  } else if(15 <= currFreq < 20) {
    return 3;
  } else if(20 <= currFreq < 25) {
    return 4;
  } else if(25 <= currFreq < 30) {
    return 5;
  } else if(30 <= currFreq < 35) {
    return 6;
  } else {
    return 7;
  }
}

void setup() {
  Serial.begin(115200);
  
  //BLE Device
  BLEDevice::init("ESP32 UART testing");

  //BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  //BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  //BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID_TX,
      BLECharacteristic::PROPERTY_NOTIFY);

  pCharacteristic->addDescriptor(new BLE2902());

  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID_RX,
      BLECharacteristic::PROPERTY_WRITE);

  pCharacteristic->setCallbacks(new MyCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");
}

void loop() {
  currVol = distanceSensorVolume.measureDistanceCm() - 5;
  currFreq = distanceSensorFrequency.measureDistanceCm() - 5;

  //Convert the volume value to 0-100
  volume = (int) (currVol * 2.5);
  
  //Trunkate the values
  (volume < 0) ? 0 : volume;
  (currFreq < 0) ? 0 : currFreq;
  (volume > 100) ? 100 : volume;
  (currFreq > 40) ? 40 : currFreq;

  //Convert the frequency to its octave
  frequency = convertFreq(currFreq);
    
  if(deviceConnected) {
    char txVolume[3];
    itoa(volume, txVolume, 10);
    pCharacteristic->setValue(txVolume);
    pCharacteristic->notify();
    Serial.println("Value sent : " + txVolume);
  }
  
  delay(1000);
}
