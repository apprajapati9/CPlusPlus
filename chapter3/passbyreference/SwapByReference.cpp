#include <iostream>

using namespace std;

void swap( char &a, char &b);

int main(){
    char left, right;

    cout << "Left is ";
    cin >> left;

    cout << "Right is ";
    cin >> right;

    swap(left, right );

    cout << "After swap: " << endl << "left is :" << left << " right is: " << right;
}

void swap( char &a, char &b){
    char c;

    c = a;
    a = b;
    b = c;
}

// Technically, a reference is an address that cannot be changed. The compier converts the references to pointer with unmodifiable addresses, relieveing us from implementing pointer syntax explicitely within out coding.
// & operator in the prototype and function header instructs the compiler to pass by reference
