#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "File.h"
#include "User.h"

#include "Conversion.h"
using namespace std;
class UsersFile : private File
{
private:

    string  fileNameWithUsers;
public:
    UsersFile();
    virtual ~UsersFile();
    void loadUsersFromFile(vector<User> &users);
    void addUserToTextFile(User user);
    void saveAllUsersToTextFile( vector<User> &users);
private:
    string changeUserDataToLine(User user);
    User getUserData(string userData);
};
#endif

