#include <stdio.h>

#define BUFFER_SIZE 5   /* change to 10 (or any size) as needed */

static int buffer[BUFFER_SIZE];
static int head  = 0;   /* index where the next sample will be written */
static int count = 0;   /* number of valid samples stored (<= BUFFER_SIZE) */

/* Insert a new sample; overwrites the oldest one when the buffer is full */
void insert_sample(int value) {
    buffer[head] = value;
    head = (head + 1) % BUFFER_SIZE;
    if (count < BUFFER_SIZE) count++;
}

/* Print samples from oldest to newest */
void print_samples(void) {
    if (count == 0) {
        printf("Buffer is empty.\n");
        return;
    }
    /* If full, the oldest sample sits at head; otherwise at index 0 */
    int start = (count == BUFFER_SIZE) ? head : 0;
    printf("Samples (oldest -> newest): ");
    for (int i = 0; i < count; i++)
        printf("%d ", buffer[(start + i) % BUFFER_SIZE]);
    printf("\n");
}

int main(void) {
    int choice, value;

    do {
        printf("\n--- Circular Data Logger (size %d) ---\n", BUFFER_SIZE);
        printf("1. Insert a sample\n");
        printf("2. Print samples (chronological)\n");
        printf("3. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter sensor value: ");
                if (scanf("%d", &value) == 1) insert_sample(value);
                break;
            case 2:
                print_samples();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}
