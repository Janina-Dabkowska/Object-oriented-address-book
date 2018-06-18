#ifndef CONVERSION_H
#define CONVERSION_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include<algorithm>

using namespace std;
class Conversion
{
public:
    Conversion();
    virtual ~Conversion();
    string intToString(int intCount);
    int stringToInt(string text);
    string changeFirstLetterToupperOtherTolower(string text);
};
#endif

