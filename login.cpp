#include <iostream>
#include "login.h"
#include "structs/user.h"

user readUser(int id) {
    user readUser{};
    FILE *usersFile = fopen("users.bin", "rb");
    
    fseek(usersFile, (unsigned)sizeof(user) * id, SEEK_SET);
    fread(&readUser, sizeof(user), 1, usersFile);
    fclose(usersFile);
    
    return readUser;
}

void createUser(user userToCreate) {
    FILE *usersFile = fopen("users.bin", "ab");
    fwrite(&userToCreate, (unsigned)sizeof(user), 1, usersFile);
    fclose(usersFile);
}

void login() {
    FILE *usersFile = fopen("users.bin", "rb");
    user newUser;
    
    if(usersFile != nullptr) {
        std::cout << "Login on to user" << std::endl;
        
        std::cout << "Login: ";
        std::cin >> newUser.login;
        
        std::cout << "Password: ";
        std::cin >> newUser.password;
        //TODO Искать подходящего пользователя\
    } else {
        std::cout << "Create new user" << std::endl;
        
        std::cout << "Login: ";
        std::cin >> newUser.login;
        
        std::cout << "Password: ";
        std::cin >> newUser.password;
        
        newUser.isAdmin = true;
        
        createUser(newUser);
    }
    
    fclose(usersFile);
}
