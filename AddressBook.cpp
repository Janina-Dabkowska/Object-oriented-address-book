#include "AddressBook.h"

using namespace std;
AddressBook::AddressBook(int userId)
{
    this->idOfLastAddressee = idOfLastAddressee;
    this->idOfLastAddressee = addresseesFile.loadAddresseesFromFile(addressBook, userId);
}
AddressBook::~AddressBook()
{
    addressBook.clear();
}
void AddressBook::setIdOfLastAddressee(int idOfLastAddressee)
{
    this->idOfLastAddressee = idOfLastAddressee;
}
int AddressBook::getIdOfLastAddressee()
{
    return idOfLastAddressee;
}

void AddressBook::sortAddressBook(vector<Addressee> &addressBook)
{
    sort(addressBook.begin(), addressBook.end(),[](Addressee& first, Addressee& second)
    {
        if ( first.getSurname() == second.getSurname())
            return (first.getName() < second.getName());
        else
            return (first.getSurname() < second.getSurname());
    } );
}

void AddressBook::displayAllAddressees()
{
    system("cls");
    if (!addressBook.empty())
    {
        sortAddressBook(addressBook);

        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;

        for (vector <Addressee> :: iterator itr = addressBook.begin(); itr != addressBook.end(); itr++)
        {
            displayAddresseeData(*itr);
        }
        cout << endl;

        cout << "Ilosc osob zapisanych w twojej ksiazce adresowej wynosi: " << addressBook.size() << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}
void AddressBook::displayAddresseeData(Addressee addressee)
{
    cout << endl << "Id:                 " << addressee.getId() << endl;
    cout << "Imie:               " << addressee.getName() << endl;
    cout << "Nazwisko:           " << addressee.getSurname() << endl;
    cout << "Numer telefonu:     " << addressee.getPhoneNumber() << endl;
    cout << "Email:              " << addressee.getEmail() << endl;
    cout << "Adres:              " << addressee.getAddress() << endl;
}
void AddressBook::searchByName()
{
    string searchedName = "";
    int addresseesConut = 0;
    Conversion conversion;

    system("cls");
    if (!addressBook.empty())
    {
        sortAddressBook(addressBook);
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        cin >> searchedName;
        searchedName = conversion.changeFirstLetterToupperOtherTolower(searchedName);

        for (vector <Addressee>::iterator  itr = addressBook.begin(); itr != addressBook.end(); itr++)
        {
            if (itr ->Addressee::getName() == searchedName)
            {
                displayAddresseeData(*itr);
                addresseesConut++;
            }
        }
        displayNumberOfSearchedAddesssees(addresseesConut);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}
void AddressBook:: searchBySurname()
{
    string searchedSurname = "";
    int addresseesConut = 0;
    Conversion conversion;

    system("cls");
    if (!addressBook.empty())
    {
        sortAddressBook(addressBook);
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        cin >> searchedSurname;
        searchedSurname = conversion.changeFirstLetterToupperOtherTolower(searchedSurname);

        for (vector <Addressee>::iterator  itr = addressBook.begin(); itr != addressBook.end(); itr++)
        {
            if (itr ->Addressee::getSurname() == searchedSurname)
            {
                displayAddresseeData(*itr);
                addresseesConut++;
            }
        }
        displayNumberOfSearchedAddesssees(addresseesConut);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}
void AddressBook::displayNumberOfSearchedAddesssees(int addresseesConut)
{
    if (addresseesConut == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << addresseesConut << endl << endl;
}
Addressee AddressBook::inputNewAddresseeData(int loggedUserId)
{
    Addressee addressee;
    string data;
    Conversion conversion;
    addressee.setId(++idOfLastAddressee);
    addressee.setUserId(loggedUserId);

    cout << "Podaj imie: ";
    cin >> data;
    addressee.setName(conversion.changeFirstLetterToupperOtherTolower(data));

    cout << "Podaj nazwisko: ";
    cin >> data;
    addressee.setSurname(conversion.changeFirstLetterToupperOtherTolower(data));

    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin, data);
    addressee.setPhoneNumber(data);

    cout << "Podaj email: ";
    cin >> data;
    addressee.setEmail(data);

    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, data);
    addressee.setAddress(data);

    return addressee;
}
void AddressBook::addAddressee(int loggedUserId)
{
    Addressee addressee;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    addressee = inputNewAddresseeData(loggedUserId);

    addressBook.push_back(addressee);

    addresseesFile.addAddresseeToTextFile(addressee);

    idOfLastAddressee++;
}

int AddressBook::inputIdOfChosenAddressee()
{
    int idOfChosenAddressee = 0;
    do
    {
        cin.clear();
        cin.sync();

        cout << "Podaj numer ID Adresata: ";
        cin >> idOfChosenAddressee;
    }
    while (cin.fail() == true);

    return idOfChosenAddressee;
}
void AddressBook::deleteAddressee()
{
    int deletedAddresseeId = 0;
    int lineNumberOfdeletedAddressee = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    deletedAddresseeId = inputIdOfChosenAddressee();

    char sign;
    bool isAddressee = false;

    for (vector <Addressee>::iterator itr = addressBook.begin(); itr != addressBook.end(); itr++)
    {
        if (itr ->Addressee::getId() == deletedAddresseeId)
        {
            isAddressee = true;
            displayAddresseeData(*itr);
            cout << endl << "Czy na pewno chcesz usunac powyzszego adresata? 't/n'";
            cin >> sign;
            if (sign == 't')
            {
                lineNumberOfdeletedAddressee = addresseesFile.returnLineNumberOfSearchedAddressee(deletedAddresseeId);
                cout<<lineNumberOfdeletedAddressee<<endl;
                Sleep(1000);
                addresseesFile.deleteChosenLineInFile(lineNumberOfdeletedAddressee);
                itr = addressBook.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                if (idOfLastAddressee == deletedAddresseeId)
                    idOfLastAddressee--;
                break;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (isAddressee == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

char AddressBook::chooseOptionFromEditMenu(Addressee addressee)
{
    char choice;
    cout << endl << "   >>> DANE ADRESATA <<<" << endl;
    displayAddresseeData(addressee);
    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    cin >> choice;

    return choice;
}

void AddressBook::editAddressee()
{
    system("cls");
    Conversion conversion;
    string liniaZDanymiAdresata = "";
    string data;
    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    int editAddresseeId = inputIdOfChosenAddressee();
    char choice;
    bool isAddressee = false;
    system("cls");
    for (vector <Addressee>::iterator itr = addressBook.begin(); itr != addressBook.end(); itr++)
    {
        if (itr -> Addressee::getId() == editAddresseeId)
        {
            isAddressee = true;
            do
            {
                choice = chooseOptionFromEditMenu(*itr);

                switch (choice)
                {
                case '1':
                    cout << "Podaj nowe imie: ";
                    cin >> data;
                    itr -> Addressee::setName(conversion.changeFirstLetterToupperOtherTolower(data));
                    updateAddresseeData(*itr, editAddresseeId);

                    break;
                case '2':
                    cout << "Podaj nowe nazwisko: ";
                    cin >> data;
                    itr -> Addressee::setSurname(conversion.changeFirstLetterToupperOtherTolower(data));
                    updateAddresseeData(*itr, editAddresseeId);

                    break;
                case '3':
                    cout << "Podaj nowy numer telefonu: ";
                    cin.sync();
                    getline(cin, data);
                    itr -> Addressee::setPhoneNumber(data);
                    updateAddresseeData(*itr, editAddresseeId);
                    break;
                case '4':
                    cout << "Podaj nowy email: ";
                    cin >> data;
                    itr -> Addressee::setEmail(data);
                    updateAddresseeData(*itr, editAddresseeId);
                    break;
                case '5':
                    cout << "Podaj nowy adres zamieszkania: ";
                    cin.sync();
                    getline(cin, data);
                    itr -> Addressee::setAddress(data);
                    updateAddresseeData(*itr, editAddresseeId);
                    break;
                case '6':
                    cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                    break;
                }
                system("pause");
                system("cls");
            }
            while(choice!='6');
        }
    }
    if (isAddressee == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
        system("pause");
    }
}
void AddressBook::updateAddresseeData(Addressee addressee, int editAddresseeId)
{
    int lineNumberOfEditAddressee = 0;
    string lineWithAddressseData = "";

    lineNumberOfEditAddressee = addresseesFile.returnLineNumberOfSearchedAddressee(editAddresseeId);
    lineWithAddressseData = addresseesFile.changeAddresseeDataToLine(addressee);
    addresseesFile.editChosenLineInFile(lineNumberOfEditAddressee, lineWithAddressseData);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

