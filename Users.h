#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <windows.h>
#include <vector>
#include "User.h"
#include "UsersFile.h"


using namespace std;
class Users
{
private:
    vector<User> users;
    int loggedUserId;
    UsersFile usersFile;
public:
    Users();
    virtual ~Users();
    int getLoggedUserId();
    void userLogging();
    void userRegistration();
    void changePassword();
    void logout();
    void endOff();
private:

    User giveNewUserData();
    int getNewUserId();
    bool isLogin(string login);
    string inputPassword();
};
#endif
