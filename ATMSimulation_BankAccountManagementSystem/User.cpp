#include "User.h"

User::User(std::string username, std::string password) : username(username), password(password) {}

std::string User::getUsername() const 
{
    return username;
}

std::string User::getPassword() const 
{
    return password;
}
