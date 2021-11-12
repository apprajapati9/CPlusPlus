#include <iostream>

using namespace std;

void printHello(char *name){
    cout << "Hello " << name << endl;
}

 int Add(int a, int b){
     return a+b;
 }

int main(){

    int (*p)(int, int);
    p = &Add; // Add without & will be the same, will return pointer address as well.

    int c = (*p)(2,3); // p(2,3) will work as well.

    cout <<c<<endl;

    void (*print)(char*);
    print = &printHello;
    print("Ajay"); //do not forget to add parentheses for no args.
    
    return 0;
}