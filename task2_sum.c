#include <stdio.h>

int main(void) {
    int n, sum = 0;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);
    if (n <= 0) { printf("Invalid size.\n"); return 1; }

    int arr[n];
    printf("Input %d elements in the array :\n", n);
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum of all elements stored in the array is : %d\n", sum);
    return 0;
}
