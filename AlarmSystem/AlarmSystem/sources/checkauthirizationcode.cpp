#include "../include/checkauthirizationcode.h"

bool checkAuthirizationCode(int authorizationCode)
{
    int enteredAuthorizationCode;
    std::cout << "Введите код авторизации.";
    std::cin >> enteredAuthorizationCode;
    if (authorizationCode == enteredAuthorizationCode)
        return true;
    else
        return false;
}
