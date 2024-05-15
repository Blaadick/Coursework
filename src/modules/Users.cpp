#include "Users.h"
#include "../Utils.h"
#include "../Loader.h"

/**
 * Adds user to users
 *
 * @param users
 * @param userToAdd
 */
void AddUser(usersList& users, user userToAdd) {
    //TODO Check unic username
    FILE* usersFile = fopen("users.bin", "ab");
    
    fwrite(&userToAdd, sizeof(user), 1, usersFile);
    fclose(usersFile);
    
    users.usersList = LoadUsers().usersList;
    users.usersNumber++;
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
    
    AddUser(users, newUser);
    
    ClearConsole();
}

void ShowUsers(usersList usersToShow) {
    char input;
    
    std::cout << "├──────────────────┼───┤" << std::endl;
    
    for(int i = 0; i < usersToShow.usersNumber; ++i) {
        printf("│ %-16s │ %b │\n", usersToShow.usersList[i].login, usersToShow.usersList[i].isAdmin);
        std::cout << "├──────────────────┼───┤" << std::endl;
    }
    
    std::cout << std::endl << "any - Return" << std::endl;
    
    std::cin >> input;
    
    ClearConsole();
}
