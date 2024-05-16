#include <iostream>
#include "Athletes.h"
#include "../Loader.h"
#include "../Utils.h"

void AddAthlete(athletesList& athletes, athlete athleteToAdd) {
    FILE* athletesFile = fopen("athletes.bin", "ab");
    
    fwrite(&athleteToAdd, sizeof(athlete), 1, athletesFile);
    fclose(athletesFile);
    
    athletes.athletesList = LoadAthletes().athletesList;
    athletes.athletesNumber++;
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

void ShowAthletes(athletesList athletesToShow) {
    char input;
    
    std::cout << "┌──────────────────┬────────┬────────┬────────┬────────────┬──────────────────┬──────────────────┐" << std::endl;
    std::cout << "│ Athlete lastname │ Result │ Height │ Weight │ Birth year │ Trainer lastname │ Country          │" << std::endl;
    std::cout << "╞══════════════════╪════════╪════════╪════════╪════════════╪══════════════════╪══════════════════╡" << std::endl;
    
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
    
    std::cout << std::endl << "any - Return" << std::endl;
    std::cin >> input;
    
    ClearConsole();
}
