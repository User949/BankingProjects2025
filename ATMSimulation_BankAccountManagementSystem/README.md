## ATM Simulation: Bank Account Management System

## Project Description
This project is a simulation of the backend of an ATM, enabling bank account management through a console application. 
The project includes basic functionalities such as user authentication, balance checking, cash withdrawal, cash deposit, account deletion, and data storage in a file for persistence.

## Objectives
- Create a secure system for managing bank accounts.
- Implement CRUD (Create, Read, Update, Delete) operations for bank accounts.
- Learn and apply advanced C++ concepts like file handling, methods, and data manipulation.
- Use best security practices to protect confidential information.

## Project Structure

### Account Class
- Defines bank accounts and methods for authentication, balance checking, cash withdrawal, and cash deposit.
- Stores account data in a structured format for persistence.

### Bank Class
- Manages multiple bank accounts.
- Implements CRUD functionalities for accounts.
- Saves and loads account data from a file.

### User Class
- Defines user accounts with username and password.

### UserManager Class
- Manages multiple user accounts.
- Handles user registration, login, and user-related operations.

Usage
Register User: Register a new user with a username and password.

Login: Log in with a registered username and password.

Show User List: Display the list of registered users.

Search User: Search for a user by username.

Delete User: Delete a user by username.

ATM Operations:
Check Balance: View the balance of the bank account.

Withdraw: Withdraw an amount from the bank account.

Deposit: Deposit an amount into the bank account.

Delete Account: Delete the bank account.

Exit: Exit the ATM operations menu.
