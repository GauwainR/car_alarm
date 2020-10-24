#include <iostream>
#include <string>

#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H


class ControlUnit
{
public:
    ControlUnit(bool positionOfStartButtom);
    bool getSystemActivity();

    void vehicleNotice(int noticeRepeat);

    void setCheckDoorsSensors(bool driver,
                              bool front,
                              bool backLeft,
                              bool backRight,
                              bool baggage,
                              bool hood);
    bool getCheckDoorsSensors();
    void setArrayOfWorkedDoorsSensors(bool driver,
                                      bool front,
                                      bool backLeft,
                                      bool backRight,
                                      bool baggage,
                                      bool hood);
    std::string *getArrayOfWorkedDoorsSensors();
    int getCountOfWorkedDoorsSensors();

    void setCipherCode();
    int getCipherCode();

    void setDoorOpener(bool doorOpener);
    bool getDoorOpener();

    bool checkPinCode();

    void setAuthorizationCode();
    int getAuthirizationCode();

    bool checkAuthirizationCode();
private:
    bool systemActivity;
    bool doorsActivity;
    std::string workedDoorsSensors[6];
    int countOfOpenDoors = 0;
    int cipherCode;
    bool doorOpener;
    int pinCode = 8055;
    int authorizationCode;
};

#endif // CONTROLUNIT_H
