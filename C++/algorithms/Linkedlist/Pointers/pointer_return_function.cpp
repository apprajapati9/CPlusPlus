#include<iostream>

using namespace std;

//int* to return pointer/address of a var
int* Add(int* a , int* b){  //This function return Seg. fault bcz of local address return
    int c = *a + *b;
    return &c;
}

int* Add_(int* a, int* b){
    //to solve Segmentation fault, we need to assign memory in Heap
    int *c = new int;
    *c = *a + *b;
    return c;
}

int main(){
    int a =2, b =4;
    //Uncomment below code to reproduce segmentation fault warning.
    //int *c1 = Add(&a,&b);
    //cout << *c1 << endl; 
    /*Segmentation fault bcz trying to access memory address sent by Add
    after returning, Add function scope is destroyed by memory stack so
    that memory pointer points to nothing bcz that address has no value.
    that's my seg. fault. 
    */

    int *c = Add_(&a, &b);
    cout << *c <<endl; // answer returns now, but still warning stays
    // shouldn't return variable/address from a function bcz its local to a function.

    return 0;
}