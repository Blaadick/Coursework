#include <iostream>
#include <cstring>
#include "../../include/structs/user.h"
#include "../../include/Utils.h"
#include "../../include/Loader.h"

void AddUser(usersList& users, user userToAdd) {
    FILE* usersFile = fopen("users.bin", "ab");
    
    fwrite(&userToAdd, sizeof(user), 1, usersFile);
    fclose(usersFile);
    
    usersList newList = LoadUsers();
    users.usersList = newList.usersList;
    users.usersNumber++;
}

void DeleteUser(usersList& users, int userID) {
    FILE* usersFile = fopen("users.bin", "wb");
    
    for(int i = 0; i < users.usersNumber; ++i) {
        if(i == userID) continue;
        
        fwrite(&users.usersList[i], sizeof(user), 1, usersFile);
    }
    
    fclose(usersFile);
    
    users.usersList = LoadUsers().usersList;
    users.usersNumber--;
}

void CreateUser(usersList& users) {
    user newUser;
    
    std::cout << "Create new user" << std::endl;
    
    std::cout << "Login: ";
    std::cin >> newUser.login;
    
    std::cout << "Password: ";
    std::cin >> newUser.password;
    
    std::cout << "Is admin? (1/0): ";
    if(!(std::cin >> newUser.isAdmin)) {
        throw std::invalid_argument("Illegal argument!");
    }
    
    for(int i = 0; i < users.usersNumber; ++i) {
        if(std::strcmp(newUser.login, users.usersList[i].login) == 0) {
            std::cout << std::endl << "A user with this name already exists" << std::endl;
            
            ConfirmExit();
            return;
        }
    }
    
    AddUser(users, newUser);
    
    std::cout << std::endl << "User created" << std::endl;
    
    ConfirmExit();
}

void RemoveUser(usersList& users) {
    char login[16];
    
    std::cout << "Enter the login of the user to be removed: ";
    std::cin >> login;
    
    if(std::strcmp(login, users.usersList[users.currentUserID].login) == 0) {
        std::cout << std::endl << "You cant delete you self";
        
        ConfirmExit();
        return;
    }
    
    for(int i = 0; i < users.usersNumber; ++i) {
        if(std::strcmp(login, users.usersList[i].login) == 0) {
            DeleteUser(users, i);
            
            std::cout << std::endl << "User removed" << std::endl;
            
            ConfirmExit();
            return;
        }
    }
    
    std::cout << std::endl << "User not found" << std::endl;
    
    ConfirmExit();
}

void ShowUsers(usersList usersToShow) {
    std::cout << "┌──────────────────┬───────────┐" << std::endl;
    std::cout << "│ Username         │ Is admin? │" << std::endl;
    std::cout << "╞══════════════════╪═══════════╡" << std::endl;
    
    for(int i = 0; i < usersToShow.usersNumber; ++i) {
        printf("│ %-16s │ %-9b │\n", usersToShow.usersList[i].login, usersToShow.usersList[i].isAdmin);
        
        if(i == usersToShow.usersNumber - 1) {
            std::cout << "└──────────────────┴───────────┘" << std::endl;
        } else {
            std::cout << "├──────────────────┼───────────┤" << std::endl;
        }
    }
    
    ConfirmExit();
}
