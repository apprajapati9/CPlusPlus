#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

void bubbleSort(int *ar, int size, int (*fun_p_compare)(int, int)){

    for(int i=0; i < size; i++){
        for(int j=0; j < size-1; j++){
            
            if(fun_p_compare(ar[j], ar[j+1]) > 0){
                int temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        
        }
    }
}

int absCompare(int a, int b){
    if(abs(a) > abs(b)) return 1;
    else return -1;
}

int compare(int a, int b){
    if( a > b) return 1;
    else return -1;
}

int q_compare(const void* a, const void* b){
    int a1 = *(int*)a;
    int b1 = *(int*)b;
    return abs(a1)-abs(b1);
}

void print(int* array, int size){
    for(int i=0;i<size; i++){
        cout << array[i] << endl;
    }
}

int main(){

    int a[] = {-31,22,-1,50,-6,4};

    bubbleSort(a, 6, absCompare); //function pointer

    for(int i = 0; i < 6; i++){
        cout << a[i] << endl;
    }
    cout << "---------qsort lib function result--------" <<endl;
    //above result -- same can be achived by this below
    int b[] = {-31,22,-1,50,-6,4};
    qsort(b, 6, sizeof(int), q_compare );
    
    print(b, 6);

    return 0;
}