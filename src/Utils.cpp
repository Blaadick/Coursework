#include <iostream>
#include "../include/Utils.h"

void ConfirmExit() {
    char input;
    
    std::cout << std::endl << "any - Return" << std::endl;
    std::cin >> input;
    
    ClearConsole();
}

void ClearConsole() {
    system("clear");
}
