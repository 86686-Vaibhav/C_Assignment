#include <stdio.h>
#include <string.h>

// Define the Student structure
struct Student {
    char studentName[50];
    char rollNo[20];  // Roll number can be alphanumeric
    int totalMarks;
};

// Function to input student details
void inputStudentDetails(struct Student *student) {
    printf("Enter student name: ");
    fgets(student->studentName, sizeof(student->studentName), stdin);
    // Remove trailing newline from fgets
    student->studentName[strcspn(student->studentName, "\n")] = 0;

    printf("Enter roll number: ");
    fgets(student->rollNo, sizeof(student->rollNo), stdin);
    student->rollNo[strcspn(student->rollNo, "\n")] = 0;

    printf("Enter total marks: ");
    scanf("%d", &student->totalMarks);
}

// Function to display student details
void displayStudentDetails(struct Student student) {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student.studentName);
    printf("Roll Number: %s\n", student.rollNo);
    printf("Total Marks: %d\n", student.totalMarks);
}

int main() {
    struct Student student;

    // Input student details
    inputStudentDetails(&student);

    // Display student details
    displayStudentDetails(student);

    return 0;
}
