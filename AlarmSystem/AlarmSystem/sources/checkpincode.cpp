#include "../include/checkpincode.h"

bool checkPinCode(int pinCode)
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
