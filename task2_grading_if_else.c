/* Student Grading System - Version 1: if-else if-else */
#include <stdio.h>

int main(void)
{
    int n, i;
    int regNo, marks;
    char name[50];
    char grade;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("\n--- Student %d ---\n", i);
        printf("Registration number: ");
        scanf("%d", &regNo);
        printf("Name: ");
        scanf(" %49[^\n]", name);
        do {
            printf("Marks (0-100): ");
            scanf("%d", &marks);
            if (marks < 0 || marks > 100)
                printf("Invalid marks! Try again.\n");
        } while (marks < 0 || marks > 100);

        /* Determine grade */
        if (marks >= 70)      grade = 'A';
        else if (marks >= 60) grade = 'B';
        else if (marks >= 50) grade = 'C';
        else if (marks >= 40) grade = 'D';
        else                  grade = 'F';

        printf("\n---------------------------------\n");
        printf("       STUDENT INFORMATION\n");
        printf("---------------------------------\n");
        printf("Registration No: %d\n", regNo);
        printf("Name: %s\n", name);
        printf("Marks: %d\n", marks);
        printf("Grade: %c\n", grade);

        /* Pass / fail */
        if (marks >= 40)
            printf("Status: Passed\n");
        else
            printf("Status: Failed\n");
        printf("---------------------------------\n");
    }
    return 0;
}
