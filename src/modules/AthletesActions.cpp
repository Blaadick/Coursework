#include <iostream>
#include <cstring>
#include "../../include/structs/athlete.h"
#include "../../include/Loader.h"
#include "../../include/Utils.h"

void AddAthlete(athletesList& athletes, athlete athleteToAdd) {
    FILE* athletesFile = fopen("athletes.bin", "ab");
    
    fwrite(&athleteToAdd, sizeof(athlete), 1, athletesFile);
    fclose(athletesFile);
    
    athletes.athletesList = LoadAthletes().athletesList;
    athletes.athletesNumber++;
}

void DeleteAthlete(athletesList& athletes, int athleteID) {
    FILE* athletesFile = fopen("athletes.bin", "wb");
    
    for(int i = 0; i < athletes.athletesNumber; ++i) {
        if(i == athleteID) continue;
        
        fwrite(&athletes.athletesList[i], sizeof(athlete), 1, athletesFile);
    }
    
    fclose(athletesFile);
    
    athletes.athletesList = LoadAthletes().athletesList;
    athletes.athletesNumber--;
}

void CreateAthlete(athletesList& athletes) {
    athlete newAthlete;
    
    std::cout << "Create new athlete" << std::endl;
    
    std::cout << "Lastname: ";
    std::cin >> newAthlete.lastname;
    
    std::cout << "Result: ";
    if(!(std::cin >> newAthlete.result)) {
        throw std::invalid_argument("Illegal argument!");
    }
    
    std::cout << "Height: ";
    if(!(std::cin >> newAthlete.height)) {
        throw std::invalid_argument("Illegal argument!");
    }
    
    std::cout << "Weight: ";
    if(!(std::cin >> newAthlete.weight)) {
        throw std::invalid_argument("Illegal argument!");
    }
    
    std::cout << "Birth year: ";
    if(!(std::cin >> newAthlete.birthYear)) {
        throw std::invalid_argument("Illegal argument!");
    }
    
    std::cout << "Trainer: ";
    std::cin >> newAthlete.trainer;
    
    std::cout << "Country: ";
    std::cin >> newAthlete.country;
    
    AddAthlete(athletes, newAthlete);
    
    ClearConsole();
}

void RemoveAthlete(athletesList& athletes) {
    char lastname[16];
    
    std::cout << "Enter the login of the user to be removed: ";
    std::cin >> lastname;
    
    for(int i = 0; i < athletes.athletesNumber; ++i) {
        if(std::strcmp(lastname, athletes.athletesList[i].lastname) == 0) {
            DeleteAthlete(athletes, i);
            
            std::cout << std::endl << "Athlete removed" << std::endl;
            
            ConfirmExit();
            return;
        }
    }
    
    std::cout << std::endl << "Athlete not found" << std::endl;
    
    ConfirmExit();
}

void ShowAthletes(athletesList athletesToShow) {
    std::cout << "┌──────────────────┬────────┬────────┬────────┬────────────┬──────────────────┬──────────────────┐" << std::endl;
    std::cout << "│ Athlete lastname │ Result │ Height │ Weight │ Birth year │ Trainer lastname │ Country          │" << std::endl;
    std::cout << "╞══════════════════╪════════╪════════╪════════╪════════════╪══════════════════╪══════════════════╡" << std::endl;
    
    if(athletesToShow.athletesNumber < 1) {
        std::cout << "└──────────────────┴────────┴────────┴────────┴────────────┴──────────────────┴──────────────────┘" << std::endl;
        
        std::cout << std::endl << "No athletes found :(" << std::endl;
        
        ConfirmExit();
        return;
    }
    
    for(int i = 0; i < athletesToShow.athletesNumber; ++i) {
        athlete athlete = athletesToShow.athletesList[i];
        
        printf("│ %-16s │ %-6i │ %-6i │ %-6i │ %-10i │ %-16s │ %-16s │\n",
               athlete.lastname,
               athlete.result,
               athlete.height,
               athlete.weight,
               athlete.birthYear,
               athlete.trainer,
               athlete.country
        );
        
        if(i == athletesToShow.athletesNumber - 1) {
            std::cout << "└──────────────────┴────────┴────────┴────────┴────────────┴──────────────────┴──────────────────┘" << std::endl;
        } else {
            std::cout << "├──────────────────┼────────┼────────┼────────┼────────────┼──────────────────┼──────────────────┤" << std::endl;
        }
    }
    
    ConfirmExit();
}
