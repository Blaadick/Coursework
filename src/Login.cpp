#include <iostream>
#include <cstring>
#include "structs/user.h"
#include "Login.h"
#include "Utils.h"

void Login(usersList& users) {
    FILE* usersFile = fopen("users.bin", "rb");
    user newUser;
    
    if(usersFile != nullptr) {
        while(true) {
            std::cout << "Login on to user" << std::endl;
            
            std::cout << "Login: ";
            std::cin >> newUser.login;
            
            std::cout << "Password: ";
            std::cin >> newUser.password;
            
            for(unsigned int i = 0; i < users.usersNumber; ++i) {
                if(strcmp(newUser.login, users.usersList[i].login) != 0) continue;
                if(strcmp(newUser.password, users.usersList[i].password) != 0) continue;
                
                users.currentUserID = i;
                
                ClearConsole();
                return;
            }
            
            ClearConsole();
        }
    } else {
        std::cout << "Create new user" << std::endl;
        
        std::cout << "Login: ";
        std::cin >> newUser.login;
        
        std::cout << "Password: ";
        std::cin >> newUser.password;
        
        newUser.isAdmin = true;
        
        //TODO Create new user
    }
    
    fclose(usersFile);
}
