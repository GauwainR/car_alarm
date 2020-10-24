#include "checkpoweron.h"
bool checkPowerOn(Controller bibelot)
{
    if (!bibelot.getPositionOfStartButtom()) return 0;
    else return 1;
}
