#include <iostream>
#include "../Utils.h"
#include "../structs/athlete.h"
#include "Athletes.h"

void ResultSort(athletesList& athletes) {
    for(unsigned i = 0; i < athletes.athletesNumber; ++i) {
        for(unsigned j = athletes.athletesNumber - 1; j > i; --j) {
            if(athletes.athletesList[i].result < athletes.athletesList[j].result) {
                std::swap(athletes.athletesList[i], athletes.athletesList[j]);
            }
        }
    }
    
    ShowAthletes(athletes);
}

void LastnameSort(athletesList& athletes) {
    for(unsigned i = 0; i < athletes.athletesNumber; ++i) {
        for(unsigned j = athletes.athletesNumber - 1; j > i; --j) {
            if(athletes.athletesList[i].lastname[0] > athletes.athletesList[j].lastname[0]) {
                std::swap(athletes.athletesList[i], athletes.athletesList[j]);
            }
        }
    }
    
    ShowAthletes(athletes);
}

void CountrySort(athletesList& athletes) {
    for(unsigned i = 0; i < athletes.athletesNumber; ++i) {
        for(unsigned j = athletes.athletesNumber - 1; j > i; --j) {
            if(athletes.athletesList[i].country[0] > athletes.athletesList[j].country[0]) {
                std::swap(athletes.athletesList[i], athletes.athletesList[j]);
            }
        }
    }
    
    ShowAthletes(athletes);
}
