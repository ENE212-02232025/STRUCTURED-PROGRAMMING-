#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#define DELAY_1S() Sleep(1000)
#else
#include <unistd.h>
#define DELAY_1S() sleep(1)
#endif

#define CORRECT_PIN  "4321"
#define MAX_ATTEMPTS 3
#define LOCK_SECONDS 5

int main(void)
{
    char pin[50];
    int attempts = MAX_ATTEMPTS;
    int granted = 0;
    int choice = 0;
    int i;

    printf("=== PIN-Based Door Lock System ===\n");

    /* ---- PIN entry: 3 attempts, lockout, then retry ---- */
    while (!granted) {
        attempts = MAX_ATTEMPTS;

        while (attempts > 0 && !granted) {
            printf("\nEnter 4-digit PIN: ");
            scanf("%49s", pin);

            /* Validate PIN length with if-else-if */
            if (strlen(pin) < 4) {
                printf("PIN is too short (must be 4 digits)\n");
            } else if (strlen(pin) > 4) {
                printf("PIN is too long (must be 4 digits)\n");
            } else {
                printf("PIN is exactly 4 digits\n");
            }

            /* Check correctness (only a 4-digit PIN can match) */
            if (strcmp(pin, CORRECT_PIN) == 0) {
                granted = 1;
            } else {
                attempts--;
                printf("Incorrect PIN. Remaining attempts: %d\n", attempts);
            }
        }

        if (!granted) {
            printf("\nSystem locked! Wait for %d seconds...\n", LOCK_SECONDS);
            for (i = LOCK_SECONDS; i >= 1; i--) {
                printf("%d... ", i);
                fflush(stdout);
                DELAY_1S();
            }
            printf("\nYou can try again now.\n");
        }
    }

    /* ---- Device menu ---- */
    do {
        printf("\n=== Device Menu ===\n");
        printf("1. Open Door\n");
        printf("2. Change Username\n");
        printf("3. Change PIN\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {   /* non-numeric input */
            scanf("%*s");
            choice = -1;
        }

        switch (choice) {
            case 1:
                printf("Access granted. Door unlocked\n");
                break;
            case 2:
                printf("Change username feature coming soon.\n");
                break;
            case 3:
                printf("Change PIN feature coming soon.\n");
                break;
            case 4:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
