#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>
#include <string>

class Bank {
public:
    Bank(const std::string& filename);
    ~Bank();

    void addAccount(const Account& account);
    Account* findAccount(const std::string& accountNumber);
    void updateAccount(const Account& updatedAccount);
    void deleteAccount(const std::string& accountNumber);

    void loadFromFile();
    void saveToFile();

private:
    std::string filename;
    std::vector<Account> accounts;
};

#endif