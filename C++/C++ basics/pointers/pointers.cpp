#include<iostream>
#include <stdlib.h> 

using namespace std;

int main(){
    int A[5] = {2, 4, 6, 8, 10};
    int *p;

    int ab = 10;
    int *a = &ab;

    p = A;
    for (int i = 0; i < 5; i++){
        cout << p[i] << endl; //remember in arrays dereferencing doesn't require *
    }

    cout << "pointer - "  << *a << endl;

    int *heapPointer;
    heapPointer = new int[5]; // new/malloc is used to allocate memory in HEAP.

    heapPointer[0] = 101;
     for (int i = 0; i < 5; i++){
        cout << "heap= " << heapPointer[i] << endl; //remember in arrays dereferencing doesn't require *
    }
}