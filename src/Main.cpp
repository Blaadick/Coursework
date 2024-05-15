#include <iostream>
#include "Loader.h"
#include "Login.h"
#include "modules/SwitchModule.h"

usersList users = LoadUsers();
athletesList athletes = LoadAthletes();

int main() {
    Login(users);
    
    SwitchModule(users, athletes);
}
