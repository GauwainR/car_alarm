#include <iostream>

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
private:
    bool driverDoor;
    bool baggageDoor;
    bool frontPassengerDoor;
    bool backLeftPassengerDoor;
    bool backRightPassengerDoor;
    bool hoodDoor;
};

#endif // DOORSSENSORS_H
