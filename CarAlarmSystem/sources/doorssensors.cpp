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

bool DoorsSensors::getDriverDoor()
{
    return DoorsSensors::driverDoor;
}

bool DoorsSensors::getFrontPassengerDoor()
{
    return DoorsSensors::frontPassengerDoor;
}

bool DoorsSensors::getBackLeftPassengerDoor()
{
    return DoorsSensors::backLeftPassengerDoor;
}

bool DoorsSensors::getBackRightPassengerDoor()
{
    return DoorsSensors::backRightPassengerDoor;
}

bool DoorsSensors::getBaggageDoor()
{
    return DoorsSensors::baggageDoor;
}

bool DoorsSensors::getHoodDoor()
{
    return DoorsSensors::hoodDoor;
}
