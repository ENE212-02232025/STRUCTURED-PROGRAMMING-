#include <stdio.h>

#define ROWS 6
#define COLS 4

int main(void) {
    int arr[ROWS][COLS];

    /* Initialize: each element = row * COLS + col + 1  (1..24) */
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            arr[i][j] = i * COLS + j + 1;

    /* Traverse and print every element */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("arr[%d][%d] = %2d   ", i, j, arr[i][j]);
        printf("\n");
    }
    return 0;
}
