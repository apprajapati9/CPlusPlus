#include <iostream>

using namespace std;

void swapByAdd(int *x, int *y){

    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

//This is monolithic code, this will be pasted inside main function as compared to pointer 
//which is efficient because accessing variable using pointer. 
void swapByRef(int &x, int &y){ //kind of like an inline function. It may also depend on the compiler how it chooses to optimize, might convert into a pointer as well.
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}

int passByValue(int a, int b){
    return a + b;
}

int main(){

    int a = 10, b = 20;

    int c = 10, d = 20;
    swapByAdd(&a, &b);

    swapByRef(c, d);

    int x = passByValue(a, b);

    cout << a << b << endl; 
    cout << c << d << endl;
    cout << x;

    return 0;
}