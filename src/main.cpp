#include <Arduino.h>
#include <Sensor.h>
#include <FuzzyLogic.h>

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
  Serial.begin(115200);
  // network_init();
  sensor_init();
  fuzzy_logic_init();
}

void loop()
{
  // put your main code here, to run repeatedly:

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

// void network_init()
// {
//   network = new Network();
//   network->init_wifi(ssid, password);
//   network->init_firebase(api_key, user_email, user_password, firebase_project_id);
// }

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
// =======
// Include the library
// #include <MQUnifiedsensor.h>
/************************Hardware Related Macros************************************/
// #define Board ("ESP-32") // Wemos ESP-32 or other board, whatever have ESP32 core.
// #define Pin (25)         // IO25 for your ESP32 WeMos Board, pinout here: https://i.pinimg.com/originals/66/9a/61/669a618d9435c702f4b67e12c40a11b8.jpg
/***********************Software Related Macros************************************/
// #define Type ("MQ-7")            // MQ3 or other MQ Sensor, if change this verify your a and b values.
// #define Voltage_Resolution (3.3) // 3V3 <- IMPORTANT. Source: https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/
// #define ADC_Bit_Resolution (12)  // ESP-32 bit resolution. Source: https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/
// #define RatioMQ7CleanAir (27.5)  // Ratio of your sensor, for this example an MQ-3
/*****************************Globals***********************************************/
// Declare Sensor
// MQUnifiedsensor MQ7(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);
// unsigned long oldTime = 0;

// void setup()
// {
// Init the serial port communication - to debug the library
// Serial.begin(9600); // Init serial port

// Set math model to calculate the PPM concentration and the value of constants
// MQ7.setRegressionMethod(1); //_PPM =  a*ratio^b
// MQ7.setA(99.042);
// MQ7.setB(-1.518); // Configure the equation to calculate CO concentration value

/*
  Exponential regression:
GAS     | a      | b
H2      | 69.014  | -1.374
LPG     | 700000000 | -7.703
CH4     | 60000000000000 | -10.54
CO      | 99.042 | -1.518
Alcohol | 40000000000000000 | -12.35
*/

/*****************************  MQ Init ********************************************/
// Remarks: Configure the pin of arduino as input.
/************************************************************************************/
// MQ7.init();
/*
  //If the RL value is different from 10K please assign your RL value with the following method:
  MQ7.setRL(10);
*/
/*****************************  MQ CAlibration ********************************************/
// Explanation:
// In this routine the sensor will measure the resistance of the sensor supposedly before being pre-heated
// and on clean air (Calibration conditions), setting up R0 value.
// We recomend executing this routine only on setup in laboratory conditions.
// This routine does not need to be executed on each restart, you can load your R0 value from eeprom.
// Acknowledgements: https://jayconsystems.com/blog/understanding-a-gas-sensor
//   Serial.print("Calibrating please wait.");
//   float calcR0 = 0;
//   for (int i = 1; i <= 10; i++)
//   {
//     MQ7.update(); // Update data, the arduino will read the voltage from the analog pin
//     calcR0 += MQ7.calibrate(RatioMQ7CleanAir);
//     Serial.print(".");
//   }
//   MQ7.setR0(calcR0 / 10);
//   Serial.println("  done!.");

//   if (isinf(calcR0))
//   {
//     Serial.println("Warning: Conection issue, R0 is infinite (Open circuit detected) please check your wiring and supply");
//     while (1)
//       ;
//   }
//   if (calcR0 == 0)
//   {
//     Serial.println("Warning: Conection issue found, R0 is zero (Analog pin shorts to ground) please check your wiring and supply");
//     while (1)
//       ;
//   }
//   /*****************************  MQ CAlibration ********************************************/
//   MQ7.serialDebug(true);
// }

// void loop()
// {
//   MQ7.update();                     // Update data, the arduino will read the voltage from the analog pin
//   MQ7.readSensor();                 // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
//   Serial.println(MQ7.readSensor()); // Prints all values on serial port
//   delay(500);                       // Sampling frequency
// }

/*
  MQUnifiedsensor Library - reading an MQ4

  Demonstrates the use a MQ4 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez

  Added example
  modified 23 May 2019
  by Miguel Califa

  Updated library usage
  modified 26 March 2020
  by Miguel Califa

  Wiring:
  https://github.com/miguel5612/MQSensorsLib_Docs/blob/master/static/img/MQ_Arduino.PNG
  Please make sure arduino A0 pin represents the analog input configured on #define pin

 This example code is in the public domain.

*/

// Include the library
#include <MQUnifiedsensor.h>
/************************Hardware Related Macros************************************/
#define Board ("ESP-32")
#define Pin (25) // Analog input 4 of your arduino
/***********************Software Related Macros************************************/
#define Type ("MQ-4") // MQ4
#define Voltage_Resolution (3.3)
#define ADC_Bit_Resolution (12) // For arduino UNO/MEGA/NANO
#define RatioMQ4CleanAir (4.4)  // RS / R0 = 60 ppm
/*****************************Globals***********************************************/
// Declare Sensor
MQUnifiedsensor MQ4(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);

void setup()
{
  // Init the serial port communication - to debug the library
  Serial.begin(9600); // Init serial port

  // Set math model to calculate the PPM concentration and the value of constants
  MQ4.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ4.setA(1012.7);
  MQ4.setB(-2.786); // Configure the equation to to calculate CH4 concentration
  /*
    Exponential regression:
  Gas    | a      | b
  LPG    | 3811.9 | -3.113
  CH4    | 1012.7 | -2.786
  CO     | 200000000000000 | -19.05
  Alcohol| 60000000000 | -14.01
  smoke  | 30000000 | -8.308
  */

  /*****************************  MQ Init ********************************************/
  // Remarks: Configure the pin of arduino as input.
  /************************************************************************************/
  MQ4.init();
  /*
    //If the RL value is different from 10K please assign your RL value with the following method:
    MQ4.setRL(10);
  */
  /*****************************  MQ CAlibration ********************************************/
  // Explanation:
  // In this routine the sensor will measure the resistance of the sensor supposedly before being pre-heated
  // and on clean air (Calibration conditions), setting up R0 value.
  // We recomend executing this routine only on setup in laboratory conditions.
  // This routine does not need to be executed on each restart, you can load your R0 value from eeprom.
  // Acknowledgements: https://jayconsystems.com/blog/understanding-a-gas-sensor
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

void loop()
{
  MQ4.update();      // Update data, the arduino will read the voltage from the analog pin
  MQ4.readSensor();  // Sensor will read PPM concentration using the model, a and b values set previously or from the setup
  MQ4.serialDebug(); // Will print the table on the serial port
  delay(200);        // Sampling frequency

}