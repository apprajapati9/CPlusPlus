#include <iostream> 

using namespace std;

void display(int  , int = 5, int =0); //this is how we can pass defalt value to params of function

void display2(int =0, int = 10); //since we have both param value specified by default we can call this function simply without any argument display2();

int main(){

    display(6, 7, 8);
    display(6);
    display(3,4); 
    //since we haven't specified default value for 1st argument you must have atleast one arugment passed.

    display2();
     
    
    return 0;
}

void display(int a, int b, int c){
    cout << a << ", " << b << ", "<< c << endl; 
}

void display2(int a, int b){
    cout << a << ", " << b << endl; 
}