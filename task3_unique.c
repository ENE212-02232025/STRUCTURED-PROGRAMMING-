#include <stdio.h>

int main(void) {
    int n;
    printf("Print all unique elements of an array:\n");
    printf("------------------------------------------\n");
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);
    if (n <= 0) { printf("Invalid size.\n"); return 1; }

    int arr[n];
    printf("Input %d elements in the array :\n", n);
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("The unique elements found in the array are: ");
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (arr[i] == arr[j]) count++;
        if (count == 1) printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
