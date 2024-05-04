#pragma once

struct user {
    char login[16]{};
    char password[16]{};
    bool isAdmin = false;
};
