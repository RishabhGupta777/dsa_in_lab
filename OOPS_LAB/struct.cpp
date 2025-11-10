#include <stdio.h>

// Define a structure for Student
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    struct Student s1;  // Declare a structure variable

    // Input student details
    printf("Enter name: ");
    

    printf("Enter roll number: ");
    scanf("%d", &s1.rollNumber);

    printf("Enter marks: ");
    scanf("%f", &s1.marks);

    // Display student details
    printf("\n--- Student Information ---\n");
    printf("Name: %s", s1.name);
    printf("Roll Number: %d\n", s1.rollNumber);
    printf("Marks: %.2f\n", s1.marks);

    return 0;
}
