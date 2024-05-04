#include <iostream>
#include "loader.h"
#include "login.h"

int main() {
    user *users = new user[]{};
    unsigned usersNumber;
    
    loadUsers(*users, usersNumber);
    
    std::cout << users[0].login;
}
