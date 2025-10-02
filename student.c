#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.txt", "a");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]s", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%d %s %d %.2f\n", s.id, s.name, s.age, s.marks);
    fclose(fp);

    printf("✅ Student added successfully!\n");
}

void displayStudents() {
    struct Student s;
    FILE *fp = fopen("students.txt", "r");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("\n---- Student Records ----\n");
    while (fscanf(fp, "%d %s %d %f", &s.id, s.name, &s.age, &s.marks) != EOF) {
        printf("ID: %d | Name: %s | Age: %d | Marks: %.2f\n", s.id, s.name, s.age, s.marks);
    }
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
