#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MAX_NAME_LENGTH 50

// Function to compare two strings (used for qsort)
int compareNames(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    char nameOfStudents[MAX_STUDENTS][MAX_NAME_LENGTH];
    int numOfStudents;

    // Input the number of students
    printf("Enter the number of students (up to %d): ", MAX_STUDENTS);
    scanf("%d", &numOfStudents);
    getchar(); // Consume the newline character after entering the number

    if (numOfStudents > MAX_STUDENTS) {
        printf("You can enter a maximum of %d students.\n", MAX_STUDENTS);
        return 1;
    }

    // Input names of students
    printf("Enter the names of students:\n");
    for (int i = 0; i < numOfStudents; i++) {
        printf("Student %d: ", i + 1);
        fgets(nameOfStudents[i], sizeof(nameOfStudents[i]), stdin);
        nameOfStudents[i][strcspn(nameOfStudents[i], "\n")] = 0; // Remove trailing newline
    }

    // Sort the array of student names
    qsort(nameOfStudents, numOfStudents, MAX_NAME_LENGTH, compareNames);

    // Display the sorted names
    printf("\nSorted Names of Students:\n");
    for (int i = 0; i < numOfStudents; i++) {
        printf("%s\n", nameOfStudents[i]);
    }

    return 0;
}
