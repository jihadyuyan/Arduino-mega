#include <Arduino.h>
#include <Sensor.h>
#include <FuzzyLogic.h>
#include <TFTLcd.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> 
#endif

#define PIN        42
#define NUMPIXELS 8 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 

TFTLcd TFT;

SoftwareSerial SendToESP(19,18);
// /********************** Firebase configuration*********************/
// const char *api_key = "AIzaSyC9Ms27sIya3-n0YC--HWss-ACAcM-PZIM";
// const char *user_email = "test@test.com";
// const char *user_password = "12345678";
// const char *firebase_project_id = "bismillah-sempro";

// /********************** WiFi configuration ************************/
// const char *ssid = "vivo 1719";
// const char *password = "onlyme1234";

/********************** Sensor configuration **********************/
// pin for mq4 sensor is GPIO25
// pin for mq135 sensor is GPIO26

FuzzyLogic *fuzzyLogic;
// Network *network;
Sensor *sensor;

// void network_init();
void sensor_init();
void fuzzy_logic_init();

void setup()
{
  Serial.begin(9600);
  SendToESP.begin(9600);
  TFT.init();
  pixels.begin();

  // network_init();
  sensor_init();
  fuzzy_logic_init();

}

void loop()
{
  // put your main code here, to run repeatedly:
  pixels.clear(); 
  float nh3 = sensor->get_MQ135();
  float ch4 = sensor->get_MQ4();
  float co = sensor->get_MQ7();
  String statusKadarGas = "";
  Serial.print("MQ135: ");
  Serial.println(nh3);
  Serial.print("MQ4: ");
  Serial.println(ch4);
  Serial.print("MQ7: ");
  Serial.println(co);
  float nilaiFuzzy = fuzzyLogic->fuzzy_compute(nh3, ch4, co);
  if (nilaiFuzzy <= 50){
    statusKadarGas = "Normal"; 
    for (int i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();  
    delay(100);
  }
  }
  else if (nilaiFuzzy > 50 && nilaiFuzzy >= 100){
    statusKadarGas = "Bahaya";
    for (int i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
  }}
  else{
    statusKadarGas = "Sangat Bahaya";
    for (int i = 0; i < NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
  }}
  
  String data = (String)nh3 + "," + (String)ch4  + "," + (String)co  + "," + (String)statusKadarGas;
  TFT.showmsgXY(nh3,ch4,co,statusKadarGas.c_str());
  // TFT.showmsgXY(10, 200, 2, &FreeSans9pt7b, data.c_str());
  SendToESP.print(data);
  Serial.println(data);

  delay(5000);
}


void sensor_init()
{
  sensor = new Sensor();
  sensor->init_MQ4();
  sensor->init_MQ135();
  sensor->init_MQ7();
}

void fuzzy_logic_init()
{
  fuzzyLogic = new FuzzyLogic();
  fuzzyLogic->fuzzy_init();
}
