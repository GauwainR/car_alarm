#include "../include/launcher.h"

int launcher()
{
    Controller bibelot;
        if (!bibelot.getPositionOfStartButtom()) return 0;
        DoorsSensors *doors = new DoorsSensors();

        if (doors->getCheckDoorsSensors())
        {
            doors->setArrayOfWorkedDoorsSensors();
            std::string *ledColor = new std::string("Желтый");
            int *soundRepeat = new int(3);
            bibelot.setAlarmNotice(*ledColor, *soundRepeat);
            delete ledColor, delete soundRepeat;
            bibelot.saveArrayOfWorkedDoorsSensors(doors->getArrayOfWorkedDoorsSensors(),
                                                  doors->getCountOfWorkedDoorsSensors());
            return 0;
        }
        delete doors;

        int *notice = new int(2);
        vehicleNotice(*notice);
        delete notice;

        int *cipherCode = new int(rand()%(9999-1000+1));
        int *pinCode = new int(4816);
        bibelot.setCipherCode(*cipherCode, *pinCode);
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

                int *notice = new int(10);
                vehicleNotice(*notice);
                delete notice;

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

                int *notice = new int(3);
                vehicleNotice(*notice);
                delete notice;

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
                if (*cipherCode == bibelot.getCipherCode() && bibelot.getDoorOpener())
                {
                    int *notice = new int(2);
                    vehicleNotice(*notice);
                    delete notice;
                    delete alarm;
                    delete warning;
                    break;
                }
            }
        }
        if (checkPinCode(*pinCode))
        {
            std::cout << "Автомобиль снят с сигнализации и готов к использованию.";
            return 0;
        }
        delete pinCode;
        bool *blockStarter = new bool(1);
        std::string *ledColor = new std::string("Желтый");
        int *soundRepeat = new int(3);
        bibelot.setAlarmNotice(*ledColor, *soundRepeat);
        delete ledColor, delete soundRepeat;
        int *authorizationCode = new int(rand()%(999999-100000+1));
        bibelot.saveGuardMode(*blockStarter ,*authorizationCode);
        delete blockStarter;
        if (checkAuthirizationCode(*authorizationCode))
        {
            delete authorizationCode;
            std::cout << "Автомобиль снят с сигнализации и готов к использованию.";
            return 0;
        } else
        {
            std::string *ledColor = new std::string("Красный");
            int *soundRepeat = new int(10);
            bibelot.setAlarmNotice(*ledColor, *soundRepeat);
            delete ledColor, delete soundRepeat;
            bibelot.saveBlockedAllCar();
            int *notice = new int(10);
            vehicleNotice(*notice);
            delete notice;
        }
        return 0;
}
