#include <iostream>
#include "SwitchModule.h"
#include "../Utils.h"
#include "Users.h"
#include "Athletes.h"
#include "Sorting.h"

/**
 * Calls modules depending on user input.
 *
 * @param currentUser
 */
void SwitchModule(usersList users, athletesList athletes) {
    bool isCurrentUserAdmin = users.usersList[users.currentUserID].isAdmin;
    char input;
    
    while(true) {
        std::cout << "1 - Show users" << std::endl;
        std::cout << "2 - Add user" << std::endl;
        std::cout << "3 - Show athletes" << std::endl;
        if(isCurrentUserAdmin) {
            std::cout << "4 - Add athletes" << std::endl;
            std::cout << "5 - Search athlete" << std::endl;
            std::cout << "6 - Sort athletes" << std::endl;
            std::cout << "7 - Something else" << std::endl;
            std::cout << "8 - Something else" << std::endl;
        }
        std::cout << "0 - Exit" << std::endl;
        
        std::cin >> input;
        ClearConsole();
        
        if(isCurrentUserAdmin) {
            switch(input) {
                case '1':
                    ShowUsers(users);
                    break;
                case '2':
                    CreateUser(users);
                    break;
                case '3':
                    ShowAthletes(athletes);
                    break;
                case '4':
                    CreateAthlete(athletes);
                    break;
                case '5':
                    SearchAthlete(athletes);
                    break;
                case '6':
                    SelectSortingMethod(athletes);
                    break;
                case '7':
                    std::cout << "7";
                    break;
                case '8':
                    std::cout << "8";
                    break;
                case '0':
                    exit(0);
                default:
                    break;
            }
        } else {
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
                    exit(0);
                default:
                    break;
            }
        }
    }
}
