#include "File.h"

using namespace std;

File::File() {;}

File::~File() {;}
bool File::isFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}
