#include <iostream>
#include <cstring>
#include "Calculations.h"
#include "../Utils.h"

void AverageWeightAndHeight(athletesList athletes) {
    char wantedCountry[16];
    int allWeights = 0;
    int allHeights = 0;
    char input;
    
    std::cout << "Enter country: ";
    std::cin >> wantedCountry;
    
    for(int i = 0; i < athletes.athletesNumber; ++i) {
        athlete athlete = athletes.athletesList[i];
        
        if(std::strcmp(athlete.country, wantedCountry) != 0) continue;
        
        allWeights += athlete.weight;
        allHeights += athlete.height;
    }
    
    std::cout << "AverageWeight: " << allWeights / (int)athletes.athletesNumber << std::endl;
    std::cout << "AverageHeight: " << allHeights / (int)athletes.athletesNumber << std::endl;
    
    std::cout << std::endl << "any - Return" << std::endl;
    std::cin >> input;
    ClearConsole();
}
