#include <iostream>
#include <cstring>
#include "Login.h"
#include "Utils.h"
#include "Loader.h"
#include "modules/Users.h"

void Login(usersList& users) {
    FILE* usersFile = fopen("users.bin", "rb");
    user newUser;
    
    fseek(usersFile, 0, SEEK_END);
    
    if(ftell(usersFile) > 0) {
        while(true) {
            std::cout << "Login on to user" << std::endl;
            
            std::cout << "Login: ";
            std::cin >> newUser.login;
            
            std::cout << "Password: ";
            std::cin >> newUser.password;
            
            for(int i = 0; i < users.usersNumber; ++i) {
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
        
        users.currentUserID = (unsigned)0;
        
        AddUser(users, newUser);
        
        ClearConsole();
    }
    
    fclose(usersFile);
}
