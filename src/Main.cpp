#include <iostream>
#include "../include/Loader.h"
#include "../include/Login.h"
#include "../include/modules/SwitchModule.h"

usersList users = LoadUsers();
athletesList athletes = LoadAthletes();

int main() {
    Login(users);
    
    SwitchModule(users, athletes);
}
