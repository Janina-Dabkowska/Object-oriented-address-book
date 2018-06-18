#ifndef ADDRESSEE_H
#define ADDRESSEE_H
#include <iostream>
using namespace std;
class Addressee
{
private:
    int id;
    int userId;
    string name;
    string surname;
    string phoneNumber;
    string email;
    string address;
public:
    Addressee();
    virtual ~Addressee();
    int getId();
    int getUserId();
    string getName();
    string getSurname();
    string getPhoneNumber();
    string getEmail();
    string getAddress();
    void setId(int id);
    void setUserId(int userId);
    void setName(string name);
    void setSurname(string surname);
    void setPhoneNumber(string phoneNumber);
    void setEmail(string email);
    void setAddress(string address);
};
#endif

