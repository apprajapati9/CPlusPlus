#include <iostream>

using namespace std;

int total; //Gets allocated in statis/Global memory 

int square(int x){
    return x*x;
}

int squareOfSum(int x, int y){
    int z = square(x+y);
    return z;
}

int main (){
    // int a = 4, b = 8; 
    // total = squareOfSum(a,b);
    // cout << "Output: " <<total;

    int a; // goes on Stack portion of memory
    int *p;
    p = new int; //goes on heap

    *p = 10;
    cout << *p <<endl;
    delete p; // must free memoery otherwise data stays there and cause errors.

    // p = new int[20];
    // delete[] p; 

    //allocate dynamic memoery, this will not be on Stack memory so have to handle 
    // allocation/deallocation by a programmer.
    int *ptr = new int[6]; 
    //Note: int(6) causes Segmentation fault. [6] works fine.
    for (int i=0;i<6;i++){
        ptr[i] = i+1;
    }
    
    for(int i =0;i<6;i++){
        cout << ptr[i] << endl;
    }
    delete[] ptr;
    ptr = NULL;

    /*
    in c, you can allocate memory in heap with malloc

    void *p = (int*) malloc(10* sizeof(int)); 
    same can be achieved with calloc

    int *p = (int *) calloc (10, sizeof(int));  
    //rather than multiply you can pass args

    */
}

/*

Application Memory
**********************
*                    *
*        HEAP        * ----Memory that is controllable. 
*                    *      also known as dynamic memory.
**********************
*                    *
*        Stack       * --- System allocates/deallocates based on scopes/ no control
*                    *
**********************
*    Static / Global * ---- all globally assigned vars go here
**********************
*    Code (text)     * ---- code text
**********************

*/