#include <iostream>
#include "SwitchModule.h"
#include "structs/user.h"
#include "Utils.h"

void SwitchModule(user currentUser) {
    char input;
    
    if(currentUser.isAdmin) {
        while(true) {
            std::cout << "1 - Data viewing" << std::endl;
            std::cout << "2 - Something else" << std::endl;
            std::cout << "3 - Something else" << std::endl;
            std::cout << "4 - Something else" << std::endl;
            std::cout << "5 - Something else" << std::endl;
            std::cout << "6 - Something else" << std::endl;
            std::cout << "7 - Something else" << std::endl;
            std::cout << "8 - Something else" << std::endl;
            std::cout << "0 - Exit" << std::endl;
            
            std::cin >> input;
            ClearConsole();
            
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
                case '4':
                    std::cout << "4";
                    break;
                case '5':
                    std::cout << "5";
                    break;
                case '6':
                    std::cout << "6";
                    break;
                case '7':
                    std::cout << "7";
                    break;
                case '8':
                    std::cout << "8";
                    break;
                case '0':
                    std::cout << "0";
                    break;
                default:
                    continue;
            }
            
            break;
        }
    } else {
        while(true) {
            std::cout << "1 - Data viewing" << std::endl;
            std::cout << "2 - Something else" << std::endl;
            std::cout << "3 - Something else" << std::endl;
            std::cout << "0 - Exit" << std::endl;
            
            std::cin >> input;
            ClearConsole();
            
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
                    continue;
            }
            
            break;
        }
    }
    

}
