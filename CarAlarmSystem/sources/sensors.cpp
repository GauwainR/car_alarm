#include "../include/sensors.h"

Sensors::Sensors()
{
    bool *contactSensorData = new bool;
    int *inclineSensorData = new int;
    int *punchSensorData = new int;
    int *volumeSensorData = new int;

    std::cout << "Данные контактного датчика "; std::cin >> *contactSensorData;
    std::cout << "Данные ультразвукого датчик "; std::cin >> *volumeSensorData;
    std::cout << "Данные датчика наклона "; std::cin >> *inclineSensorData;
    std::cout << "Данные датчика удара? "; std::cin >> *punchSensorData;

    Sensors::reportPunchSensor = *punchSensorData;
    Sensors::reportInclineSensor = *inclineSensorData;
    Sensors::reportVolumeSensor = *volumeSensorData;
    Sensors::reportContactSensor = *contactSensorData;
}

int Sensors::getPunchSensorReport()
{
    return reportPunchSensor;
}

int Sensors::getVolumeSensorReport()
{
    return reportVolumeSensor;
}

int Sensors::getInclineSensorReport()
{
    return  reportInclineSensor;
}

bool Sensors::getContactSensorReport()
{
    return reportContactSensor;
}
