#include <iostream>
#include <string>
#include <ctime>
#include "controller.h"
#include "doorssensors.h"
#include "sensors.h"
#include "worrymode.h"
#include "vehiclenotice.h"
#include "checkpincode.h"
#include "checkauthirizationcode.h"

#ifndef UNITCONTROL_H
#define UNITCONTROL_H


class UnitControl
{
public:
    UnitControl();
private:
    Controller bibelot;
};

#endif // UNITCONTROL_H
