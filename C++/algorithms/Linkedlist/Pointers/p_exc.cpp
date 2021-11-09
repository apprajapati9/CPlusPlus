#include<iostream>

using namespace std;

void pointer_and_array(){
    int a[] = {2,4,5,1,7};

    int *p = a;
    for(int i=0;i<5; i++){
        cout << "--------------------" << endl;
        cout << "Address of array a[" << i << "] = " << &a[i] << endl;
        cout << "Address of array a+i =" << a+i << endl; 
        // a + 1/a+2 so a = first element address.
        
        cout << "Value of array[" << i << "] = " << a[i] << endl;
        cout << "value of array *(a+1) =" << *(a+i) << endl;
    }
    // in another words, a[] is a pointer. a is address. 
    // *a = values.. dereferencing. 
}

/* "int *array" or int array[] .. its the same as function args */
int SumOfElements(int array[], int size){ /*
    you must pass size when you are passing an array as an argument
    when you pass array, it passes pointer of array[0], so 
    printing sizeof(array) = 4 bytes only. 
    array passed here was int array[] = {1,3,4,12,3}, so 4 bytes per elements
    4 * 5 (elements) = 20 bytes 
    but here sizeof(array) in this function, it will be 4 bytes only because
    pointer is passed with address of first element only which is array[0]
    hope that clears up.
    */
    int sum = 0;
    
    int wrong_size = sizeof(array)/sizeof(array[0]); 
    /*
    // answer is 4 divided by 4 = 1 only which is wrong.that's why must pass size
    // compiler throws this warning:
    
    warning: 'sizeof' on array function parameter 'array' will return size of 'int*' [-Wsizeof-array-argument]
     int wrong_size = sizeof(array)/sizeof(array[0]);

    */ 
    cout << "wrong_size= " << wrong_size << endl;

    for(int i = 0; i < size; i++){
        sum = sum + array[i];
    }

    return sum;
}

void doubleArrayVals(int *array, int size){
    for (int i=0; i < size; i++){
        array[i] = array[i] * 2; 
    }
}

void function_args_array(){

    int array[] = {1,3,4,12,3};

    int size = sizeof(array) / sizeof(array[0]);

    int total = SumOfElements(array, size); 
    //when you pass like this, it passes address of array[0] when type is of arrays.
    // as we saw in pointer_and_array() function, array allocates a block of memory
    // so address of array[0], so next one would be array[1] = array[0] + 4 (int) bytes
    cout << "Size in main= " << size << endl;
    cout << "Total = " << total << endl;

    //below function is proof that array is passed as pass by ref, which is why
    // changing array in function, reflects change here as well.
    doubleArrayVals(array, size);
    cout << endl;
    for (int i = 0; i <size; i++){
        cout << array[i] << ",";
    }
    cout << endl;
}

void basic_pointers(){
    int a = 5; 
    int *p; // p = address, *p = value at address.

    p = &a;

    cout << p << " = P pointer value, which is address of a!" <<endl;

    cout << &a << " = Address of 'a' variable"<< endl;

    cout << &p <<" = P Pointer's own address in memory" <<endl; 
    //pointer itself lives on diff diff address
    //pointer is in the momory, and memory has an address for pointer itself too.

    cout << *p << " = *p gives value of pointer-dereferencing" << endl; 
}

int main(){

    //basic_pointers();

    //cout << "----- Pointer and arrays concept -------" << endl;
    //pointer_and_array();

    cout << "----- Arrays as function arguements -------" << endl;
    function_args_array(); 
    // This function shows how pointers are used in arrays and 
    // how they are essential in some data structures.
    // another way to look at this is that arrays are always used in function as "pass by reference"
}


/* NOTE 
-------->To understand individually, please comment other functions call
--------> There's note and a warning when you run this program,
        it is for understanding purpose so ignore warning and run the executable after compiling.
*/