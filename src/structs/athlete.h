#pragma once

struct athlete {
    char lastname[16]{};
    int result{};
    int height{};
    int weight{};
    int birthYear{};
    char trainer[16]{};
    char country[16]{};
};

struct athletesList {
    athlete* athletesList = new athlete[]{};
    unsigned int athletesNumber{};
};
