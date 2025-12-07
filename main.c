#include <stdio.h>
#include <stdlib.h>


// LOGIN FUNCTION

int login() {
    const int correctPIN = 2005;
    int enteredPIN;
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN == correctPIN) {
            printf("Login successful!\n");
            return 1;   // True
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n", 3 - attempts);
        }
    }

    // If user uses all attempts
    return 0;   // False
}
// MAIN PROGRAM

int main() {
    float balance = 5000.00;   // Initial balance
    int choice;
    float amount;

    printf("=== Welcome to the ATM System ===\n");

    if (!login()) {
        printf("Access denied. Exiting program...\n");
        return 0;
    }

    // Menu loop
    do {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Your current balance is: %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Deposit successful! New balance: %.2f\n", balance);
                } else {
                    printf("Invalid deposit amount!\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > balance) {
                    printf("Insufficient funds!\n");
                } else if (amount <= 0) {
                    printf("Invalid withdrawal amount!\n");
                } else {
                    balance -= amount;
                    printf("Withdrawal successful! New balance: %.2f\n", balance);
                }
                break;

            case 4:
                printf("Thank you for using the ATM.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
