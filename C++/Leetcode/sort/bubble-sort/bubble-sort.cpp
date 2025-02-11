#include <iostream>

using namespace std;

/*
Bubble sort is also known as sinking sort. It has a worst case and average complexity of O(n2) where n is the number of
items being sorted.

Each n iterations, n[i] to n[i+1] elements are compared and swapped.
so n to n is N times and outer N items making it O(n2)

*/

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void swap2(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArr(int *a, int size)
{
    for (int i = 0; i< size; i++) {
        cout << a[i] << ",";
    }
    cout << endl;
}

/*
biggest one keeps going at the end, which is why size-1-i
First iteration: out of size -1 which is 4 in this case.
    5,3 swap
    5,2 swap
    5,4 swap
    5,1 swap
    arr : 3,2,4,1,5
second iteration :
    3,2 swap
    3,4 no swap
    4,1 swap
    4,5 no swap -- > this iteration won't happen bcz of j = size - 1 -i 
    arr : 2,3,1,4,5
third iteration:
    2,3 - no swap
    3,1 - swap

    arr :2,1,3,4,5

forth iteration:
    2,1 - swap
    2,3 - no swap
    
    arr : 1,2,3,4,5 
*/
void bubbleSort(int *a, int size)
{
    for(int i = 0; i < size - 1; i++) {

        for(int j = 0; j < size -1 -i; j++) {

            cout << a[j] << ",";
            if(a[j] > a[j+1]) {
                swap2(&a[j], &a[j+1]);
            }

        }
        cout << endl;
        printArr(a, size);
    }
    cout << "End." << endl;
}

int main()
{
    cout << "hello world" << endl;

    int a[] = {32,-5,1,12,300,6,87,10};// {5,3,2,4,1};//{32,-5,1,12,300,6,87,10};

    int size = sizeof(a)/sizeof(int); //32/4 = 8

    cout << "size " << size << endl;
    bubbleSort(a, size);

    for(int i = 0; i < size; i++ ) {
        cout << a[i] << ",";
    }
    return 0;
}
