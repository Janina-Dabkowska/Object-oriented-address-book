#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

using namespace std;
class File
{
    public:
    File();
    virtual ~File();
protected:
    bool isFileEmpty(fstream &textFile);
};
#endif

