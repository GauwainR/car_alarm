#include <iostream>

#ifndef SENSORS_H
#define SENSORS_H


class Sensors
{
public:
    Sensors();
    int getPunchSensorReport();
    int getInclineSensorReport();
    int getVolumeSensorReport();
    bool getContactSensorReport();
private:
    int reportPunchSensor;
    int reportInclineSensor;
    int reportVolumeSensor;
    bool reportContactSensor;
};

#endif // SENSORS_H
