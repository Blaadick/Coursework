#include <iostream>
#include "Loader.h"
#include "structs/user.h"

usersList LoadUsers() {
    //TODO Fix out of file bug
    FILE* usersFile = fopen("users.bin", "rb");
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
