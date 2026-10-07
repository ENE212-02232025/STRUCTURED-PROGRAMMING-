/* Student Grading System - Version 2: switch-case */
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

        /* Grade using marks/10 as the switch expression */
        switch (marks / 10) {
            case 10: case 9: case 8: case 7:
                grade = 'A'; break;
            case 6:
                grade = 'B'; break;
            case 5:
                grade = 'C'; break;
            case 4:
                grade = 'D'; break;
            default:
                grade = 'F';
        }

        printf("\n---------------------------------\n");
        printf("       STUDENT INFORMATION\n");
        printf("---------------------------------\n");
        printf("Registration No: %d\n", regNo);
        printf("Name: %s\n", name);
        printf("Marks: %d\n", marks);
        printf("Grade: %c\n", grade);

        /* Pass / fail using switch on the grade */
        switch (grade) {
            case 'F':
                printf("Status: Failed\n");
                break;
            default:
                printf("Status: Passed\n");
        }
        printf("---------------------------------\n");
    }
    return 0;
}
