#include <stdio.h>

int main(void) {
    int n, value, pos;
    printf("Input the size of array : ");
    scanf("%d", &n);
    if (n <= 0) { printf("Invalid size.\n"); return 1; }

    int arr[n + 1];  /* one extra slot for the inserted value */
    printf("Input %d elements in the array :\n", n);
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Input the value to be inserted : ");
    scanf("%d", &value);
    printf("Input the Position, where the value to be inserted : ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position. Must be between 1 and %d.\n", n + 1);
        return 1;
    }

    printf("The current list of the array : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    /* Shift elements right to make room (position is 1-based) */
    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = value;
    n++;

    printf("\nAfter Insert the element the new list is : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
