#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "bank.txt"

typedef struct {
    int acc_no;
    char name[50];
    float balance;
} Account;

void createAccount() {
    Account a;
    FILE *fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        printf("File error.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &a.acc_no);
    printf("Enter Name: ");
    scanf(" %[^\n]", a.name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &a.balance);

    fprintf(fp, "%d %s %.2f\n", a.acc_no, a.name, a.balance);
    fclose(fp);
    printf("Account created successfully.\n");
}

void displayBalance() {
    int acc_no, found = 0;
    Account a;
    FILE *fp = fopen(FILENAME, "r");

    if (fp == NULL) {
        printf("No account found.\n");
        return;
    }

    printf("Enter Account Number to view balance: ");
    scanf("%d", &acc_no);

    while (fscanf(fp, "%d %s %f", &a.acc_no, a.name, &a.balance) == 3) {
        if (a.acc_no == acc_no) {
            printf("Account Holder: %s\nBalance: %.2f\n", a.name, a.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}

void depositMoney() {
    int acc_no, found = 0;
    float amount;
    Account a;
    FILE *fp = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("File error.\n");
        return;
    }

    printf("Enter Account Number to deposit into: ");
    scanf("%d", &acc_no);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    while (fscanf(fp, "%d %s %f", &a.acc_no, a.name, &a.balance) == 3) {
        if (a.acc_no == acc_no) {
            a.balance += amount;
            found = 1;
        }
        fprintf(temp, "%d %s %.2f\n", a.acc_no, a.name, a.balance);
    }

    fclose(fp);
    fclose(temp);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found)
        printf("Deposit successful.\n");
    else
        printf("Account not found.\n");
}

void withdrawMoney() {
    int acc_no, found = 0;
    float amount;
    Account a;
    FILE *fp = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("File error.\n");
        return;
    }

    printf("Enter Account Number to withdraw from: ");
    scanf("%d", &acc_no);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    while (fscanf(fp, "%d %s %f", &a.acc_no, a.name, &a.balance) == 3) {
        if (a.acc_no == acc_no) {
            if (a.balance >= amount) {
                a.balance -= amount;
                found = 1;
            } else {
                printf("Insufficient balance.\n");
                found = -1;
            }
        }
        fprintf(temp, "%d %s %.2f\n", a.acc_no, a.name, a.balance);
    }

    fclose(fp);
    fclose(temp);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found == 1)
        printf("Withdrawal successful.\n");
    else if (found == 0)
        printf("Account not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Bank Management System ---\n");
        printf("1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Display Balance\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayBalance(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
