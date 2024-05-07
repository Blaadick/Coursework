#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ROOM_LENGTH 10
#define MAX_USERS 100
typedef struct {
    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];
} User;

typedef struct {
    int number;
    char surname[MAX_NAME_LENGTH];
    char firstname[MAX_NAME_LENGTH];
    char middlename[MAX_NAME_LENGTH];
    char room_number[MAX_ROOM_LENGTH];
    char room_category[MAX_NAME_LENGTH];
    char check_in_date[MAX_NAME_LENGTH];
    int stay_duration;
    float price_per_night;
} Guest;

typedef struct {
    User users[MAX_USERS];
    int count;
} UserList;

void displayMenuAdmin(UserList *userList, Guest *guests, int guestCount);
void displayMenuUser(Guest *guests, int guestCount);
void printGuestData(Guest *guests, int count);
void addGuest(Guest *guests, int *count);
void editGuest(Guest *guests, int count);
void deleteGuest(Guest *guests, int *count);
void sortByRoomNumber(Guest *guests, int count);
void sortByCheckInDate(Guest *guests, int count);
void sortBySurname(Guest *guests, int count);
void filterByCheckInDate(Guest *guests, int count, char date[]);
void filterByRoomCategory(Guest *guests, int count, char category[]);
void filterByRoomNumber(Guest *guests, int count, char number[]);
void calculateTotalCost(Guest *guests, int count);
void calculateCostByCategory(Guest *guests, int count, char category[]);
void findMinCostGuest(Guest *guests, int count);

void adduser(UserList *list, UserList *new_user) {
     if (userList->count >= MAX_USERS) {
         printf("���������� ������������ ���������� �������������.\n");
         return;
     }

     printf("������� ��� ������ ������������: ");
     scanf("%s", userList->users[userList->count].username);
     printf("������� ������ ������ ������������: ");
     scanf("%s", userList->users[userList->count].password);

     userList->count++;
     printf("������������ ������� ��������.\n");
 }

int main() {
    UserList userList = {.count = 0};
    strcpy(userList.users[0].username, "admin");
    strcpy(userList.users[0].password, "adminpass");
    userList.count++;

    Guest guests[MAX_GUESTS];
    int guestCount = 0;


    displayMenuAdmin(&userList, guests, guestCount);

    return 0;
}

void displayMenuAdmin(UserList *userList, Guest *guests, int guestCount) {
    void displayAdminMenu() {
        printf("\n���� ��������������:\n");
        printf("1. �������� ������������\n");
        printf("2. ������� ������������\n");
        printf("�������� ��������: ");
        int choice;
        scanf("%d", &choice)

        UserList userList;
        switch (choice) {
            case 1:
                addUser(&userList);
                break;
            case 2:
                deleteUser(&userList);
                break;
            default:
                printf("������������ �����.\n");
                break;
        }
    }
}

void displayMenuUser(Guest *guests, int guestCount) {
    void displayUserMenu() {
        printf("\n���� ������������:\n");
        printf("1. ����������� ���������� � ������\n");
        printf("2. ����� ����� �� ���� �����������\n");
        printf("3. ����� ����� �� ��������� �������\n");
        printf("4. ����� ����� �� ������ �������\n");
        printf("�������� ��������: ");
        int choice;
        scanf("%d", &choice);

        Guest guests[MAX_GUESTS];
        int guestCount = 0;
        void readGuestDataFromFile(Guest *guests, int *count) {
            FILE *file = fopen("guests.bin", "rb");
            if (file == NULL) {
                printf("������ �������� �����.\n");
                return;
            }

            fseek(file, 0, SEEK_END);
            *count = ftell(file) / sizeof(Guest);
            rewind(file);

            fread(guests, sizeof(Guest), *count, file);
            fclose(file);
        }


        switch (choice) {
            case 1:
                printGuestData(guests, guestCount);
                break;
            case 2:
            void searchGuestByCheckInDate(Guest *guests, int count, char date[]) {
                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(guests[i].check_in_date, date) == 0) {
                        printf("����� ������:\n");
                        printf("�������: %s\n", guests[i].surname);
                        printf("���: %s\n", guests[i].firstname);
                        printf("��������: %s\n", guests[i].middlename);
                        printf("����� �������: %s\n", guests[i].room_number);
                        printf("��������� �������: %s\n", guests[i].room_category);
                        printf("���� �����������: %s\n", guests[i].check_in_date);
                        printf("���������� ����: %d\n", guests[i].stay_duration);
                        printf("���� �� �����: %.2f\n", guests[i].price_per_night);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("����� � ��������� ����� ����������� �� ������.\n");
                }
            }
                break;
            case 3:
            void searchGuestByRoomCategory(Guest *guests, int count, char category[]) {
                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(guests[i].room_category, category) == 0) {
                        printf("����� ������:\n");
                        printf("�������: %s\n", guests[i].surname);
                        printf("���: %s\n", guests[i].firstname);
                        printf("��������: %s\n", guests[i].middlename);
                        printf("����� �������: %s\n", guests[i].room_number);
                        printf("��������� �������: %s\n", guests[i].room_category);
                        printf("���� �����������: %s\n", guests[i].check_in_date);
                        printf("���������� ����: %d\n", guests[i].stay_duration);
                        printf("���� �� �����: %.2f\n", guests[i].price_per_night);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("����� � ��������� ���������� ������� �� �������.\n");
                }
            }
                break;
            case 4:
            void searchGuestByRoomNumber(Guest *guests, int count, char number[]) {
                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(guests[i].room_number, number) == 0) {
                        printf("����� ������:\n");
                        printf("�������: %s\n", guests[i].surname);
                        printf("���: %s\n", guests[i].firstname);
                        printf("��������: %s\n", guests[i].middlename);
                        printf("����� �������: %s\n", guests[i].room_number);
                        printf("��������� �������: %s\n", guests[i].room_category);
                        printf("���� �����������: %s\n", guests[i].check_in_date);
                        printf("���������� ����: %d\n", guests[i].stay_duration);
                        printf("���� �� �����: %.2f\n", guests[i].price_per_night);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("����� � ��������� ������� ������� �� �������.\n");
                }
            }
                break;
            default:
                printf("������������ �����.\n");
                break;
        }
    }
}

void printGuestData(Guest *guests, int count) {
    void printGuestData(Guest *guests, int count) {
        if (count == 0) {
            printf("��� ��������� ������ � ������.\n");
            return;
        }

        printf("���������� � ������:\n");
        for (int i = 0; i < count; i++) {
            printf("����� %d:\n", i + 1);
            printf("�������: %s\n", guests[i].surname);
            printf("���: %s\n", guests[i].firstname);
            printf("��������: %s\n", guests[i].middlename);
            printf("����� �������: %s\n", guests[i].room_number);
            printf("��������� �������: %s\n", guests[i].room_category);
            printf("���� �����������: %s\n", guests[i].check_in_date);
            printf("���������� ����: %d\n", guests[i].stay_duration);
            printf("���� �� �����: %.2f\n", guests[i].price_per_night);
            printf("\n");
        }
    }
}

void addGuest(Guest *guests, int *count) {
    void addGuest(Guest *guests, int *count) {
        if (*count >= MAX_GUESTS) {
            printf("���������� ������������ ���������� ������.\n");
            return;
        }

        printf("������� ������� �����: ");
        scanf("%s", guests[*count].surname);
        printf("������� ��� �����: ");
        scanf("%s", guests[*count].firstname);
        printf("������� �������� �����: ");
        scanf("%s", guests[*count].middlename);
        printf("������� ����� �������: ");
        scanf("%s", guests[*count].room_number);
        printf("������� ��������� �������: ");
        scanf("%s", guests[*count].room_category);
        printf("������� ���� �����������: ");
        scanf("%s", guests[*count].check_in_date);
        printf("������� ���������� ���� ����������: ");
        scanf("%d", &guests[*count].stay_duration);
        printf("������� ���� �� �����: ");
        scanf("%f", &guests[*count].price_per_night);

        (*count)++;
        printf("���������� � ����� ������� ���������.\n");
    }
}

void editGuest(Guest *guests, int count) {
    void editGuest(Guest *guests, int count) {
        if (count == 0) {
            printf("��� ��������� ������ � ������ ��� ��������������.\n");
            return;
        }

        char roomNumber[MAX_ROOM_LENGTH];
        printf("������� ����� ������� �����, ���������� � ������� �� ������ ���������������: ");
        scanf("%s", roomNumber);

        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(guests[i].room_number, roomNumber) == 0) {
                printf("������� ����� ������ ��� �����:\n");
                printf("������� �������: ");
                scanf("%s", guests[i].surname);
                printf("������� ���: ");
                scanf("%s", guests[i].firstname);
                printf("������� ��������: ");
                scanf("%s", guests[i].middlename);
                printf("������� ����� ����� �������: ");
                scanf("%s", guests[i].room_number);
                printf("������� ����� ��������� �������: ");
                scanf("%s", guests[i].room_category);
                printf("������� ����� ���� �����������: ");
                scanf("%s", guests[i].check_in_date);
                printf("������� ����� ���������� ���� ����������: ");
                scanf("%d", &guests[i].stay_duration);
                printf("������� ����� ���� �� �����: ");
                scanf("%f", &guests[i].price_per_night);
                found = 1;
                printf("���������� � ����� ������� ���������������.\n");
                break;
            }
        }

        if (!found) {
            printf("����� � ��������� ������� ������� �� ������.\n");
        }
    }
}

void deleteGuest(Guest *guests, int *count) {
    void deleteGuest(Guest *guests, int *count) {
        if (*count == 0) {
            printf("��� ��������� ������ � ������ ��� ��������.\n");
            return;
        }

        char roomNumber[MAX_ROOM_LENGTH];
        printf("������� ����� ������� �����, ���������� � ������� �� ������ �������: ");
        scanf("%s", roomNumber);

        int found = 0;
        for (int i = 0; i < *count; i++) {
            if (strcmp(guests[i].room_number, roomNumber) == 0) {
                // ���������� ��������� ������� ������ ���������� � ��������� �������
                guests[i] = guests[*count - 1];
                (*count)--;
                found = 1;
                printf("���������� � ����� ������� �������.\n");
                break;
            }
        }

        if (!found) {
            printf("����� � ��������� ������� ������� �� ������.\n");
        }
    }
}

void sortByRoomNumber(Guest *guests, int count) {
    // ���������� ���������� ���������
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                // ���������� ������ ������ � ������ �� ������� ��� �������������
                if (strcmp(guests[j].room_number, guests[j + 1].room_number) > 0) {
                    Guest temp = guests[j];
                    guests[j] = guests[j + 1];
                    guests[j + 1] = temp;
                }
            }
        }
}

void sortByCheckInDate(Guest *guests, int count) {
    void sortByCheckInDate(Guest *guests, int count) {
        // ���������� ���������� ���������
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                // ���������� ���� ����������� � ������ �� ������� ��� �������������
                if (strcmp(guests[j].check_in_date, guests[j + 1].check_in_date) > 0) {
                    Guest temp = guests[j];
                    guests[j] = guests[j + 1];
                    guests[j + 1] = temp;
                }
            }
        }
    }
}

void sortBySurname(Guest *guests, int count) {
    void sortBySurname(Guest *guests, int count) {
        // ���������� ���������� ���������
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                // ���������� ������� � ������ �� ������� ��� �������������
                if (strcmp(guests[j].surname, guests[j + 1].surname) > 0) {
                    Guest temp = guests[j];
                    guests[j] = guests[j + 1];
                    guests[j + 1] = temp;
                }
            }
        }
    }
}

void filterByCheckInDate(Guest *guests, int count, char date[]) {
    void filterByCheckInDate(Guest *guests, int count, char date[]) {
        printf("���������� ���������� �� ���� ����������� %s:\n", date);
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(guests[i].check_in_date, date) == 0) {
                printf("�������: %s\n", guests[i].surname);
                printf("���: %s\n", guests[i].firstname);
                printf("��������: %s\n", guests[i].middlename);
                printf("����� �������: %s\n", guests[i].room_number);
                printf("��������� �������: %s\n", guests[i].room_category);
                printf("���� �����������: %s\n", guests[i].check_in_date);
                printf("���������� ����: %d\n", guests[i].stay_duration);
                printf("���� �� �����: %.2f\n", guests[i].price_per_night);
                found = 1;
            }
        }

        if (!found) {
            printf("������ � ��������� ����� ����������� �� �������.\n");
        }
    }
}

void filterByRoomCategory(Guest *guests, int count, char category[]) {
    void filterByRoomCategory(Guest *guests, int count, char category[]) {
        printf("���������� ���������� �� ��������� ������� %s:\n", category);
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(guests[i].room_category, category) == 0) {
                printf("�������: %s\n", guests[i].surname);
                printf("���: %s\n", guests[i].firstname);
                printf("��������: %s\n", guests[i].middlename);
                printf("����� �������: %s\n", guests[i].room_number);
                printf("��������� �������: %s\n", guests[i].room_category);
                printf("���� �����������: %s\n", guests[i].check_in_date);
                printf("���������� ����: %d\n", guests[i].stay_duration);
                printf("���� �� �����: %.2f\n", guests[i].price_per_night);
                found = 1;
            }
        }

        if (!found) {
            printf("������ � ��������� ���������� ������� �� �������.\n");
        }
    }
}

void filterByRoomNumber(Guest *guests, int count, char number[]) {
    void filterByRoomNumber(Guest *guests, int count, char number[]) {
        printf("���������� ���������� �� ������ ������� %s:\n", number);
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(guests[i].room_number, number) == 0) {
                printf("�������: %s\n", guests[i].surname);
                printf("���: %s\n", guests[i].firstname);
                printf("��������: %s\n", guests[i].middlename);
                printf("����� �������: %s\n", guests[i].room_number);
                printf("��������� �������: %s\n", guests[i].room_category);
                printf("���� �����������: %s\n", guests[i].check_in_date);
                printf("���������� ����: %d\n", guests[i].stay_duration);
                printf("���� �� �����: %.2f\n", guests[i].price_per_night);
                found = 1;
            }
        }

        if (!found) {
            printf("������ � ��������� ������� ������� �� �������.\n");
        }
    }
}

void calculateTotalCost(Guest *guests, int count) {
    float calculateTotalCost(Guest *guests, int count) {
        float totalCost = 0.0;
        for (int i = 0; i < count; i++) {
            totalCost += guests[i].stay_duration * guests[i].price_per_night;
        }
        return totalCost;
    }
}

void calculateCostByCategory(Guest *guests, int count, char category[]) {
    float calculateCostByRoomCategory(Guest *guests, int count, char category[]) {
        float totalCost = 0.0;
        for (int i = 0; i < count; i++) {
            if (strcmp(guests[i].room_category, category) == 0) {
                totalCost += guests[i].stay_duration * guests[i].price_per_night;
            }
        }
        return totalCost;
    }
}

void findMinCostGuest(Guest *guests, int count) {
    int findGuestWithMinCost(Guest *guests, int count) {
        if (count == 0) {
            return -1; // ���������� -1 � ������ ���������� ������
        }

        int minIndex = 0;
        float minCost = guests[0].stay_duration * guests[0].price_per_night;

        for (int i = 1; i < count; i++) {
            float cost = guests[i].stay_duration * guests[i].price_per_night;
            if (cost < minCost) {
                minCost = cost;
                minIndex = i;
            }
        }

        return minIndex;