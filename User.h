#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;
class User
{

private:
    int id;
    string login;
    string password;

public:
    User();
    virtual ~User();
    int getId();
    string getLogin();
    string getPassword();
    void setId(int id);
    void setLogin(string login);
    void setPassword(string password);
};

#endif
