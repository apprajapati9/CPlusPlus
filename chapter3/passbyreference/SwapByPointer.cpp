#include <iostream>

using namespace std;

void swap( char *a, char *b);

int main(){
    char left, right;

    cout << "Left is ";
    cin >> left;

    cout << "Right is ";
    cin >> right;

    swap(&left, &right );

    cout << "After swap: " << endl << "left is :" << left << " right is: " << right;
}

void swap( char *a, char *b){
    char c;

    c = *a;
    *a = *b;
    *b = c;
}