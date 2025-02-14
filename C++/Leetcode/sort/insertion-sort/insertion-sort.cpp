
#include <iostream>

using namespace std;

/*
The main important thing about insertion sort is that it doesn't swap elements.
It shifts one by one until it finds the right index for an element to insert on the left side.
*/

void print(int *a, int size)
{
    cout << "printing arr: " << endl;
    for(int i = 0; i < size; i++) {
        cout << a[i] << ",";
    }
    cout << endl;
}


/*
Best case: On, worst-case, avg case - On2
*/
void insertionSort(int *arr, int size)
{

    for(int i = 1; i < size; i++) { // starting at index 1 because first element is sorted
        int j = i - 1; // checking left and considering sorted
        int x = arr[i];  // in while loop, elements are shifted at this position using j+1 which is i thus storing here.
        while(j >= 0 && x < arr[j]) {
            arr[j+1] = arr[j];  //shifted left to right
            j = j-1;
        }
        arr[j+1] = x; //placed at the right index after finding the correct position for the element using while loop.
    }
}

int main()
{
    cout << "Hello world!" << endl;

    int arr[] = {3,5,8,6,2};

    int size = sizeof(arr)/ sizeof(int);
    insertionSort(arr, size);
    print(arr, size);

    return 0;
}

