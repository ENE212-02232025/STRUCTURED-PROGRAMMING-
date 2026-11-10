
#include <stdio.h>
#include <stdbool.h>

// Function declarations
bool login(void);
void showMenu(void);
void checkBalance(double balance);
double deposit(double balance);
double withdraw(double balance);

int main()
{
    double balance = 5000.00;
    int choice;

    printf("================================\n");
    printf("       WELCOME TO ATM SYSTEM\n");
    printf("================================\n");

    // Verify user PIN
    if (!login())
    {
        printf("\nAccess denied. Exiting system.\n");
        return 0;
    }

    printf("\nLogin successful!\n");

    // ATM menu loop
    do
    {
        showMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                checkBalance(balance);
                break;

            case 2:
                balance = deposit(balance);
                break;

            case 3:
                balance = withdraw(balance);
                break;

            case 4:
                printf("\nThank you for using our ATM.\n");
                printf("Please visit again!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// Function to verify PIN
bool login(void)
{
    int storedPIN = 7889;
    int enteredPIN;
    int attempts = 0;

    while (attempts < 3)
    {
        printf("\nEnter your PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN == storedPIN)
        {
            return true;
        }
        else
        {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n",
                   3 - attempts);
        }
    }

    return false;
}

// Function to display ATM menu
void showMenu(void)
{
    printf("\n========== ATM MENU ==========\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
    printf("==============================\n");
}

// Function to check account balance
void checkBalance(double balance)
{
    printf("\nYour current balance is: Ksh %.2f\n", balance);
}

// Function to deposit money
double deposit(double balance)
{
    double amount;

    printf("\nEnter amount to deposit: Ksh ");
    scanf("%lf", &amount);

    if (amount > 0)
    {
        balance += amount;

        printf("Deposit successful!\n");
        printf("New balance: Ksh %.2f\n", balance);
    }
    else
    {
        printf("Invalid amount. Deposit must be positive.\n");
    }

    return balance;
}

// Function to withdraw money
double withdraw(double balance)
{
    double amount;

    printf("\nEnter amount to withdraw: Ksh ");
    scanf("%lf", &amount);

    if (amount <= 0)
    {
        printf("Invalid amount. Enter a positive amount.\n");
    }
    else if (amount > balance)
    {
        printf("Insufficient balance!\n");
    }
    else
    {
        balance -= amount;

        printf("Withdrawal successful!\n");
        printf("Remaining balance: Ksh %.2f\n", balance);
    }

    return balance;
}

