#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[50];
    int roomNumber;
    int days;
    float rate;
};

void bookRoom() {
    FILE *fp = fopen("records.txt", "a");
    struct Customer c;

    printf("Enter Customer Name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter Room Number: ");
    scanf("%d", &c.roomNumber);
    printf("Enter Number of Days: ");
    scanf("%d", &c.days);
    printf("Enter Room Rate per Day: ");
    scanf("%f", &c.rate);

    fprintf(fp, "%s %d %d %.2f\n", c.name, c.roomNumber, c.days, c.rate);
    fclose(fp);

    printf("Room Booked Successfully!\n");
}

void viewCustomers() {
    FILE *fp = fopen("records.txt", "r");
    struct Customer c;

    printf("\n--- Current Customers ---\n");
    while (fscanf(fp, " %[^\n] %d %d %f", c.name, &c.roomNumber, &c.days, &c.rate) != EOF) {
        printf("Name: %s | Room: %d | Days: %d | Rate: %.2f\n", c.name, c.roomNumber, c.days, c.rate);
    }

    fclose(fp);
}

void checkOut() {
    int room;
    int found = 0;

    printf("Enter Room Number for Check-out: ");
    scanf("%d", &room);

    FILE *fp = fopen("records.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    struct Customer c;

    while (fscanf(fp, " %[^\n] %d %d %f", c.name, &c.roomNumber, &c.days, &c.rate) != EOF) {
        if (c.roomNumber == room) {
            float bill = c.days * c.rate;
            printf("\nCustomer %s checked out.\n", c.name);
            printf("Total Bill: %.2f\n", bill);
            found = 1;
        } else {
            fprintf(temp, "%s %d %d %.2f\n", c.name, c.roomNumber, c.days, c.rate);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("records.txt");
    rename("temp.txt", "records.txt");

    if (!found) {
        printf("Room not found!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n====== Hotel Management System ======\n");
        printf("1. Book Room\n");
        printf("2. View All Customers\n");
        printf("3. Check-Out Customer\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bookRoom(); break;
            case 2: viewCustomers(); break;
            case 3: checkOut(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
