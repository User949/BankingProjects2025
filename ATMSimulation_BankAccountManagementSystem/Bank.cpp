#include "Bank.h"
#include <fstream>
#include <algorithm>

Bank::Bank(const std::string& filename) : filename(filename) 
{
    loadFromFile();
}

Bank::~Bank() 
{
    saveToFile();
}

void Bank::addAccount(const Account& account) 
{
    accounts.push_back(account);
}

Account* Bank::findAccount(const std::string& accountNumber) 
{
    for (auto& account : accounts) 
    {
        if (account.getAccountNumber() == accountNumber)     
            return &account;
    }
    return nullptr;
}

void Bank::updateAccount(const Account& updatedAccount) 
{
    for (auto& account : accounts) 
    {
        if (account.getAccountNumber() == updatedAccount.getAccountNumber()) 
        {
            account = updatedAccount;
            return;
        }
    }
}

void Bank::deleteAccount(const std::string& accountNumber) 
{
    auto it = std::remove_if(accounts.begin(), accounts.end(), [&accountNumber](const Account& account) {
            return account.getAccountNumber() == accountNumber; 
        });
    accounts.erase(it, accounts.end());
}

void Bank::loadFromFile() 
{
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) 
    {
        accounts.push_back(Account::fromString(line));
    }
}

void Bank::saveToFile() 
{
    std::ofstream file(filename);
    for (const auto& account : accounts)
        file << account.toString() << "\n";
}
