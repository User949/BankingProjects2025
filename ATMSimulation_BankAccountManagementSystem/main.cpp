#include <iostream>
#include <string>
#include "Bank.h"
#include "UserManager.h"

void displayMenu() 
{
    std::cout << "\n\n\t\t1. Register User" << std::endl;
    std::cout << "\t\t2. Login" << std::endl;
    std::cout << "\t\t3. Show User List" << std::endl;
    std::cout << "\t\t4. Search User" << std::endl;
    std::cout << "\t\t5. Delete User" << std::endl;
    std::cout << "\t\t6. Exit" << std::endl;
    std::cout << "\t\tEnter Your Choice: ";
}

void displayATMMenu() 
{
    std::cout << "\n\n\t\t1. Check balance" << std::endl;
    std::cout << "\t\t2. Withdraw" << std::endl;
    std::cout << "\t\t3. Deposit" << std::endl;
    std::cout << "\t\t4. Delete account" << std::endl;
    std::cout << "\t\t5. Exit" << std::endl;
    std::cout << "\t\tEnter Your Choice: ";
}

void pause() 
{
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void handleATMOperations(Bank& bank, Account* account) 
{
    std::string pin;
    std::cout << "Enter PIN: ";
    std::cin >> pin;
    if (!account->authenticate(pin)) 
    {
        std::cout << "Invalid PIN." << std::endl;
        return;
    }

    int atmChoice;
    do {
        system("cls");
        displayATMMenu();
        std::cin >> atmChoice;

        switch (atmChoice) {
        case 1:
            std::cout << "Balance: " << account->getBalance() << std::endl;
            pause();
            break;
        case 2: {
            double amount;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            if (amount <= 0) {
                std::cout << "Invalid amount." << std::endl;
                pause();
                break;
            }
            if (account->withdraw(amount)) {
                bank.updateAccount(*account);
                std::cout << "Withdraw successful." << std::endl;
            }
            else {
                std::cout << "Insufficient balance." << std::endl;
            }
            pause();
            break;
        }
        case 3: {
            double amount;
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            if (amount <= 0) {
                std::cout << "Invalid amount." << std::endl;
                pause();
                break;
            }
            account->deposit(amount);
            bank.updateAccount(*account);
            std::cout << "Deposit successful." << std::endl;
            pause();
            break;
        }
        case 4:
            bank.deleteAccount(account->getAccountNumber());
            std::cout << "Account deleted." << std::endl;
            atmChoice = 5; // Exit ATM menu
            pause();
            break;
        case 5:
            bank.saveToFile();
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            pause();
        }
    } while (atmChoice != 5);
}

int main() 
{
    UserManager userManager;
    Bank bank("accounts.csv");

    std::string choice;
    int op;

    do {
        system("cls");
        displayMenu();
        std::cin >> op;
        switch (op) {
        case 1:
            userManager.registerUser();
            break;
        case 2: {
            std::string username, password;
            std::cout << "\t\tEnter User: ";
            std::cin >> username;
            std::cout << "\t\tEnter Password: ";
            std::cin >> password;
            if (userManager.loginUser(username, password)) 
            {
                Account* account = bank.findAccount(username);
                if (!account) 
                {
                    std::cout << "Account not found for user. Do you want to create a new bank account? (y/n): ";
                    char createChoice;
                    std::cin >> createChoice;
                    if (createChoice == 'y' || createChoice == 'Y') 
                    {
                        std::cout << "Enter PIN: ";
                        std::string pin;
                        std::cin >> pin;
                        bank.addAccount(Account(username, pin, 0.0));
                        std::cout << "Bank account created." << std::endl;
                        account = bank.findAccount(username);
                    }
                    else
                        break;
                }

                if (account) 
                    handleATMOperations(bank, account);
            }
            break;
        }
        case 3:
            userManager.showUser();
            break;
        case 4: {
            std::string username;
            std::cout << "\t\tEnter User Name: ";
            std::cin >> username;
            userManager.searchUser(username);
            break;
        }
        case 5: {
            std::string username;
            std::cout << "\t\tEnter User: ";
            std::cin >> username;
            userManager.deleteUser(username);
            break;
        }
        case 6:
            exit(0);
        default:
            std::cout << "Invalid choice." << std::endl;
        }
        std::cout << "\t\tDo You Want to Continue [Yes/No]? ";
        std::cin >> choice;
    } while (choice == "y" || choice == "Y" || choice == "Yes" || choice == "yes");

    return 0;
}