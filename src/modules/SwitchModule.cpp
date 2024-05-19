#include <iostream>
#include "../../include/structs/athlete.h"
#include "../../include/structs/user.h"
#include "../../include/Utils.h"
#include "../../include/modules/Searching.h"
#include "../../include/modules/Sorting.h"
#include "../../include/modules/AthletesActions.h"
#include "../../include/modules/Calculations.h"
#include "../../include/modules/UsersActions.h"

void SelectSearchingMethod(athletesList athletes) {
    char input;
    
    while(true) {
        std::cout << "1 - Search by lastname" << std::endl;
        std::cout << "2 - Search by birth year" << std::endl;
        std::cout << "3 - Search by trainer" << std::endl;
        std::cout << "4 - Search by country" << std::endl;
        std::cout << "5 - Search the best athlete by country" << std::endl;
        std::cout << "6 - Search the best athlete by birth year" << std::endl;
        std::cout << "7 - Search all trainers by country" << std::endl;
        std::cout << "0 - Return" << std::endl;
        
        std::cin >> input;
        ClearConsole();
        
        switch(input) {
            case '1':
                LastnameSearch(athletes);
                break;
            case '2':
                BirthYearSearch(athletes);
                break;
            case '3':
                TrainerSearch(athletes);
                break;
            case '4':
                CountrySearch(athletes);
                break;
            case '5':
                CountryBestSearch(athletes);
                break;
            case '6':
                BirthYearBestSearch(athletes);
                break;
            case '7':
                TrainersByCountrySearch(athletes);
                break;
            case '0':
                ClearConsole();
                return;
            default:
                break;
        }
    }
}

void SelectSortingMethod(athletesList athletes) {
    char input;
    
    while(true) {
        std::cout << "1 - Sorting by result" << std::endl;
        std::cout << "2 - Sorting by lastname" << std::endl;
        std::cout << "3 - Sorting by country" << std::endl;
        std::cout << "0 - Return" << std::endl;
        
        std::cin >> input;
        ClearConsole();
        
        switch(input) {
            case '1':
                ResultSort(athletes);
                break;
            case '2':
                LastnameSort(athletes);
                break;
            case '3':
                CountrySort(athletes);
                break;
            case '0':
                ClearConsole();
                return;
            default:
                break;
        }
    }
}

void SwitchModule(usersList users, athletesList athletes) {
    bool isCurrentUserAdmin = users.usersList[users.currentUserID].isAdmin;
    char input;
    
    while(true) {
        std::cout << "1 - Show athletes" << std::endl;
        std::cout << "2 - Search athlete" << std::endl;
        std::cout << "3 - Sort athletes" << std::endl;
        std::cout << "4 - Calculate average weight and height by country" << std::endl;
        if(isCurrentUserAdmin) {
            std::cout << "5 - Create athlete" << std::endl;
            std::cout << "6 - Remove athlete" << std::endl;
            std::cout << "7 - Show users" << std::endl;
            std::cout << "8 - Create user" << std::endl;
            std::cout << "9 - Remove user" << std::endl;
        }
        std::cout << "0 - Exit" << std::endl;
        
        std::cin >> input;
        ClearConsole();
        
        if(isCurrentUserAdmin) {
            switch(input) {
                case '1':
                    ShowAthletes(athletes);
                    break;
                case '2':
                    SelectSearchingMethod(athletes);
                    break;
                case '3':
                    SelectSortingMethod(athletes);
                    break;
                case '4':
                    AverageWeightAndHeight(athletes);
                    break;
                case '5':
                    CreateAthlete(athletes);
                    break;
                case '6':
                    RemoveAthlete(athletes);
                    break;
                case '7':
                    ShowUsers(users);
                    break;
                case '8':
                    CreateUser(users);
                    break;
                case '9':
                    RemoveUser(users);
                    break;
                case '0':
                    exit(0);
                default:
                    break;
            }
        } else {
            switch(input) {
                case '1':
                    ShowAthletes(athletes);
                    break;
                case '2':
                    SelectSearchingMethod(athletes);
                    break;
                case '3':
                    SelectSortingMethod(athletes);
                    break;
                case '4':
                    AverageWeightAndHeight(athletes);
                    break;
                case '0':
                    exit(0);
                default:
                    break;
            }
        }
    }
}
