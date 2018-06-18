#include "Addressee.h"

using namespace std;

Addressee::Addressee()
{
    id = 0;
    userId = 0;
    name = "";
    surname = "";
    phoneNumber = "";
    email = "";
    address= "";
}
Addressee::~Addressee()
{
    ;
}
int Addressee::getId()
{
    return id;
}
int Addressee::getUserId()
{
    return userId;
}
string Addressee::getName()
{
    return name;
}
string Addressee::getSurname()
{
    return surname;
}
string Addressee::getPhoneNumber()
{
    return phoneNumber;
}
string Addressee::getEmail()
{
    return email;
}
string Addressee::getAddress()
{
    return address;
}
void Addressee::setId(int id)
{
    this->id = id;
}
void Addressee::setUserId(int userId)
{
    this->userId = userId;
}
void Addressee::setName(string name)
{
    this->name = name;
}
void Addressee::setSurname(string surname)
{
    this->surname = surname;
}
void Addressee::setEmail(string email)
{
    this->email= email;
}
void Addressee::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
void Addressee::setAddress(string address)
{
    this->address= address;
}

