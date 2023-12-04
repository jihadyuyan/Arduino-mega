#include <Arduino.h>
#include <Sensor.h>
#include <FuzzyLogic.h>
#include <Wire.h>

FuzzyLogic *fuzzyLogic;
Sensor *sensor;

void sensor_init();
void fuzzy_logic_init();

void setup()
{
  Serial.begin(115200);
  sensor_init();
  fuzzy_logic_init();
}

void loop()
{

  float nh3 = sensor->get_MQ135();
  float ch4 = sensor->get_MQ4();
  float co = sensor->get_MQ7();
  Serial.print("MQ135: ");
  Serial.println(nh3);
  Serial.print("MQ4: ");
  Serial.println(ch4);
  Serial.print("MQ7: ");
  Serial.println(co);
  fuzzyLogic->fuzzy_compute(nh3, ch4, co);

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