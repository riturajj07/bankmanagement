#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 50

// Structure to represent a bank account
typedef struct {
    int account_number;
    char customer_name[MAX_NAME_LENGTH];
    float balance;
} Account;

// Array to store bank accounts
Account accounts[MAX_CUSTOMERS];
int num_customers = 0;

// Function prototypes
void create_account();
void close_account();
void deposit();
void withdraw();
void transfer();
void view_account_details();

// Function to display the main menu
void display_menu() {
    printf("\nBank Management System\n");
    printf("1. Create Account\n");
    printf("2. Close Account\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Transfer\n");
    printf("6. View Account Details\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Function to create a new account
void create_account() {
    printf("\nEnter customer name: ");
    scanf("%s", accounts[num_customers].customer_name);
    accounts[num_customers].account_number = num_customers + 1;
    printf("Account created successfully. Account number is %d\n", accounts[num_customers].account_number);
    num_customers++;
}

// Function to close an existing account
void close_account() {
    int account_number;
    printf("\nEnter account number to close: ");
    scanf("%d", &account_number);

    int found = 0;
    for (int i = 0; i < num_customers; i++) {
        if (accounts[i].account_number == account_number) {
            found = 1;
            // Shift remaining accounts to fill the gap
            for (int j = i; j < num_customers - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            num_customers--;
            printf("Account closed successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Account not found.\n");
    }
}

// Function to deposit funds into an account
void deposit() {
    int account_number;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    int found = 0;
    for (int i = 0; i < num_customers; i++) {
        if (accounts[i].account_number == account_number) {
            found = 1;
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            break;
        }
    }
    if (!found) {
        printf("Account not found.\n");
    }
}

// Function to withdraw funds from an account
void withdraw() {
    int account_number;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    int found = 0;
    for (int i = 0; i < num_customers; i++) {
        if (accounts[i].account_number == account_number) {
            found = 1;
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient funds.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Account not found.\n");
    }
}

// Function to transfer funds between accounts
void transfer() {
    int from_account, to_account;
    float amount;
    printf("\nEnter account number to transfer from: ");
    scanf("%d", &from_account);
    printf("Enter account number to transfer to: ");
    scanf("%d", &to_account);
    printf("Enter amount to transfer: ");
    scanf("%f", &amount);

    int found_from = 0, found_to = 0;
    for (int i = 0; i < num_customers; i++) {
        if (accounts[i].account_number == from_account) {
            found_from = 1;
            if (accounts[i].balance >= amount) {
                for (int j = 0; j < num_customers; j++) {
                    if (accounts[j].account_number == to_account) {
                        found_to = 1;
                        accounts[i].balance -= amount;
                        accounts[j].balance += amount;
                        printf("Transfer successful.\n");
                        break;
                    }
                }
                break;
            } else {
                printf("Insufficient funds.\n");
            }
        }
    }
    if (!found_from) {
        printf("From account not found.\n");
    }
    if (!found_to) {
        printf("To account not found.\n");
    }
}

// Function to view account details
void view_account_details() {
    int account_number;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);

    int found = 0;
    for (int i = 0; i < num_customers; i++) {
        if (accounts[i].account_number == account_number) {
            found = 1;
            printf("\nAccount Number: %d\n", accounts[i].account_number);
            printf("Customer Name: %s\n", accounts[i].customer_name);
            printf("Balance: %.2f\n", accounts[i].balance);
            break;
        }
    }
    if (!found) {
        printf("Account not found.\n");
    }
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                close_account();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                transfer();
                break;
            case 6:
                view_account_details();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}