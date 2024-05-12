#include <iostream>
#include "SwitchModule.h"

void SwitchModule() {
    std::cout << "1 - Data viewing" << std::endl;
    std::cout << "2 - Something else" << std::endl;
    std::cout << "3 - Something else" << std::endl;
    std::cout << "0 - Exit" << std::endl;
    
    char input;
    std::cin >> input;
    
    switch(input) {
        case '1':
            std::cout << "1";
            break;
        case '2':
            std::cout << "2";
            break;
        case '3':
            std::cout << "3";
            break;
        case '0':
            std::cout << "0";
            break;
        default:
            std::cout << "Incorrect input";
    }
}
