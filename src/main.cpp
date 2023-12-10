#include <Arduino.h>
#include <Sensor.h>
#include <FuzzyLogic.h>
#include <Wire.h>
#include <TFT_eSPI.h>

#include "Adafruit_GFX.h"
#include "MCUFRIEND_kbv.h"

#include "Fonts/FreeSans9pt7b.h"

#define LCD_CS 2
#define LCD_RS 32
#define LCD_WR 33
#define LCD_RD 4
#define LCD_RST 15

MCUFRIEND_kbv tft(LCD_CS, LCD_RS, LCD_WR, LCD_RD, LCD_RST);
FuzzyLogic *fuzzyLogic;
Sensor *sensor;

void sensor_init();
void fuzzy_logic_init();
void show_lcd(int x, int y, String sz, const GFXfont *f, const char *message);

void setup()
{
  Serial.begin(115200);
  sensor_init();
  fuzzy_logic_init();

  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(0xffff);
  tft.invertDisplay(true);
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
  float output = fuzzyLogic->fuzzy_compute(nh3, ch4, co);

  delay(5000);
}

void show_lcd(int x, int y, int sz, const GFXfont *f, const char *message)
{
  tft.setFont(f);
  tft.setCursor(x, y);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(sz);
  tft.println(message);
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