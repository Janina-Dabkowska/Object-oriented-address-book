#ifndef ADDRESSEESFILE_H
#define ADDRESSEESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "File.h"
#include "Addressee.h"

#include "Conversion.h"
using namespace std;

class AddresseesFile : private File
{
private:
    string  fileNameWithAddressees;

public:
    AddresseesFile();
    AddresseesFile(string fileName);
    virtual ~AddresseesFile();
    int loadAddresseesFromFile(vector<Addressee> &addressBook, int userId);
    void addAddresseeToTextFile(Addressee addressee);
    int returnLineNumberOfSearchedAddressee(int addresseeId);
    void deleteChosenLineInFile(int deletedLineNumber);
    string changeAddresseeDataToLine(Addressee addressee);
    void editChosenLineInFile(int editLineNumber, string lineWithAddressseData);

private:
    Addressee getAddresseeFromDataLine(string addresseeData);
    int getUserIdFromDataLine( string addresseeData);
    int getAddresseeIdFromDataLine(string oneAddresseeData);
    string getNumber(string text, int positionOfSign);
    void deleteReadFile(string fileNameWithExtension);
    void changeTemporaryFileNameToReadFileName(string temporaryFileNameWithExtension, string fileNameWithExtension);
};

#endif // ADDRESSEESFILE_H

