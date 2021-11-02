#include<bits/stdc++.h>

using namespace std;

/*
    to demonstrate basics of Pointers
*/
void simplePointer(){
    int var = 20;

    //declaration of pointer variable
    int *ptr;
    
    ptr = &var;  //pointer is a memory address of a variable
    //Note: Data type of ptr and variable MUST be thes same. int pointer to int var

    cout<< "Value at ptr= " << ptr << endl;  
    //pointer address
    
    cout << "Value at var= " <<var << endl;
    // to access value of var

    cout << "Value at ptr*= " << *ptr <<endl; 
    // ptr* to get the value of pointer itself

}

//pass by value
int square(int n){

    cout << "Address of n1 in square(): " << &n << endl;

    n *= n;  //n = n*n;
    return n;
}

//Pass by reference with Pointer args
void square2(int *n){

    //Address of n in Square2 and Main() n2, is the same.  
    cout << "Address of n in square2() " << n <<endl;

    //Explicit dereferencing to get the value pointed to
    *n *= *n;  // n* = *n * n*;

    /* no need to return because it changes value from address
    so one variable is accessed from variable and changed so this change
    would affect n2 in main method as well. */
}

void square3(int &n){
    //address of n in square3() is the same as in main() n3 which was passed here
    cout << "Address of n3 in square3() " << &n << endl;

    // implicit deferencing (without *)
    n *= n; 
}


int main(){

    cout << endl << "------------------Simple pointer -------------------" << endl << endl;
    simplePointer();

    cout << endl << "----------------- Pass by Value --------------------" << endl << endl;

    // Pass by value
    int n1 = 10;
    cout <<"Address of n1 in main() :" << &n1 <<endl;
    cout << square(n1) << endl;
    cout << "No change in n1 in main() " << n1 << endl;
    /*it passes value and in function, new different var is allocated
       in the function to perform operation and returned but it doesn't 
       change the original variable that was passed by main() function. 
       address are different is the proof of that. 
    */
    cout << endl << "------ Call by reference with Pointer args----------" << endl << endl;

    int n2= 20;
    cout << "Address of n2 in main" << &n2 <<endl;
    square2(&n2);
    cout<<"Square on n2: (changed in main too)" << n2 << endl;

    cout << endl << "------ Call by reference with reference args----------" << endl << endl;

    int n3 = 9;
    cout << "Address of n3 in main()" << &n3 <<endl;
    square3(n3);
    cout << "n3  value in main =" <<n3 <<endl;

    /*
    Note: 
    If wish to modify the original copy directly 
    (especially in passing huge object or array) and/or 
    avoid the overhead of cloning, we use pass-by-reference. 
    Pass-by-Reference with Reference Arguments does not require 
    any clumsy syntax for referencing and dereferencing.
    */

   /*
    Null pointers poits nowhere and you can do it this two ways
    int *ptr1 = 0;  
    int *ptr2 = NULL; 

   */
}