#include <iostream>
#include <new>

using namespace std;

int main(){
    int i, n;

    int * p ; // pointer to store

    cout << "How many numbers would you like to type? ";
    cin >> i;

    p = new (nothrow) int[i]; // will allocate pointer memory for i block
    if( p == nullptr){
        cout << "Error: Memory couldn't be allocated";
    }else{
        for (n = 0; n < i; n++){
            cout << "Enter number : ";
            cin >> p[n];
        }    
        cout << "you have entered : ";
        for( n = 0; n < i; n++){
            cout << p[n] << ", ";
        }
        delete[] p;
    }
    return 0;
}