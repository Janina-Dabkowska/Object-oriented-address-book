#include "AddresseesFile.h"

using namespace std;
AddresseesFile::AddresseesFile()
{
    fileNameWithAddressees = "Adresaci.txt";
}
AddresseesFile::AddresseesFile(string fileName)
{
    fileNameWithAddressees = fileName;
}
AddresseesFile::~AddresseesFile()
{
    ;
}
int AddresseesFile::loadAddresseesFromFile(vector<Addressee> &addressBook, int userId)
{
    Addressee addressee;
    string oneAddresseeData = "";
    int idOfLastAddressee = 0;
    string dataOfLastAddressee = "";
    fstream textFile;
    textFile.open(fileNameWithAddressees.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, oneAddresseeData))
        {

            if(userId == getUserIdFromDataLine(oneAddresseeData) )
            {
                addressee = getAddresseeFromDataLine(oneAddresseeData);
                addressBook.push_back(addressee);
            }
        }
        dataOfLastAddressee = oneAddresseeData;
        textFile.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
    if (dataOfLastAddressee != "")
    {
        idOfLastAddressee = getAddresseeIdFromDataLine(dataOfLastAddressee);
        return idOfLastAddressee;
    }
    else
        return 0;
}
int AddresseesFile::getAddresseeIdFromDataLine(string oneAddresseeData)
{
    Conversion conversion;
    int positionOfNumber = 0;
    int addresseeId = conversion.stringToInt(getNumber(oneAddresseeData, positionOfNumber));
    return addresseeId;
}
int AddresseesFile::getUserIdFromDataLine( string addresseeData)
{
    Conversion conversion;
    int userIdInt;
    string userIdString = "";

    int positionOfNumber = addresseeData.find_first_of('|') + 1;
    userIdInt = conversion.stringToInt(getNumber(addresseeData, positionOfNumber));
    return  userIdInt;
}
string AddresseesFile::getNumber(string text, int positionOfSign)
{
    string number= "";
    while(isdigit(text[positionOfSign]) == true)
    {
        number += text[positionOfSign];
        positionOfSign ++;
    }
    return number;
}

Addressee AddresseesFile::getAddresseeFromDataLine(string addresseeData)
{
    Addressee addressee;
    string oneAddresseeData = "";
    int oneAddresseeDataNumber = 1;
    Conversion conversion;

    for (unsigned int positionOfSign = 0; positionOfSign < addresseeData.size(); positionOfSign++)
    {
        if (addresseeData[positionOfSign] != '|')
        {
            oneAddresseeData += addresseeData[positionOfSign];
        }
        else
        {
            switch(oneAddresseeDataNumber)
            {
            case 1:
                addressee.setId(conversion.stringToInt(oneAddresseeData)) ;
                break;
            case 2:
                addressee.setUserId (conversion.stringToInt(oneAddresseeData));
                break;
            case 3:
                addressee.setName(oneAddresseeData);
                break;
            case 4:
                addressee.setSurname(oneAddresseeData);
                break;
            case 5:
                addressee.setPhoneNumber(oneAddresseeData);
                break;
            case 6:
                addressee.setEmail(oneAddresseeData);
                break;
            case 7:
                addressee.setAddress(oneAddresseeData);
                break;
            }

            oneAddresseeData = "";
            oneAddresseeDataNumber++;
        }
    }
    return addressee;

}

void AddresseesFile::addAddresseeToTextFile(Addressee addressee)

{
    string lineWithAddresseData = "";
    fstream textFile;
    textFile.open(fileNameWithAddressees.c_str(), ios::out | ios::app);

    if (textFile.good() == true)
    {
        lineWithAddresseData = changeAddresseeDataToLine(addressee);

        if (isFileEmpty(textFile) == true)
        {
            textFile << lineWithAddresseData;
        }
        else
        {
            textFile << endl << lineWithAddresseData ;
        }
        textFile.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    system("pause");
}
string AddresseesFile::changeAddresseeDataToLine(Addressee addressee)
{
    Conversion conversion;
    string lineWithAddresseeData = "";
    lineWithAddresseeData += conversion.intToString(addressee.getId()) + '|';
    lineWithAddresseeData += conversion.intToString(addressee.getUserId()) + '|';
    lineWithAddresseeData += addressee.getName() + '|';
    lineWithAddresseeData += addressee.getSurname() + '|';
    lineWithAddresseeData += addressee.getPhoneNumber() + '|';
    lineWithAddresseeData += addressee.getEmail() + '|';
    lineWithAddresseeData += addressee.getAddress() + '|';
    return lineWithAddresseeData;
}
int AddresseesFile::returnLineNumberOfSearchedAddressee(int addresseeId)
{
    bool isAddressee = false;
    int lineNumberInTextFile = 1;
    string oneAddresseeDataInLine = "";
    fstream textFile;
    textFile.open(fileNameWithAddressees.c_str(), ios::in);

    if (textFile.good() == true && addresseeId != 0)
    {
        while(getline(textFile, oneAddresseeDataInLine))
        {
            if(addresseeId == getAddresseeIdFromDataLine(oneAddresseeDataInLine))
            {
                isAddressee = true;
                textFile.close();
                return lineNumberInTextFile;
            }
            else
                lineNumberInTextFile++;
        }
        if (isAddressee == false)
        {
            textFile.close();
            return 0;
        }
    }
    return 0;
}
void AddresseesFile::deleteChosenLineInFile(int deletedLineNumber)//usunWybranaLinieWPliku(int deletedLineNumber)
{
    fstream readTextFile, temporaryTextFile;
    string readLine = "";
    int readLineNumber = 1;
    AddresseesFile temporaryFile ("Adresaci_tymczasowo.txt");
    readTextFile.open(fileNameWithAddressees.c_str(), ios::in);
    temporaryTextFile.open(temporaryFile.fileNameWithAddressees.c_str(), ios::out | ios::app);

    if (readTextFile.good() == true && deletedLineNumber != 0)
    {
        while (getline(readTextFile, readLine))
        {
            // Tych przypadkow jest tyle, gdyz chcemy osiagnac taki efekt,
            // aby na koncu pliku nie bylo pustej linii
            if (readLineNumber == deletedLineNumber) {}
            else if (readLineNumber == 1 && readLineNumber != deletedLineNumber)
                temporaryTextFile << readLine;
            else if (readLineNumber == 2 && deletedLineNumber == 1)
                temporaryTextFile << readLine;
            else if (readLineNumber > 2 && deletedLineNumber == 1)
                temporaryTextFile << endl << readLine;
            else if (readLineNumber > 1 && deletedLineNumber != 1)
                temporaryTextFile << endl << readLine;
            readLineNumber++;
        }
        readTextFile.close();
        temporaryTextFile.close();

        deleteReadFile(fileNameWithAddressees);
        changeTemporaryFileNameToReadFileName(temporaryFile.fileNameWithAddressees.c_str(), fileNameWithAddressees);
    }
}
void AddresseesFile::deleteReadFile(string fileNameWithExtension)//usunOdczytywanyPlik(string nazwaPlikuZRozszerzeniem)//usunOdczytywanyPlik
{
    if (remove(fileNameWithExtension.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << fileNameWithExtension << endl;
}

void AddresseesFile::changeTemporaryFileNameToReadFileName(string temporaryFileNameWithExtension, string fileNameWithExtension)//zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem)//zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku
{
    if (rename(temporaryFileNameWithExtension.c_str(), fileNameWithExtension.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << fileNameWithExtension << endl;
}
////////////////////////////////////////////////////////

void AddresseesFile::editChosenLineInFile(int editLineNumber, string lineWithAddressseData)
{
    fstream readTextFile,temporaryTextFile;
    string readLine = "";
    int readLineNumber = 1;
    AddresseesFile temporaryFile ("Adresaci_tymczasowo.txt");
    readTextFile.open(fileNameWithAddressees.c_str(), ios::in);
    temporaryTextFile.open(temporaryFile.fileNameWithAddressees.c_str(), ios::out | ios::app);

    if (readTextFile.good() == true)
    {
        while (getline(readTextFile, readLine))
        {
            if (readLineNumber == editLineNumber)
            {
                if (readLineNumber == 1)
                    temporaryTextFile << lineWithAddressseData;
                else if (readLineNumber > 1)
                    temporaryTextFile << endl << lineWithAddressseData;
            }
            else
            {
                if (readLineNumber == 1)
                    temporaryTextFile << readLine;
                else if (readLineNumber > 1)
                    temporaryTextFile << endl << readLine;
            }
            readLineNumber++;
        }
        readTextFile.close();
        temporaryTextFile.close();

        deleteReadFile(fileNameWithAddressees);
        changeTemporaryFileNameToReadFileName(temporaryFile.fileNameWithAddressees, fileNameWithAddressees);
    }
}


