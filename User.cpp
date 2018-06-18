#include "User.h"

using namespace std;

User::User()
{
    id = 0;
    login = "";
    password = "";
}
User::~User() {;}
int User::getId()
{
    return id;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
void User::setId(int id)
{
    this->id = id;
}
void User::setLogin(string login)
{
    this->login = login;
}
void User::setPassword(string password)
{
    this->password = password;
}
