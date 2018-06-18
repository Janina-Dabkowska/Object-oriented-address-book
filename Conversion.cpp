#include "Conversion.h"

using namespace std;
Conversion::Conversion(){;}
Conversion::~Conversion(){;}
string Conversion::intToString(int intCount)
{
    ostringstream ss;
    ss << intCount;
    string str = ss.str();

    return str;
}
int Conversion::stringToInt(string text)
{
    return atoi(text.c_str());
}
string Conversion::changeFirstLetterToupperOtherTolower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
