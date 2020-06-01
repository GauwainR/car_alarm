#include "../include/controlunit.h"

ControlUnit::ControlUnit(bool positionOfStartButtom)
{
    ControlUnit::systemActivity = positionOfStartButtom;
}

bool ControlUnit::getSystemActivity()
{
    return ControlUnit::systemActivity;
}

void ControlUnit::vehicleNotice(int noticeRepeat)
{
    for (int i=0; i<noticeRepeat; i++)
    {
        std::cout << "*Моргание фар*" << std::endl;
        std::cout << "*Гудок*" << std::endl;
    }
}


void ControlUnit::setCheckDoorsSensors(bool driver,
                                       bool front,
                                       bool backLeft,
                                       bool backRight,
                                       bool baggage,
                                       bool hood)
{
    if (driver || front || backLeft || backRight || baggage || hood)
        ControlUnit::doorsActivity = true;
    else
        ControlUnit::doorsActivity = false;
}

bool ControlUnit::getCheckDoorsSensors()
{
    return ControlUnit::doorsActivity;
}

void ControlUnit::setArrayOfWorkedDoorsSensors(bool driver,
                                               bool front,
                                               bool backLeft,
                                               bool backRight,
                                               bool baggage,
                                               bool hood)
{
    if (driver)
    {
        ControlUnit::workedDoorsSensors[countOfOpenDoors] = "Водительская дверь";
        ControlUnit::countOfOpenDoors++;
    }
    if (front)
    {
        ControlUnit::workedDoorsSensors[countOfOpenDoors] = "Передняя пассажирская дверь";
        ControlUnit::countOfOpenDoors++;
    }
    if (backLeft)
    {
        ControlUnit::workedDoorsSensors[countOfOpenDoors] = "Задняя левая пассажирская дверь";
        ControlUnit::countOfOpenDoors++;
    }
    if (backRight)
    {
        ControlUnit::workedDoorsSensors[countOfOpenDoors] = "Задняя правая пассажирская дверь";
        ControlUnit::countOfOpenDoors++;
    }
    if (baggage)
    {
        ControlUnit::workedDoorsSensors[countOfOpenDoors] = "Багажная дверь";
        ControlUnit::countOfOpenDoors++;
    }
    if (hood)
    {
        ControlUnit::workedDoorsSensors[countOfOpenDoors] = "Капотная дверь";
        ControlUnit::countOfOpenDoors++;
    }
}

std::string *ControlUnit::getArrayOfWorkedDoorsSensors()
{
    return workedDoorsSensors;
}

int ControlUnit::getCountOfWorkedDoorsSensors()
{
    return countOfOpenDoors;
}

void ControlUnit::setCipherCode()
{

    ControlUnit::cipherCode = rand()%(9999-1000+1);
}

int ControlUnit::getCipherCode()
{
    return cipherCode;
}

void ControlUnit::setDoorOpener(bool doorOpener)
{
    ControlUnit::doorOpener = doorOpener;
}

bool ControlUnit::getDoorOpener()
{
    return doorOpener;
}

bool ControlUnit::checkPinCode()
{
    int enteredPinCode;
    for (int attempts=0; attempts<3;attempts++)
    {
        std::cout << "Введите PinCode: ";
        std::cin >> enteredPinCode;
        if (enteredPinCode == pinCode)
            return true;
        else
            std::cout << "Неверный PinCode!" << std::endl;
    }
    return false;
}

void ControlUnit::setAuthorizationCode()
{
    ControlUnit::authorizationCode = rand()%(999999-100000+1);
}

int ControlUnit::getAuthirizationCode()
{
    return authorizationCode;
}

bool ControlUnit::checkAuthirizationCode()
{
    int enteredAuthorizationCode;
    std::cout << "Введите код авторизации.";
    std::cin >> enteredAuthorizationCode;
    if (authorizationCode == enteredAuthorizationCode)
        return true;
    else
        return false;
}
