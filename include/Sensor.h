#ifndef Sensor_H_
#define Sensor_H_

#include <MQUnifiedsensor.h>

class Sensor
{
public:
    Sensor();
    void init_MQ4();
    void init_MQ135();
    void init_MQ7();
    float get_MQ4();
    float get_MQ135();
    float get_MQ7();
};

#endif // !Sensor_H_