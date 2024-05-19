#include <iostream>
#include "../include/structs/user.h"
#include "../include/structs/athlete.h"

usersList LoadUsers() {
    FILE* usersFile = fopen("users.bin", "rb");
    if(usersFile == nullptr) {
        usersFile = fopen("users.bin", "wb");
    }
    
    usersList loadingUsers;
    
    fseek(usersFile, 0, SEEK_END);
    loadingUsers.usersNumber = ftell(usersFile) / sizeof(user);
    rewind(usersFile);
    
    loadingUsers.usersList = new user[loadingUsers.usersNumber];
    
    for(int i = 0; i < loadingUsers.usersNumber; ++i) {
        fread(&loadingUsers.usersList[i], sizeof(user), 1, usersFile);
    }
    
    fclose(usersFile);
    
    return loadingUsers;
}

athletesList LoadAthletes() {
    FILE* athletesFile = fopen("athletes.bin", "rb");
    if(athletesFile == nullptr) {
        athletesFile = fopen("athletes.bin", "wb");
    }
    
    athletesList loadingAthletes;
    
    fseek(athletesFile, 0, SEEK_END);
    loadingAthletes.athletesNumber = ftell(athletesFile) / sizeof(athlete);
    rewind(athletesFile);
    
    loadingAthletes.athletesList = new athlete[loadingAthletes.athletesNumber];
    
    for(int i = 0; i < loadingAthletes.athletesNumber; ++i) {
        fread(&loadingAthletes.athletesList[i], sizeof(athlete), 1, athletesFile);
    }
    
    fclose(athletesFile);
    
    return loadingAthletes;
}
