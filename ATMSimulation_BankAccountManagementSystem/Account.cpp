#include "Account.h"
#include <sstream>

Account::Account(std::string accountNumber, std::string pin, double balance) : accountNumber(accountNumber), pin(pin), balance(balance) {}

bool Account::authenticate(std::string enteredPin) 
{
    return pin == enteredPin;
}

double Account::getBalance() const 
{
    return balance;
}

bool Account::withdraw(double amount) 
{
    if (amount > balance) 
        return false;
    balance -= amount;
    return true;
}

void Account::deposit(double amount) 
{
    balance += amount;
}

std::string Account::getAccountNumber() const 
{
    return accountNumber;
}

std::string Account::toString() const 
{
    return accountNumber + "," + pin + "," + std::to_string(balance);
}

Account Account::fromString(const std::string& data) 
{
    std::stringstream ss(data);
    std::string accountNumber, pin, balanceStr;
    getline(ss, accountNumber, ',');
    getline(ss, pin, ',');
    getline(ss, balanceStr, ',');
    return Account(accountNumber, pin, std::stod(balanceStr));
}
