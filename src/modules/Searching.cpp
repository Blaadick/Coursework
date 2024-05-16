#include <iostream>
#include <cstring>
#include "Searching.h"
#include "../Utils.h"

void LastnameSearch(athletesList athletes) {
    char lastnameWanted[16];
    bool athleteFound = false;
    char input;
    
    std::cout << "Search athlete by last name" << std::endl;
    
    std::cout << "Enter lastname: ";
    std::cin >> lastnameWanted;
    
    std::cout << std::endl << "┌──────────────────┬────────┬────────┬────────┬────────────┬──────────────────┬──────────────────┐" << std::endl;
    std::cout << "│ Athlete lastname │ Result │ Height │ Weight │ Birth year │ Trainer lastname │ Country          │" << std::endl;
    std::cout << "╞══════════════════╪════════╪════════╪════════╪════════════╪══════════════════╪══════════════════╡" << std::endl;
    
    for(int i = 0; i < athletes.athletesNumber; ++i) {
        athlete athlete = athletes.athletesList[i];
        
        if(std::strcmp(athlete.lastname, lastnameWanted) == 0) {
            athleteFound = true;
            
            printf("│ %-16s │ %-6i │ %-6i │ %-6i │ %-10i │ %-16s │ %-16s │\n",
                   athlete.lastname,
                   athlete.result,
                   athlete.height,
                   athlete.weight,
                   athlete.birthYear,
                   athlete.trainer,
                   athlete.country
            );
            
            std::cout << "├──────────────────┼────────┼────────┼────────┼────────────┼──────────────────┼──────────────────┤" << std::endl;
        }
    }
    
    if(!athleteFound) {
        std::cout << "└──────────────────┴────────┴────────┴────────┴────────────┴──────────────────┴──────────────────┘" << std::endl;
        std::cout << "No athletes found :(" << std::endl;
    }
    
    std::cout << std::endl << "any - Return" << std::endl;
    std::cin >> input;
    
    ClearConsole();
}

void BirthYearSearch(athletesList athletes) {
    int birthYearWanted;
    bool athleteFound = false;
    char input;
    
    std::cout << "Search athlete by birth year" << std::endl;
    
    std::cout << "Enter birth year: ";
    
    if(!(std::cin >> birthYearWanted)) {
        throw std::invalid_argument("Illegal argument!");
    }
    
    std::cout << std::endl << "┌──────────────────┬────────┬────────┬────────┬────────────┬──────────────────┬──────────────────┐" << std::endl;
    std::cout << "│ Athlete lastname │ Result │ Height │ Weight │ Birth year │ Trainer lastname │ Country          │" << std::endl;
    std::cout << "╞══════════════════╪════════╪════════╪════════╪════════════╪══════════════════╪══════════════════╡" << std::endl;
    
    for(int i = 0; i < athletes.athletesNumber; ++i) {
        athlete athlete = athletes.athletesList[i];
        
        if(athlete.birthYear == birthYearWanted) {
            athleteFound = true;
            
            printf("│ %-16s │ %-6i │ %-6i │ %-6i │ %-10i │ %-16s │ %-16s │\n",
                   athlete.lastname,
                   athlete.result,
                   athlete.height,
                   athlete.weight,
                   athlete.birthYear,
                   athlete.trainer,
                   athlete.country
            );
            
            std::cout << "├──────────────────┼────────┼────────┼────────┼────────────┼──────────────────┼──────────────────┤" << std::endl;
        }
    }
    
    if(!athleteFound) {
        std::cout << "└──────────────────┴────────┴────────┴────────┴────────────┴──────────────────┴──────────────────┘" << std::endl;
        std::cout << "No athletes found :(" << std::endl;
    }
    
    std::cout << std::endl << "any - Return" << std::endl;
    std::cin >> input;
    
    ClearConsole();
}

void TrainerSearch(athletesList athletes) {
    char trainerWanted[16];
    bool athleteFound = false;
    char input;
    
    std::cout << "Search athlete by trainer" << std::endl;
    
    std::cout << "Enter trainer lastname: ";
    std::cin >> trainerWanted;
    
    std::cout << std::endl << "┌──────────────────┬────────┬────────┬────────┬────────────┬──────────────────┬──────────────────┐" << std::endl;
    std::cout << "│ Athlete lastname │ Result │ Height │ Weight │ Birth year │ Trainer lastname │ Country          │" << std::endl;
    std::cout << "╞══════════════════╪════════╪════════╪════════╪════════════╪══════════════════╪══════════════════╡" << std::endl;
    
    for(int i = 0; i < athletes.athletesNumber; ++i) {
        athlete athlete = athletes.athletesList[i];
        
        if(std::strcmp(athlete.trainer, trainerWanted) == 0) {
            athleteFound = true;
            
            printf("│ %-16s │ %-6i │ %-6i │ %-6i │ %-10i │ %-16s │ %-16s │\n",
                   athlete.lastname,
                   athlete.result,
                   athlete.height,
                   athlete.weight,
                   athlete.birthYear,
                   athlete.trainer,
                   athlete.country
            );
            
            std::cout << "├──────────────────┼────────┼────────┼────────┼────────────┼──────────────────┼──────────────────┤" << std::endl;
        }
    }
    
    if(!athleteFound) {
        std::cout << "└──────────────────┴────────┴────────┴────────┴────────────┴──────────────────┴──────────────────┘" << std::endl;
        std::cout << "No athletes found :(" << std::endl;
    }
    
    std::cout << std::endl << "any - Return" << std::endl;
    std::cin >> input;
    
    ClearConsole();
}

void CountrySearch(athletesList athletes) {
    char countryWanted[16];
    bool athleteFound = false;
    char input;
    
    std::cout << "Search athlete by country" << std::endl;
    
    std::cout << "Enter country: ";
    std::cin >> countryWanted;
    
    std::cout << std::endl << "┌──────────────────┬────────┬────────┬────────┬────────────┬──────────────────┬──────────────────┐" << std::endl;
    std::cout << "│ Athlete lastname │ Result │ Height │ Weight │ Birth year │ Trainer lastname │ Country          │" << std::endl;
    std::cout << "╞══════════════════╪════════╪════════╪════════╪════════════╪══════════════════╪══════════════════╡" << std::endl;
    
    for(int i = 0; i < athletes.athletesNumber; ++i) {
        athlete athlete = athletes.athletesList[i];
        
        if(std::strcmp(athlete.country, countryWanted) == 0) {
            athleteFound = true;
            
            printf("│ %-16s │ %-6i │ %-6i │ %-6i │ %-10i │ %-16s │ %-16s │\n",
                   athlete.lastname,
                   athlete.result,
                   athlete.height,
                   athlete.weight,
                   athlete.birthYear,
                   athlete.trainer,
                   athlete.country
            );
            
            std::cout << "├──────────────────┼────────┼────────┼────────┼────────────┼──────────────────┼──────────────────┤" << std::endl;
        }
    }
    
    if(!athleteFound) {
        std::cout << "└──────────────────┴────────┴────────┴────────┴────────────┴──────────────────┴──────────────────┘" << std::endl;
        std::cout << "No athletes found :(" << std::endl;
    }
    
    std::cout << std::endl << "any - Return" << std::endl;
    std::cin >> input;
    
    ClearConsole();
}

void CountryBestSearch(athletesList athletes) {
    char countryWanted[16];
    athlete athleteLookingFor;
    char input;
    
    std::cout << "Search best athlete by country" << std::endl;
    
    std::cout << "Enter country: ";
    std::cin >> countryWanted;
    
    for(int i = 0; i < athletes.athletesNumber; ++i) {
        athlete athlete = athletes.athletesList[i];
        
        if(std::strcmp(athlete.country, countryWanted) != 0) continue;
        if(athlete.result >= athleteLookingFor.result) athleteLookingFor = athlete;
    }
    
    std::cout << std::endl << "┌──────────────────┬────────┬────────┬────────┬────────────┬──────────────────┬──────────────────┐" << std::endl;
    std::cout << "│ Athlete lastname │ Result │ Height │ Weight │ Birth year │ Trainer lastname │ Country          │" << std::endl;
    std::cout << "╞══════════════════╪════════╪════════╪════════╪════════════╪══════════════════╪══════════════════╡" << std::endl;
    
    if(strcmp(athleteLookingFor.country, "") == 0) {
        std::cout << "└──────────────────┴────────┴────────┴────────┴────────────┴──────────────────┴──────────────────┘"<< std::endl;
    
        std::cout << "No athlete found :(" << std::endl;
    } else {
        printf("│ %-16s │ %-6i │ %-6i │ %-6i │ %-10i │ %-16s │ %-16s │\n",
        athleteLookingFor.lastname,
        athleteLookingFor.result,
        athleteLookingFor.height,
        athleteLookingFor.weight,
        athleteLookingFor.birthYear,
        athleteLookingFor.trainer,
        athleteLookingFor.country
        );
        
        std::cout << "└──────────────────┴────────┴────────┴────────┴────────────┴──────────────────┴──────────────────┘"<< std::endl;
    }
    
    std::cout << std::endl << "any - Return" << std::endl;
    std::cin >> input;
    
    ClearConsole();
}

void BirthYearBestSearch(athletesList athletes) {
    athlete athleteLookingFor;
    int athleteAgeWanted;
    char input;
    time_t time = std::time(nullptr);
    int currentYear = localtime(&time)->tm_year + 1900;
    
    athleteLookingFor.birthYear = 0;
    
    std::cout << "Search best athlete by country" << std::endl;
    
    std::cout << "Enter athlete age: ";
    if(!(std::cin >> athleteAgeWanted)) {
        throw std::invalid_argument("Illegal argument!");
    }
    
    for(int i = 0; i < athletes.athletesNumber; ++i) {
        athlete athlete = athletes.athletesList[i];
        
        if(athlete.birthYear != currentYear - athleteAgeWanted) continue;
        if(athlete.result >= athleteLookingFor.result) athleteLookingFor = athlete;
    }
    
    std::cout << std::endl << "┌──────────────────┬────────┬────────┬────────┬────────────┬──────────────────┬──────────────────┐" << std::endl;
    std::cout << "│ Athlete lastname │ Result │ Height │ Weight │ Birth year │ Trainer lastname │ Country          │" << std::endl;
    std::cout << "╞══════════════════╪════════╪════════╪════════╪════════════╪══════════════════╪══════════════════╡" << std::endl;
    
    if(athleteLookingFor.result == 0) {
        std::cout << "└──────────────────┴────────┴────────┴────────┴────────────┴──────────────────┴──────────────────┘"<< std::endl;
        
        std::cout << "No athlete found :(" << std::endl;
    } else {
        printf("│ %-16s │ %-6i │ %-6i │ %-6i │ %-10i │ %-16s │ %-16s │\n",
               athleteLookingFor.lastname,
               athleteLookingFor.result,
               athleteLookingFor.height,
               athleteLookingFor.weight,
               athleteLookingFor.birthYear,
               athleteLookingFor.trainer,
               athleteLookingFor.country
        );
        
        std::cout << "└──────────────────┴────────┴────────┴────────┴────────────┴──────────────────┴──────────────────┘"<< std::endl;
    }
    
    std::cout << std::endl << "any - Return" << std::endl;
    std::cin >> input;
    
    ClearConsole();
}

void TrainersByCountrySearch(athletesList athletes) {
    char countryWanted[16];
    char input;
    
    std::cout << "Search all trainers by country" << std::endl;
    
    std::cout << "Enter country: ";
    std::cin >> countryWanted;
    
    std::cout << "┌──────────────────┐" << std::endl;
    
    for(int i = 0; i < athletes.athletesNumber; ++i) {
        athlete athlete = athletes.athletesList[i];
        
        if(strcmp(athlete.country, countryWanted) == 0) {
            printf("│ %-16s │\n", athlete.trainer);
            
            std::cout << "├──────────────────┤" << std::endl;
        }
    }
    std::cout << std::endl << "any - Return" << std::endl;
    std::cin >> input;
    
    ClearConsole();
}
