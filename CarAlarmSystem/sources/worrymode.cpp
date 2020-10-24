#include "../include/worrymode.h"

WorryMode::WorryMode(int punchSensor,
                     int volumeSensor,
                     int inclineSensor,
                     bool contactSensor)
{
    WorryMode::reportPunchSensor = punchSensor;
    WorryMode::reportVolumeSensor = volumeSensor;
    WorryMode::reportInclineSensor = inclineSensor;
    WorryMode::reportContactSensor = contactSensor;
}

bool WorryMode::checkWorryMode(int minPunch, int minVolume, int minIncline, bool contact)
{
    if (reportPunchSensor >= minPunch || reportVolumeSensor >= minVolume ||
        reportInclineSensor >= minIncline || reportContactSensor == contact)
        return true;
    else
        return  false;
}

std::string WorryMode::getWhichSensorWasTriggered()
{
    if (reportPunchSensor)
        return "Сработал датчик удара";
    else if (reportVolumeSensor)
        return  "Сработал ультразвуковой датчик";
    else if (reportInclineSensor)
        return "Сработал датчик наклона";
    else
        return "Сработал контактный датчик";
}

void WorryMode::setCarLock(bool blockStarter, bool blockEngine)
{
    WorryMode::starter = blockStarter;
    WorryMode::engine = blockEngine;
}

bool WorryMode::getBlockStarter()
{
    return starter;
}

bool WorryMode::getBlockEngine()
{
    return engine;
}
