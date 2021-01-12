#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <HCSR04.h>


//#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" //UART service UUID
//#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E" //Receiver
//#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E" //Sender

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
float currVol = 0;
int volume = 0;
float currFreq = 0;
int frequency = 0;
const int readPin = 32; // Use GPIO number. See ESP32 board pinouts

//debug
int value = 0;
bool oldDeviceConnected = false;
BLEServer* pServer = NULL;

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
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  //BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  //BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );

  pCharacteristic->addDescriptor(new BLE2902());

  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Waiting a client connection to notify...");

  //Do it with the buzzer
  ledcSetup(0, 2000, 8); //Channel, Freq, Resolution
  ledcAttachPin(25, 0); //Pin, Channel
}

void loop() {
 
  // notify changed value
    if (deviceConnected) {
        pCharacteristic->setValue(value);
        Serial.println(value);
        pCharacteristic->notify();
        value++;
        delay(1000); // bluetooth stack will go into congestion, if too many packets are sent, in 6 hours test i was able to go as low as 3ms
    }

    // disconnecting
    if (!deviceConnected && oldDeviceConnected) {
        delay(500); // give the bluetooth stack the chance to get things ready
        pServer->startAdvertising(); // restart advertising
        Serial.println("start advertising");
        oldDeviceConnected = deviceConnected;
    }
    // connecting
    if (deviceConnected && !oldDeviceConnected) {
        // do stuff here on connecting
        oldDeviceConnected = deviceConnected;
    }
   
  currVol = distanceSensorVolume.measureDistanceCm() - 5;
  currFreq = distanceSensorFrequency.measureDistanceCm() - 5;

  //Convert the volume value to 0-100
  volume = (int) (currVol * 2.5);
  
  //Trunkate the values
  (volume < 0) ? 0 : volume;
  (currFreq < 0) ? 0 : currFreq;
  (volume > 100) ? 100 : volume;
  (currFreq > 40) ? 40 : currFreq;

  frequency = (int) currFreq*100;
  Serial.println(frequency);

  //For the buzzer
  ledcWriteTone(0, currFreq);
    
  if(deviceConnected) {
    char txVolume[3];
    itoa(volume, txVolume, 10);
    pCharacteristic->setValue("cc");
    pCharacteristic->notify();
    Serial.println("Value sent : cc");
  }
  
}
