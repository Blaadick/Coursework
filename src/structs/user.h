#pragma once

struct user {
    char login[16]{};
    char password[16]{};
    bool isAdmin{};
};

struct usersList {
    user* usersList = new user[]{};
    unsigned int usersNumber{};
    unsigned int currentUserID{};
};
