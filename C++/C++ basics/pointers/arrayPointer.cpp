#include <iostream>

using namespace std;

//when passing an array, it only passes address of first element so size is 1
void fun(int *a){
    cout << sizeof(int) << endl;
    cout << "other function= " << sizeof(a) / sizeof(int) << endl;
    for (int i = 0; i < 5; i++){
        a[i] += 1;
        cout << a[i]; 
    }
}

int* preturnFun(int size){
    int *p;
    p = new int[size]; //this array is created in heap
    for (int i = 0; i < size; i++){
        p[i] = i+3;
    }

    return p;
}
int main(){
    int a[] = {2, 3, 4, 5, 6};

    cout << "main function=" << sizeof(a) / sizeof(int) << endl;
    fun(a);

    int *ptr, size = 5;
    ptr = preturnFun(size);

    cout << "pointer array ------  " << endl;

    for (int i = 0; i < 5; i++){
        cout << ptr[i] << endl;
    }
    return 0;
}