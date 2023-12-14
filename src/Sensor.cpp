#include "Sensor.h"

// #define board "ESP32"
#define board "Arduino Mega"
#define voltage 5
#define voltage_Resolution 5
#define ADC_Bit_Resolution 10
#define MQ4_TYPE "MQ-4"
#define MQ135_TYPE "MQ-135"
#define MQ7_TYPE "MQ-7"
#define RatioMQ4CleanAir 4.4
#define RatioMQ135CleanAir 3.6
#define RatioMQ7CleanAir 27.5
#define PIN_MQ4 A13
#define PIN_MQ135 A14
#define PIN_MQ7 A15

unsigned long oldTime = 0;

MQUnifiedsensor MQ135(board, voltage, ADC_Bit_Resolution, PIN_MQ135, MQ135_TYPE);
MQUnifiedsensor MQ4(board, voltage, ADC_Bit_Resolution, PIN_MQ4, MQ4_TYPE);
MQUnifiedsensor MQ7(board, voltage, ADC_Bit_Resolution, PIN_MQ7, MQ7_TYPE);
// MQ7 mq7(PIN_MQ7, voltage_Resolution);

static Sensor *instance = NULL;

Sensor::Sensor()
{

    instance = this;
}

void Sensor::init_MQ4()
{

    MQ4.setRegressionMethod(1); // Use Least Squares Method for calculating slope and y-intercept.
    MQ4.setA(1012.7);           // Configure the ecuation to get CH4 concentration.
    MQ4.setB(-2.786);           // Configure the ecuation to get CH4 concentration.

    MQ4.init(); // Initialize the sensor.

    Serial.print("Calibrating please wait.");
    float calcR0 = 0;
    for (int i = 1; i <= 10; i++)
    {
        MQ4.update(); // Update data, the arduino will read the voltage from the analog pin
        calcR0 += MQ4.calibrate(RatioMQ4CleanAir);
        Serial.print(".");
    }
    MQ4.setR0(calcR0 / 10);
    Serial.println("  done!.");

    if (isinf(calcR0))
    {
        Serial.println("Warning: Conection issue, R0 is infinite (Open circuit detected) please check your wiring and supply");
        while (1)
            ;
    }
    if (calcR0 == 0)
    {
        Serial.println("Warning: Conection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply");
        while (1)
            ;
    }
    /*****************************  MQ CAlibration ********************************************/
    MQ4.serialDebug(true);
}

void Sensor::init_MQ135()
{

    MQ135.setRegressionMethod(1); // Use Least Squares Method for calculating slope and y-intercept.
    MQ135.setA(102.2);            // Configure the ecuation to get NH4 concentration.
    MQ135.setB(-2.473);           // Configure the ecuation to get NH4 concentration.

    MQ135.init(); // Initialize the sensor.

    Serial.print("Calibrating please wait.");
    float calcR0 = 0;
    for (int i = 1; i <= 10; i++)
    {
        MQ135.update(); // Update data, the arduino will read the voltage from the analog pin
        calcR0 += MQ135.calibrate(RatioMQ135CleanAir);
        Serial.print(".");
    }
    MQ135.setR0(calcR0 / 10);
    Serial.println("  done!.");

    if (isinf(calcR0))
    {
        Serial.println("Warning: Conection issue, R0 is infinite (Open circuit detected) please check your wiring and supply");
        while (1)
            ;
    }
    if (calcR0 == 0)
    {
        Serial.println("Warning: Conection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply");
        while (1)
            ;
    }
    /*****************************  MQ CAlibration ********************************************/
    MQ135.serialDebug(true);
}

// void Sensor::init_MQ7()
// {
//     MQ7.calibrate();
// }
void Sensor::init_MQ7(){
    MQ7.setRegressionMethod(1); // Use Least Squares Method for calculating slope and y-intercept.
    MQ7.setA(99.042);            // Configure the ecuation to get NH4 concentration.
    MQ7.setB(-1.518);           // Configure the ecuation to get NH4 concentration.

    MQ7.init(); // Initialize the sensor.

    Serial.print("Calibrating please wait.");
    float calcR0 = 0;
    for (int i = 1; i <= 10; i++)
    {
        MQ7.update(); // Update data, the arduino will read the voltage from the analog pin
        calcR0 += MQ7.calibrate(RatioMQ7CleanAir);
        Serial.print(".");
    }
    MQ7.setR0(calcR0 / 10);
    Serial.println("  done!.");

    if (isinf(calcR0))
    {
        Serial.println("Warning: Conection issue, R0 is infinite (Open circuit detected) please check your wiring and supply");
        while (1)
            ;
    }
    if (calcR0 == 0)
    {
        Serial.println("Warning: Conection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply");
        while (1)
            ;
    }
    /*****************************  MQ CAlibration ********************************************/
    MQ7.serialDebug(true);
}

float Sensor::get_MQ4()
{
    MQ4.update();
    return MQ4.readSensor();
}

float Sensor::get_MQ135()
{
    MQ135.update();
    return MQ135.readSensor();
}

// float Sensor::get_MQ7()
// {
//     return MQ7.readPpm();
// }
float Sensor::get_MQ7()
{
    MQ7.update();
    return MQ7.readSensor();
}