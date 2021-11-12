#include <iostream>

//Pointer arithmetic

using namespace std;

void printValsInt(int *p){
    
    cout << "P = " << p << endl; 
    cout << "p+1 = " << p+1 << endl;
    cout << "*p = " << *p << endl; 
    cout << "*p + 1 = " << *p + 1 <<endl; 
    cout << "*(p+1) = " << *(p+1) << endl; 
    cout << "*(p+2) = " << *(p+2) << endl;

    cout << "*(p+2) +1 = " << *(p+2) +1 << endl; //7
   
    //Trick to remember is that Pointer arithmtic is jumping from
    // pointer one address to another in this case... p+1= pointer address + 1, next address
    //value arithmetic happens when you deref 
}

void printValsChar(char *p){
    
    cout << "P = " << p << endl; 
    cout << "p+1 = " << p+1 << endl;
    cout << "*p = " << *p << endl; 
    cout << "*p + 1 = " << *p + 1 <<endl; 
    cout << "*(p+1) = " << *(p+1) << endl; 
    cout << "*p + 2 = " << *p + 2 <<endl;
    cout << "*(p+2) = " << *(p+2) << endl; 

    cout << "*(p+2) +1 = " << *(p+2) +1 << endl; 
}


int main(){

    int i_a[5] = {2,4,6,8,10};
    char c_a[5] = {'a', 'b', 'c', 'd', '\0'};
    
    //int *p = a;
    //char *p = a;
    
    //cout << "Address of &a[0] = " << &a[0] <<endl;
    //cout << "Address of &a[1] = " << &a[1] <<endl;

    //Diff between int and char is significant. please remember/understand.
    cout << "---------------------------------" <<endl;
    printValsChar(c_a);
    cout << "---------------------------------" <<endl;
    printValsInt(i_a);
    
    return 0;
}