#include <iostream>

using namespace std;

bool isPalindrome(int number)
{
    if (number < 0 || number != 0 && number%10 == 0)
    {
        return false; // Negative numbers aren't palindrome
    }

    if (number == 0)
    {
        return true;
    }

    int original = number;
    int reverseNum = 0;

    while (number > 0)
    {
        int digit = number % 10;
        reverseNum = reverseNum * 10 + digit;
        number /= 10;
    }
  
    return original == reverseNum;
}

bool isPalin(int x)
{
    if (x < 0 || (x != 0 && x % 10 == 0))
    { // 120%10=0 - this condition really important to elimi
        return false;
    }

    int check = 0;
    while (x > check)
    {
        check = check * 10 + x % 10;
        // digit=123 --> 1 - 0+3 =3, 3*10+2 = 32
        // digit=121 --> 1 - 0+1 =1, 1*10+2= 12
        x /= 10;
        // digit=123 --> x=12, x=1
        // digit=121 --> x=12,x=1
    }
    return (x == check || x == check / 10);
}

bool isPalindromeByDivision(int number){

    if(number < 0 || number != 0 && number%10 == 0)
        return false;

    int div = 1;
    while(number >= 10*div){
        div *= 10;  //To find base of 10 in order to get first digit.
    }
    //cout << "div=" << div <<endl;

    while(number > 0) {
        if(number % 10 != number / div)
            return false;

        number = (number%div) / 10; 
        // (n%div) gives us remainder. essentially getting remainder and then dividing to get last digit
        div /= 100;
    }
    return true;
}



int main()
{
    // 0 false, 1 true
    int value = 101;
    cout << "is value= " << value << " Palindrome? " << (isPalin(value) ? "true" : "false") << endl;
    cout << "is value= " << value << " Palindrome? " << (isPalindrome(value) ? "true" : "false") << endl;

    cout << "is value= " << value << " Palindrome? " << (isPalindromeByDivision(value) ? "true" : "false") << endl;
    return 0;
}

//Run this to test.
void experimentProof()
{
    for (int i = 1; i <= 1000; i++)
    {
        if (i % 10 == 0)
        {
            cout << i << " is divided by 10 so cannot be palindrome!" << endl;
        }
    }
    //basicall x%10 == 0  -> means that if last digit of a number is 0 then it cannot be palindrom
    // because positive numbers don't have leading 0s.
    //120 - last digit can be found by 120%10=0 which means it cannot be palindrome.
}