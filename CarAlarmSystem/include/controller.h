#include <iostream>
#include <fstream>


#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
    Controller();
    bool getPositionOfStartButtom();

    void setAlarmNotice(std::string color, int sound);

    void saveAlarmNotice(std::ofstream& conditionCar);
    void saveArrayOfWorkedDoorsSensors(std::string *workedDoorsSensors, int countOfWorkedDoors);
    void saveWorryModeNotice(std::string sensor, bool blockStarter, bool blockEngine);

    void setCipherCode(int code);
    int getCipherCode();

    void setDoorOpener();
    bool getDoorOpener();

    void saveGuardMode(bool blockStarter, int authorizationCode);
    void saveBlockedAllCar();
private:
    std::string ledColor;
    int soundRepeat;
    bool positionOfStartButtom;
    bool doorsSensors;
    int cipherCode;
    bool doorOpener;
};

#endif // CONTROLLER_H
