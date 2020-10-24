#include <iostream>
#include <string>
#include "include/controller.h"
#include "include/controlunit.h"
#include "include/doorssensors.h"
#include "include/sensors.h"
#include "include/worrymode.h"

using namespace std;

int main()
{
    Controller bibelot;
    ControlUnit unit(bibelot.getPositionOfStartButtom());
    if (!unit.getSystemActivity()) return 0;
    DoorsSensors *doors = new DoorsSensors();
    unit.setCheckDoorsSensors(doors->getDriverDoor(),
                              doors->getFrontPassengerDoor(),
                              doors->getBackLeftPassengerDoor(),
                              doors->getBackRightPassengerDoor(),
                              doors->getBaggageDoor(),
                              doors->getHoodDoor());
    if (unit.getCheckDoorsSensors())
    {
        unit.setArrayOfWorkedDoorsSensors(doors->getDriverDoor(),
                                          doors->getFrontPassengerDoor(),
                                          doors->getBackLeftPassengerDoor(),
                                          doors->getBackRightPassengerDoor(),
                                          doors->getBaggageDoor(),
                                          doors->getHoodDoor());
        std::string *ledColor = new std::string("Желтый");
        int *soundRepeat = new int(3);
        bibelot.setAlarmNotice(*ledColor, *soundRepeat);
        delete ledColor, delete soundRepeat;
        bibelot.saveArrayOfWorkedDoorsSensors(unit.getArrayOfWorkedDoorsSensors(),
                                              unit.getCountOfWorkedDoorsSensors());
        return 0;
    }
    delete doors;

    int *vehicleNotice = new int(2);
    unit.vehicleNotice(*vehicleNotice);
    delete vehicleNotice;

    unit.setCipherCode();
    bibelot.setCipherCode(unit.getCipherCode());

    while (true)
    {
        Sensors *sensors = new Sensors();
        WorryMode *alarm = new WorryMode(sensors->getPunchSensorReport(),
                                         sensors->getVolumeSensorReport(),
                                         sensors->getInclineSensorReport(),
                                         sensors->getContactSensorReport());
        WorryMode *warning = new WorryMode(sensors->getPunchSensorReport(),
                                           sensors->getVolumeSensorReport(),
                                           sensors->getInclineSensorReport(),
                                           sensors->getContactSensorReport());
        int *alarmMinPunch = new int(3);
        int *alarmMinVolume = new int(3);
        int *alarmMinIncline = new int(5);
        bool *alarmMinContact = new bool(true);

        int *warningMinPunch = new int(1);
        int *warningMinVolume = new int(1);
        int *warningMinIncline = new int(1);
        bool *warningMinContact = new bool(true);

        if (alarm->checkWorryMode(*alarmMinPunch,
                              *alarmMinVolume,
                              *alarmMinIncline,
                              *alarmMinContact))
        {
            delete alarmMinPunch; delete alarmMinVolume;
            delete alarmMinIncline; delete alarmMinContact;

            bool *blockStarter = new bool(1);
            bool *blockEngine = new bool(1);

            alarm->setCarLock(*blockStarter,
                              *blockEngine);

            int *vehicleNotice = new int(10);
            unit.vehicleNotice(*vehicleNotice);
            delete vehicleNotice;

            std::string *ledColor = new std::string("Красный");
            int *soundRepeat = new int(10);
            bibelot.setAlarmNotice(*ledColor, *soundRepeat);
            delete ledColor, delete soundRepeat;

            bibelot.saveWorryModeNotice(alarm->getWhichSensorWasTriggered(),
                                        alarm->getBlockStarter(),
                                        alarm->getBlockEngine());
            return 0;
        } else if (warning->checkWorryMode(*warningMinPunch,
                                           *warningMinVolume,
                                           *warningMinIncline,
                                           *warningMinContact))
        {
            delete warningMinPunch; delete warningMinVolume;
            delete  warningMinIncline; delete warningMinContact;
            bool *blockStarter = new bool(false);
            bool *blockEngine = new bool(false);

            alarm->setCarLock(*blockStarter,
                              *blockEngine);

            int *vehicleNotice = new int(3);
            unit.vehicleNotice(*vehicleNotice);
            delete vehicleNotice;

            std::string *ledColor = new std::string("Желтый");
            int *soundRepeat = new int(3);
            bibelot.setAlarmNotice(*ledColor, *soundRepeat);
            delete ledColor, delete soundRepeat;

            bibelot.saveWorryModeNotice(alarm->getWhichSensorWasTriggered(),
                                        alarm->getBlockStarter(),
                                        alarm->getBlockEngine());

        } else
        {
            bibelot.setDoorOpener();
            unit.setDoorOpener(bibelot.getDoorOpener());
            if (unit.getCipherCode() == bibelot.getCipherCode() && unit.getDoorOpener())
            {
                int *vehicleNotice = new int(2);
                unit.vehicleNotice(*vehicleNotice);
                delete vehicleNotice;
                delete alarm;
                delete warning;
                break;
            }
        }
    }
    if (unit.checkPinCode())
    {
        std::cout << "Автомобиль снят с сигнализации и готов к использованию.";
        return 0;
    }
    bool *blockStarter = new bool(1);
    std::string *ledColor = new std::string("Желтый");
    int *soundRepeat = new int(3);
    bibelot.setAlarmNotice(*ledColor, *soundRepeat);
    delete ledColor, delete soundRepeat;

    unit.setAuthorizationCode();
    bibelot.saveGuardMode(*blockStarter ,unit.getAuthirizationCode());
    delete blockStarter;
    if (unit.checkAuthirizationCode())
    {
        std::cout << "Автомобиль снят с сигнализации и готов к использованию.";
        return 0;
    } else
    {
        std::string *ledColor = new std::string("Красный");
        int *soundRepeat = new int(10);
        bibelot.setAlarmNotice(*ledColor, *soundRepeat);
        delete ledColor, delete soundRepeat;
        bibelot.saveBlockedAllCar();
        int *vehicleNotice = new int(10);
        unit.vehicleNotice(*vehicleNotice);
        delete vehicleNotice;
    }
    return 0;
}
