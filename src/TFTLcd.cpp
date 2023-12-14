#include <TFTLcd.h>


MCUFRIEND_kbv tftlcd(CS_PIN, RS_PIN, WR_PIN, RD_PIN, RST_PIN);

int col[8];

static TFTLcd *instance = NULL;

TFTLcd::TFTLcd()
{
    instance = this;
}

void TFTLcd::init() {
  tftlcd.reset();
  Serial.begin(9600);
  uint16_t ID = tftlcd.readID();
  tftlcd.begin(ID);
  tftlcd.setRotation(1);
  // tftlcd.invertDisplay(true);
  tftlcd.fillScreen(0xffff);
//   showmsgXY(100, 200, 2, &FreeSans9pt7b, "M. Jihad Yuyan");
  col[0] = tftlcd.color565(155, 0, 50);
  col[1] = tftlcd.color565(170, 30, 80);
  col[2] = tftlcd.color565(195, 60, 110);
  col[3] = tftlcd.color565(215, 90, 140);
  col[4] = tftlcd.color565(230, 100, 170);
  col[5] = tftlcd.color565(250, 0, 0);
  col[6] = tftlcd.color565(0, 255, 0);
  col[7] = tftlcd.color565(0, 0, 225);

}

void TFTLcd::showmsgXY(float nh3, float ch4, float co, const char *kondisi)
{
//   int16_t x1, y1;
//   uint16_t wid, ht;
  tftlcd.setFont(&FreeSans9pt7b);
  tftlcd.fillScreen(0xffff);
  tftlcd.setCursor(10, 50);
  tftlcd.setTextColor(0x0000);
  tftlcd.setTextSize(1.8);
  tftlcd.print("Gas Amonia = " + (String)nh3);
  tftlcd.setCursor(10, 100);
  tftlcd.setTextColor(0x0000);
  tftlcd.print("Gas Metana = " + (String)ch4);
  tftlcd.setCursor(10, 150);
  tftlcd.setTextColor(0x0000);
  tftlcd.print("Gas Karbon Monoksida = " + (String)co);
  tftlcd.setCursor(10, 200);
  tftlcd.setTextColor(0x0000);
  tftlcd.print("Kondisi = " + (String)kondisi);
}