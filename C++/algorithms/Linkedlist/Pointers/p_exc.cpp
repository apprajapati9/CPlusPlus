#include<iostream>

using namespace std;

int main(){

    int a = 5; 
    int *p; // p = address, *p = value at address.

    p = &a;

    cout << p << " = P pointer value, which is address of a!" <<endl;

    cout << &a << " = Address of 'a' variable"<< endl;

    cout << &p <<" = P Pointer's own address in memory" <<endl; 
    //pointer itself lives on diff diff address
    //pointer is in the momory, and memory has an address for pointer itself too.

    cout << *p << " = *p gives value of pointer-dereferencing" << endl; 
}