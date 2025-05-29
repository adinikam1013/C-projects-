#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "library.txt"

typedef struct {
    int book_id;
    char title[100];
    char borrower[100];
    char issue_date[11];  // Format: DD-MM-YYYY
    char due_date[11];    // Format: DD-MM-YYYY
} Book;

void addBook() {
    Book b;
    FILE *fp = fopen(FILENAME, "a");

    if (fp == NULL) {
        printf("File error.\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &b.book_id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter Borrower's Name: ");
    scanf(" %[^\n]", b.borrower);
    printf("Enter Issue Date (DD-MM-YYYY): ");
    scanf("%s", b.issue_date);
    printf("Enter Due Date (DD-MM-YYYY): ");
    scanf("%s", b.due_date);

    fprintf(fp, "%d|%s|%s|%s|%s\n", b.book_id, b.title, b.borrower, b.issue_date, b.due_date);
    fclose(fp);

    printf("Book record added.\n");
}

void viewBooks() {
    Book b;
    FILE *fp = fopen(FILENAME, "r");

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Issued Books ---\n");
    while (fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%[^\n]\n", &b.book_id, b.title, b.borrower, b.issue_date, b.due_date) == 5) {
        printf("Book ID: %d\nTitle: %s\nBorrower: %s\nIssue Date: %s\nDue Date: %s\n\n",
               b.book_id, b.title, b.borrower, b.issue_date, b.due_date);
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book Entry\n2. View Issued Books\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
