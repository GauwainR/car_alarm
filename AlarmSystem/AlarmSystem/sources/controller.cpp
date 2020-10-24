#include "../include/controller.h"

Controller::Controller()
{
    std::cout << "Поставить автомобиль на сигнализацию? ";
    bool *carAlarmStart = new bool;
    std::cin >> *carAlarmStart;
    Controller::positionOfStartButtom = *carAlarmStart;
    delete carAlarmStart;
}

bool Controller::getPositionOfStartButtom()
{
    return positionOfStartButtom;
}

void Controller::setAlarmNotice(std::string color, int repeat)
{
    Controller::ledColor = color;
    Controller::soundRepeat = repeat;
}

void Controller::saveAlarmNotice(std::ofstream& conditionCar)
{
    conditionCar << "Цвет светодиода: ";
    conditionCar << ledColor;
    conditionCar << "\n";
    for (int i=0; i<soundRepeat;i++)
    {
        conditionCar << "*Звуковое оповещение*";
        conditionCar << "\n";
    }
}

void Controller::saveArrayOfWorkedDoorsSensors(std::string *workedDoorsSensors, int countOfWorkedDoors)
{
    std::ofstream conditionCar("../../../../../../AlarmSystem/Notice.txt");
    for (int i=0; i<countOfWorkedDoors;i++)
    {
        conditionCar << "Не закрыта: ";
        conditionCar << workedDoorsSensors[i];
        conditionCar << "\n";
    }
    saveAlarmNotice(conditionCar);
    conditionCar.close();
}

void Controller::setCipherCode(int code, int pinCode)
{
    std::ofstream conditionCar("../../../../../../AlarmSystem/Notice.txt");
    conditionCar << "PinCode: ";
    conditionCar << pinCode;
    conditionCar << "\n";
    Controller::cipherCode = code;
}

int Controller::getCipherCode()
{
    return cipherCode;
}

void Controller::saveWorryModeNotice(std::string sensor, bool blockStarter, bool blockEngine)
{
    std::ofstream conditionCar("../../../../../../AlarmSystem/Notice.txt");
    conditionCar << sensor;
    conditionCar << "\n";
    if (blockStarter)
        conditionCar << "Заблокирован стартер\n";
    if (blockEngine)
        conditionCar << "Заблокирован двигатель\n";
    saveAlarmNotice(conditionCar);
    conditionCar.close();
}

void Controller::setDoorOpener()
{
    bool *doorOpener = new bool;
    std::cout << "Использован ли пульт управлением сигнализацией для открытия двери ";
    std::cin >> *doorOpener;
    Controller::doorOpener = *doorOpener;
    delete doorOpener;
}

bool Controller::getDoorOpener()
{
    return doorOpener;
}

void Controller::saveGuardMode(bool blockStarter, int authorizationCode)
{
    std::ofstream conditionCar("../../../../../../AlarmSystem/Notice.txt");
    if (blockStarter)
        conditionCar << "Заблокирован стартер\n";
    conditionCar << "Код авторизации:";
    conditionCar << authorizationCode;
    conditionCar << "\n";
    saveAlarmNotice(conditionCar);
    conditionCar.close();
}

void Controller::saveBlockedAllCar()
{
    std::ofstream conditionCar("../../../../../../AlarmSystem/Notice.txt");
    conditionCar << "Проникновение в машину!";
    conditionCar << "\n";
    conditionCar << "Заблокирован стартер\n";
    conditionCar << "Заблокирован двигатель\n";
    saveAlarmNotice(conditionCar);
    conditionCar.close();
}
