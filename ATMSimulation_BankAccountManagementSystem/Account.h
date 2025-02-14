#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    Account(std::string accountNumber, std::string pin, double balance);

    bool authenticate(std::string enteredPin);
    double getBalance() const;
    bool withdraw(double amount);
    void deposit(double amount);

    std::string getAccountNumber() const;
    std::string toString() const;
    static Account fromString(const std::string& data);

private:
    std::string accountNumber;
    std::string pin;
    double balance;
};

#endif