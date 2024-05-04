#include <iostream>
#include "loader.h"
#include "structs/user.h"

void loadUsers(user *users, unsigned &usersNumber) {
    FILE *usersFile = fopen("users.bin", "rb");
    
    fseek(usersFile, 0, SEEK_END);
    usersNumber = ftell(usersFile) / sizeof(user);
    rewind(usersFile);
    
    user *loadingUsers = new user[usersNumber];
    
    for(int i = 0; i < usersNumber; ++i) {
        fread(&loadingUsers[i], sizeof(user), 1, usersFile);
    }
    
    fclose(usersFile);
    
    users = loadingUsers;
}

void saveUsers(user savingUsers) {
    FILE *usersFile = fopen("users.bin", "wb");
    
    fwrite(&savingUsers, 1, sizeof(user), usersFile);
    fclose(usersFile);
}
