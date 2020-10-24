#include <string>

#ifndef WORRYMODE_H
#define WORRYMODE_H


class WorryMode
{
public:
    WorryMode(int punchSensor,
              int volumeSensor,
              int inclineSensor,
              bool contactSensor);

    bool checkWorryMode(int minPunch,
                        int minVolume,
                        int minIncline,
                        bool contact);
    std::string getWhichSensorWasTriggered();
    void setCarLock(bool blockStarter, bool blockEngine);
    bool getBlockStarter();
    bool getBlockEngine();
private:
    int reportPunchSensor;
    int reportInclineSensor;
    int reportVolumeSensor;
    bool reportContactSensor;
    bool starter;
    bool engine;
};

#endif // WORRYMODE_H
