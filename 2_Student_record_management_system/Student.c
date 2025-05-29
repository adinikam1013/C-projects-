#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.dat"

typedef struct {
    int roll;
    char name[50];
    float marks;
} Student;

void addStudent() {
    Student s;
    FILE *fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        printf("File error.\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    printf("Enter name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student added successfully.\n");
}

void displayStudents() {
    Student s;
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("Roll: %d\nName: %s\nMarks: %.2f\n\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    int roll;
    int found = 0;
    Student s;
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll == roll) {
            printf("Record found:\nRoll: %d\nName: %s\nMarks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");

    fclose(fp);
}

void updateStudent() {
    int roll, found = 0;
    Student s;
    FILE *fp = fopen(FILENAME, "rb+");
    if (fp == NULL) {
        printf("File error.\n");
        return;
    }

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll == roll) {
            printf("Existing Record:\nName: %s\nMarks: %.2f\n", s.name, s.marks);
            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            printf("Record updated.\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");

    fclose(fp);
}

void deleteStudent() {
    int roll, found = 0;
    Student s;
    FILE *fp = fopen(FILENAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL) {
        printf("File error.\n");
        return;
    }

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.roll == roll) {
            found = 1;
        } else {
            fwrite(&s, sizeof(Student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.dat", FILENAME);

    if (found)
        printf("Record deleted.\n");
    else
        printf("Student not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Record Management ---\n");
        printf("1. Add Student\n2. Display All Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
