#include <stdio.h>
#include <iostream>

/*
Example to understand why we need a pointer to a pointer.
 
 */

using namespace std; 

void cant_change(int * x, int * z){
    x = z;
    cout << "cant_change() = Value of a inside cant_change function " << x << " and " << z << endl;
    cout << "cant_change() = Inside can't change function change will stay the same outside of this function scope?" << endl;

    cout << "can't change() = address of pointer a= " << &x << endl;
}

void change(int ** x, int * z){
    *x = z; 
    //dereferecing pointer to a pointer... **x = *x

    cout << "Change() = a's value inside change() a= " << *x  << " but because of pointer to pointer, this change should be take effect in main() too." << endl;
    cout << endl;
    cout << "Change() = address of pointer a= " << &*x << endl; 
    // &*x = address of pointer pointing to (*x) 

}

void p2p_using_function(){
    int c = 1;
    int d = 2;
    int e = 3;

    int * a = &c;
    int * b = &d;
    int * f = &e;
    int ** pp = &a;  // pointer to pointer 'a'

    cout << "Main() = a' value= " << a << endl;
    cout << "Main() = b' value= " << b << endl;
    cout << "Main() = f' value= " << f << endl;

    cout << endl;

    cout << "Main() = a' address= " << &a << endl;
    cout << "Main() = b' address= " << &b << endl;
    cout << "Main() = f' address= " << &f << endl;
    
    cout << endl;
    
    cout << "Main() = c' address= " << &c << endl;
    cout << "Main() = d' address= " << &d << endl;
    cout << "Main() = e' address= " << &e << endl;

    cout << endl;
 
    cout << "Main() = Can we change a pointer? Let's see" << endl;
    cout << endl;
    cout << "Main() = operation performing a = b" << endl;
    cout << endl;
    a = b;
    cout << "Main() = a' value after a = b is =" << a << " = Same as b's value"  << endl;
    cout << endl;
    cout << "Main() = a and b dereference, a= " << *a << " and b=" << *b << endl;
    
    cout << endl;
    cout << "Main() = Can we perfom change in a function?" << endl;  
    
    cout << endl;
    cout << "Main() = Calling cant_change(a, f) function." << endl;

    cant_change(a, f);  // Passing pointers so can be regarded as *a, pass by value but for pointers
    //can think of this as *a, so duplicate values are stored in function scope.

    //lets print pointer's address so the picture can be clearer
    cout << endl;
    cout << "Main() = address of pointer a " << &a << endl; 
    
    cout << endl;
    cout << "Main() = value of a outside of can't cange function scope is " << a << endl;
    
    cout << endl;
    cout << "Main() = outside of cant_change function, a's value hasn't changed. it is same as a=b " << endl;

    cout << endl;
    cout << "Main() = Let's see if pointer to a pointer can help us with changing value outside of main() and still remain the same in Main() " << endl;

    change (&a, f); // passsing address of a pointer, pass by reference if you will, but for pointer.
    //can think of it as.... & of *a, so in function  change (int * (*a), *f);

    cout << endl;
    cout << "Main() = a value " << a << endl;

    //you don't need to pass address if you have double pointer already
    
    //pp is **p = &a; --- so below are the same.
    //change(pp, f);  is same as passing.... change(&a, f);
    //hope that clears up. 
}

void p2p_simple_example(){
    int x = 55;
    int *p = &x;

    *p = 66; //changes the value of x

    int ** q = &p;  //can only store a pointer inside a pointer to a pointer
    int ***r = &q; // can only store pointer to a pointer inside a pointer to a pointer to a pointer.

    cout << "Address value of p= " << p << endl; // address of x
    cout << "Address value of x= " << &x << endl; // addresss of x
    
    cout << "Value stored at p= " << *p << endl; // 66
    cout << endl;

    cout << "Value stored at *q= " << *q << endl; // address of pointer p, so in other words &(*p)
    cout <<endl;

    cout << "Value stored at **q= " << *(*q) << endl; // 66
    cout << endl;

    cout << "Value stored at **r= " << *(*r) << endl ; //address of a pointer q. 
    cout <<endl;

    cout << "Value stored at ***r= " << *(*(*r)) << endl; // 66
    //you can simply type ***r, but brackets are for understanding precendence.
    ***r = 9;
    cout << "After performing ***r = 9; operation" << endl;
    cout << "Value stored at x= " << x << endl; // 66

    **q = *p +2 ;
    cout << "output of **q = *p + 2; which changes x = " << x << endl;

}

int main()
{
    p2p_using_function();
    cout << "---------------------Simple example-----------------" << endl;
    p2p_simple_example();
    return 0;
}

