#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include <vector>
#include <string>

class UserManager {
public:
    void registerUser();
    bool loginUser(std::string username, std::string password);
    void showUser();
    void searchUser(std::string username);
    void deleteUser(std::string username);

private:
    std::vector<User> users;
};

#endif
