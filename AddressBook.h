#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include <algorithm>
#include <windows.h>
#include <vector>
#include "Addressee.h"
#include "AddresseesFile.h"
#include "Users.h"


using namespace std;

class AddressBook
{
private:
    vector <Addressee> addressBook;
    int idOfLastAddressee;
    AddresseesFile addresseesFile;
public:
    AddressBook(int userId);
    virtual ~AddressBook();
    void setIdOfLastAddressee(int idOfLastAddressee);
    int getIdOfLastAddressee();
    void addAddressee(int loggedUserId);
    void searchByName();
    void searchBySurname();
    void displayAllAddressees();
    void deleteAddressee();
    void editAddressee();
    void sortAddressBook(vector<Addressee> &addressBook);

private:

    void displayAddresseeData(Addressee addressee);
    void displayNumberOfSearchedAddesssees(int addresseesConut);
    Addressee inputNewAddresseeData(int loggedUserId);
    int inputIdOfChosenAddressee();
    char chooseOptionFromEditMenu(Addressee addressee);
    void updateAddresseeData(Addressee addressee, int editAddresseeId);


};

#endif // ADDRESSBOOK_H

