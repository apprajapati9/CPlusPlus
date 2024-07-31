#include <iostream>

using namespace std;

bool isNegative(char s)
{
    return s == '-';
}

bool checkIfValid(string s)
{

    int index = isNegative(s[0]) ? 1 : 0;
    for (int i = index; i < s.size(); i++)
    {
        int num = s[i];
        if (num < 48 || num > 57) // 45 being - negative
        {
            return false; // invalid.
        }
    }

    return true; // valid num
}

void stringToNum(string s, int size)
{
    bool neg = isNegative(s[0]);

    if (!checkIfValid(s))
    {
        cout << "Not a valid number" << endl;
        return;
    }

    int num = 0;
    int index = neg ? 1 : 0;
    for (int i = index; i < size; i++)
    {
        num = num * 10 + (s[i] - '0');
    }
    if (neg)
    {
        num *= -1;
    }
    cout << "Converted Num " << num << endl;
}

void printASCIIOfNums()
{
    cout << endl
         << "Printing Ascii value of 0-9" << endl;
    for (int i = 0; i <= 9; i++)
    {
        int num = (char)i + '0';
        cout << num << endl;
    }
}

int main()
{
    string name = "12323";

    // printASCIIOfNums();  //If want to test printing ASCII of 1-9
    
    stringToNum(name, name.size());
    
    return 0;
}