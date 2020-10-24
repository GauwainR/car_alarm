#include "../include/vehiclenotice.h"

void vehicleNotice(int noticeRepeat)
{
    for (int i=0; i<noticeRepeat; i++)
    {
        std::cout << "*Моргание фар*" << std::endl;
        std::cout << "*Гудок*" << std::endl;
    }
}
