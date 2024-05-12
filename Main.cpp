#include <iostream>
#include "Loader.h"
#include "Login.h"
#include "SwitchModule.h"

usersList users = LoadUsers();

int main() {
    Login(users);
    
    SwitchModule(users.usersList[users.currentUserID]);
}
