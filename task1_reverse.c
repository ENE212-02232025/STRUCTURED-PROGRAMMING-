#include <stdio.h>

int main(void) {
    int n;
    printf("Input the number of elements to store in the array : ");
    scanf("%d", &n);
    if (n <= 0) { printf("Invalid size.\n"); return 1; }

    int arr[n];
    printf("Input %d number of elements in the array :\n", n);
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("The values store into the array are : ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    printf("\nThe values store into the array in reverse are : ");
    for (int i = n - 1; i >= 0; i--) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
