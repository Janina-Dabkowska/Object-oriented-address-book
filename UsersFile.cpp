#include "UsersFile.h"

using namespace std;
UsersFile::UsersFile()
{
    fileNameWithUsers = "Uzytkownicy.txt";
}
UsersFile::~UsersFile()
{
    ;
}
void  UsersFile::loadUsersFromFile(vector<User> &users)
{
    User user;
    string oneUserData = "";
    fstream textFile;
    textFile.open(fileNameWithUsers.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, oneUserData))
        {
            user = getUserData (oneUserData);
            users.push_back(user);
        }
        textFile.close();
    }
}
void UsersFile::saveAllUsersToTextFile( vector<User> &users)
{
    string lineWithUserData ="";
    fstream textFile;
    textFile.open(fileNameWithUsers.c_str(), ios::out);
    if (textFile.good())
    {
        int countUsers = users.size();
        for (int i=0; i<countUsers; i++)
        {
            lineWithUserData = changeUserDataToLine(users[i]);
            if (i<countUsers-1)
                textFile << lineWithUserData << endl;
            else
                textFile << lineWithUserData ;
        }
        textFile.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " <<fileNameWithUsers<< endl;
    }
}

string UsersFile::changeUserDataToLine(User user)
{
    string lineWithUserData = "";
    Conversion conversion;
    lineWithUserData += conversion.intToString(user.getId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';
    return lineWithUserData;
}
void UsersFile::addUserToTextFile(User user)
{
    fstream textFile;
    string lineWithUserData = "";
    textFile.open(fileNameWithUsers.c_str(), ios::out | ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = changeUserDataToLine(user);
        if (isFileEmpty(textFile) == true)
        {
            textFile << lineWithUserData;
        }
        else
        {
            textFile << endl << lineWithUserData ;
        }
        textFile.close();

    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku " << fileNameWithUsers <<" i zapisac w nim danych."<<endl;
    }
}
User   UsersFile::getUserData(string userData)
{
    User user;
    string oneUserData = "";
    int oneUserDataNumber = 1;
    Conversion conversion;

    for (unsigned int positionOfSign = 0; positionOfSign < userData.size(); positionOfSign++)
    {
        if (userData[positionOfSign] != '|')
        {
            oneUserData += userData[positionOfSign];
        }
        else
        {
            switch(oneUserDataNumber)
            {
            case 1:
                user.setId(conversion.stringToInt(oneUserData)) ;
                break;
            case 2:
                user.setLogin (oneUserData);
                break;
            case 3:
                user.setPassword(oneUserData);
                break;
            }
            oneUserData = "";
            oneUserDataNumber++;
        }
    }
    return user;
}
