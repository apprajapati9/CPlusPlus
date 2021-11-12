#include <iostream>

using namespace std;

void A(){
    cout << "Hello" << endl;
}

void B(void (*ptr)()){
    ptr();  //callback function that ptr points to
}

int main(){

    void (*ap)();
    ap = A;

    B(ap);
    B(A); // would work just as well because A function itself returns pointer 
    // so without creating passing name could give us the same result.


    return 0;
}