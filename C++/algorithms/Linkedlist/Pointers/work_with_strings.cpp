#include <iostream>

using namespace std;

void printCharArray(char* str){ //*str = A, str pointer address passed here.
    /*
    //1st way
    int i = 0;
    while (str[i] != '\0'){
        cout << str[i] << endl;
        i++;
    }
    */
    while (*str != '\0'){  //deref so A, J, A Y  will come 
        cout << *str << endl; 
        str++; // str has add value, so address++ will move on to next char address.
    }
}

int main(){
    char c[5];
    c[0] = 'A';
    c[1] = 'J';
    c[2] = 'A';
    c[3] = 'Y';
    c[4] = '\0';
    cout << "C= " << c << endl; 
    /* when you don't end string with \0 null character, 
    it will print undesirable values in output for example mine was = AJAY▒@  chars,
    so always have string null terminated. */

    //below syntax already uses null termination automatically
    char c2[] = "AJAY";
    //cout << "C2= " << c2 << endl; //Null char isn't counted in length.

    //
    printCharArray(c2); // c2[0] address is passed, pass by ref by default for array
    /*
    when you do = char *c2 = "AJAY"; 
    throws below warning: 
    warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
     char *c2 = "AJAY";
    
    warning can be ignored but they give you important information so follow that n remember.
    */
}