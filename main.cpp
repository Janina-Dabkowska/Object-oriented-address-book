#include <iostream>
#include "Users.h"
#include "AddressBook.h"

using namespace std;

char chooseOptionFromMainMenu();
char chooseOptionFromLoggedUserMenu();

int main()
{
    Users users ;
    char choice;
    while(1)
    {
        if(users.getLoggedUserId() == 0)
        {
            choice = chooseOptionFromMainMenu();
            switch (choice)
            {
            case '1':
                users.userRegistration();
                break;
            case '2':
                users.userLogging();
                break;
            case '9':
                users.endOff();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else if (users.getLoggedUserId()>0)
        {
            AddressBook addressBook(users.getLoggedUserId());
            choice = chooseOptionFromLoggedUserMenu();
            switch (choice)
            {
            case '1':
                addressBook.addAddressee(users.getLoggedUserId());
                break;
            case '2':
                addressBook.searchByName();
                break;
            case '3':
                addressBook.searchBySurname();
                break;
            case '4':
                addressBook.displayAllAddressees();
                break;
            case '5':
                addressBook.deleteAddressee();
                break;
            case '6':
                addressBook.editAddressee();
                break;
            case '7':
                users.changePassword();
                break;
            case '8':
                users.logout();
                break;
            }
        }
    }
    return 0;
}
char chooseOptionFromMainMenu()
{
    char choice;
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> choice;
    cin.ignore();

    return choice;
}
char chooseOptionFromLoggedUserMenu()
{
    char choice;
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> choice;
    cin.ignore();
    return choice;
}
