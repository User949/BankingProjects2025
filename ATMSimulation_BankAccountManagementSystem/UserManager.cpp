#include "UserManager.h"
#include <iostream>

void UserManager::registerUser() 
{
    std::string username, password;
    std::cout << "\t\tEnter User Name: ";
    std::cin >> username;
    std::cout << "\t\tEnter Password: ";
    std::cin >> password;

    User newUser(username, password);
    users.push_back(newUser);

    std::cout << "\t\tUser Register Successfully ...." << std::endl;
}

bool UserManager::loginUser(std::string username, std::string password) 
{
    for (const auto& user : users) 
    {
        if (user.getUsername() == username && user.getPassword() == password) 
        {
            std::cout << "\t\tLogin Successfully ...." << std::endl;
            return true;
        }
    }
    std::cout << "\t\tInvalid User Name or Password ...." << std::endl;
    return false;
}

void UserManager::showUser() 
{
    std::cout << "\t\t---Users List---" << std::endl;
    for (const auto& user : users) {
        std::cout << "\t\t" << user.getUsername() << std::endl;
    }
}

void UserManager::searchUser(std::string username) 
{
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            std::cout << "\t\tUser Found" << std::endl;
            return;
        }
    }
    std::cout << "\t\tUser Not Found" << std::endl;
}

void UserManager::deleteUser(std::string username) 
{
    auto it = std::remove_if(users.begin(), users.end(),
        [&username](const User& user) {
            return user.getUsername() == username;
        });
    if (it != users.end()) 
    {
        users.erase(it, users.end());
        std::cout << "\t\tUser Removed Successfully...." << std::endl;
    }
    else
        std::cout << "\t\tUser Not Found" << std::endl;
}