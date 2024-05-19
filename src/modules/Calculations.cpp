#include <iostream>
#include <cstring>
#include "../../include/structs/athlete.h"
#include "../../include/Utils.h"

void AverageWeightAndHeight(athletesList athletes) {
    char wantedCountry[16];
    int athletesInCountry = 0;
    int allWeights = 0;
    int allHeights = 0;
    
    std::cout << "Enter country: ";
    std::cin >> wantedCountry;
    
    for(int i = 0; i < athletes.athletesNumber; ++i) {
        athlete athlete = athletes.athletesList[i];
        
        if(std::strcmp(athlete.country, wantedCountry) != 0) continue;
        athletesInCountry++;
        allWeights += athlete.weight;
        allHeights += athlete.height;
    }
    
    std::cout << "AverageWeight: " << allWeights / athletesInCountry << std::endl;
    std::cout << "AverageHeight: " << allHeights / athletesInCountry << std::endl;
    
    ConfirmExit();
}
