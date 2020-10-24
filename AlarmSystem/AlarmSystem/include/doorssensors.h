#include <iostream>
#include <string>
#ifndef DOORSSENSORS_H
#define DOORSSENSORS_H


class DoorsSensors
{
public:
    DoorsSensors();

    bool getDriverDoor();
    bool getFrontPassengerDoor();
    bool getBackLeftPassengerDoor();
    bool getBackRightPassengerDoor();
    bool getBaggageDoor();
    bool getHoodDoor();
    bool getCheckDoorsSensors();
    void setArrayOfWorkedDoorsSensors();
    std::string *getArrayOfWorkedDoorsSensors();
    int getCountOfWorkedDoorsSensors();
private:
    bool driverDoor;
    bool baggageDoor;
    bool frontPassengerDoor;
    bool backLeftPassengerDoor;
    bool backRightPassengerDoor;
    bool hoodDoor;
    std::string workedDoorsSensors[6];
    int countOfOpenDoors = 0;
};

#endif // DOORSSENSORS_H
