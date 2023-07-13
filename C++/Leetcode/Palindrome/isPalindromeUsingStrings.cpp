#include <iostream>

using namespace std;

/*
9. Leetcode - Palindrome number
Given an integer x, return true if x is a palindrome and false otherwise.

Examples: 
Input : x= 121 
output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Input: x = 10
Output: false.

Follow up question: Do it without convering number to a string. 
*/

void reverseString(string &str)
{
    int length = str.length();
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

string reverseStringWithoutSwap(string str)
{
    // can also do below way but it requires another sting which means more space occupied.
    string reverse;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reverse += str[i];
    }
    return reverse;
}

string numberToString(int number)
{

    string str;

    bool isNegative = false;

    if (number == 0)
    {              // edge case when you are trying to convert number into a string.
        str = "0"; // important thing- the number 0 doesn't have a sign so -0,+0 and 0 are identical.

        // bool is = 0 == -0;
        // cout << is << endl;  // --> 1 = True.
    }

    // This is to handle negative value only.
    if (number < 0)
    {
        isNegative = true;
        number = -number;
        // When unary minus operator is applied to a number, it changes the sign of that number
        // if the number number is positive, it becomes negative and negative becomes positive.
    }

    while (number > 0)
    {
        char digit = '0' + number % 10;
        number = number / 10;
        str += digit;
    }
    // string reverse;  //Try seperating this to a function to learn how to pass strings.
    // for (int i = str.length()-1; i >= 0; i--) {
    //     reverse += str[i];
    // }

    if (isNegative)
    {
        str = '-' + str;
    }

    return str;
}

bool isPalindrome(int x)
{
    string number = numberToString(x);
    if (number == reverseStringWithoutSwap(number))
    {
        return true;
    }
    return false;
}

int main()
{
    // 0=false, 1=true in bool
    int value = 1122211;
    cout << "NumberToString() function= " << numberToString(value) << endl;
    cout << "reverseStringWithoutSwap() function= " << reverseStringWithoutSwap(numberToString(value)) << endl;
    cout << "isPalindrome() function= " << isPalindrome(value) << endl;

    string swap = "123";
    cout << "Swap to reverse string function test--> value= " << swap << endl;
    reverseString(swap);
    cout << "Reverse string with swap=" << swap << endl;

    return 0;
}

/*
CHAR:

char is needed to convert digits into a string because characters are the building blocks of strings.
When we perform arithmetic operations on integers, the result is a numeric value.
To convert this numeric value to its corresponding character representation, we need to add it to the
ASCII value of the character '0'; It's called character encoding.

ASCII value of '0' is 48, 1-49,2-50, and so on.
So

char digit = '0' + number; // 48+5 = 53 = 5; so the number is 5.

a few helpful starters :  0 - 48, A-65, a-97

You cannot convert a big number 2 digits number therefore we need to perform %/ operations to
separate digits and then convert it into a string.

*/