#ifndef TFTLcd_H_
#define TFTLcd_H_

#include "Adafruit_GFX.h"
#include "MCUFRIEND_kbv.h"

#define CS_PIN 2
#define RS_PIN 32
#define WR_PIN 33
#define RD_PIN 4
#define RST_PIN 15


#include "Fonts/FreeSans9pt7b.h"
#include "Fonts/FreeSans12pt7b.h"
#include "Fonts/FreeSerif12pt7b.h"
#include "FreeDefaultFonts.h"

#define PI 3.1415926535897932384626433832795
#define WHITE 0xFFFF


class TFTLcd
{
public:
    TFTLcd();
    void init();
    void showmsgXY(float nh3, float ch4, float co,  const char *kondisi);
};

#endif // !TFTLcd_H_