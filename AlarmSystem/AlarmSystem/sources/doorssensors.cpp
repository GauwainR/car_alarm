#include "../include/doorssensors.h"

DoorsSensors::DoorsSensors()
{
    bool *driver = new bool;
    bool *baggage = new bool;
    bool *frontPassenger = new bool;
    bool *backLeftPassenger = new bool;
    bool *backRightPassenger = new bool;
    bool *hood = new bool;

    std::cout << "Открыта ли водительская дверь? "; std::cin >> *driver;
    std::cout << "Открыта ли дверь передняя пассажирская дверь? "; std::cin >> *frontPassenger;
    std::cout << "Открыта ли задняя левая пассажирская дверь? "; std::cin >> *backLeftPassenger;
    std::cout << "Открыта ли задняя правая пассажирская дверь? "; std::cin >> *backRightPassenger;
    std::cout << "Открыт ли багажник? "; std::cin >> *baggage;
    std::cout << "Открыт ли капот? "; std::cin >> *hood;

    DoorsSensors::driverDoor = *driver;
    DoorsSensors::baggageDoor = *baggage;
    DoorsSensors::frontPassengerDoor = *frontPassenger;
    DoorsSensors::backLeftPassengerDoor = *backLeftPassenger;
    DoorsSensors::backRightPassengerDoor = *backRightPassenger;
    DoorsSensors::hoodDoor = *hood;

    delete driver; delete frontPassenger;
    delete backLeftPassenger; delete backRightPassenger;
    delete hood; delete baggage;
}

bool DoorsSensors::getCheckDoorsSensors()
{
    if (driverDoor || frontPassengerDoor || backLeftPassengerDoor ||
            backRightPassengerDoor || baggageDoor || hoodDoor)
        return true;
    else
        return false;
}

void DoorsSensors::setArrayOfWorkedDoorsSensors()
{
    if (driverDoor)
    {
        DoorsSensors::workedDoorsSensors[countOfOpenDoors] = "Водительская дверь";
        DoorsSensors::countOfOpenDoors++;
    }
    if (frontPassengerDoor)
    {
        DoorsSensors::workedDoorsSensors[countOfOpenDoors] = "Передняя пассажирская дверь";
        DoorsSensors::countOfOpenDoors++;
    }
    if (backLeftPassengerDoor)
    {
        DoorsSensors::workedDoorsSensors[countOfOpenDoors] = "Задняя левая пассажирская дверь";
        DoorsSensors::countOfOpenDoors++;
    }
    if (backRightPassengerDoor)
    {
        DoorsSensors::workedDoorsSensors[countOfOpenDoors] = "Задняя правая пассажирская дверь";
        DoorsSensors::countOfOpenDoors++;
    }
    if (baggageDoor)
    {
        DoorsSensors::workedDoorsSensors[countOfOpenDoors] = "Багажная дверь";
        DoorsSensors::countOfOpenDoors++;
    }
    if (hoodDoor)
    {
        DoorsSensors::workedDoorsSensors[countOfOpenDoors] = "Капотная дверь";
        DoorsSensors::countOfOpenDoors++;
    }
}

std::string *DoorsSensors::getArrayOfWorkedDoorsSensors()
{
    return workedDoorsSensors;
}

int DoorsSensors::getCountOfWorkedDoorsSensors()
{
    return countOfOpenDoors;
}
