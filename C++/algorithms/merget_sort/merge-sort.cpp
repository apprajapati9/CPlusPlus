#include <iostream>

using namespace std;

void sort(int *arr, int start, int end, int mid)
{

    int left = start; //left half start
    int right = mid + 1; //right half start

    int s1 = mid - start + 1; //Size of left size arr
    int s2 = end - right + 1; // size of right size arr

    int mergedArr[s1+s2] = {0}; // mergedArr to combine left and right.
    int index = 0;

    while(s1 != 0 && s2 != 0) {

        if(arr[left] < arr[right] || arr[left] == arr[right]) {
            mergedArr[index] = arr[left];
            left++;
            index++;
            s1--;
        }

        if(arr[right] < arr[left]) {
            mergedArr[index] = arr[right];
            right++;
            index++;
            s2--;
        }
    }

    // Here keep using left variable to access correct left element.
    if(s1 > 0) {
        for(int i = 0; i < s1; i++) {
            mergedArr[index]= arr[left];
            index++;
            left++; //increment.
        }
    }

    //here keep using right variable to access correct right  element.
    if(s2 > 0) {
        for(int i = 0; i < s2; i++) {
            mergedArr[index]= arr[right];
            index++;
            right++;// increment.
        }

    }

    //updating original arr.
    index = 0;
    for(int i = start; i <= end; i++) {
        arr[i] = mergedArr[index];
        index++;
    }

}

void mergeSort(int *arr, int start, int end, int size)
{

    int mid = start + (end - start) / 2; // find mid
    //cout << "mid " << mid << endl;

    if(start < end) {
        mergeSort(arr, start, mid, size);
        mergeSort(arr, mid+1, end, size);

        sort(arr, start, end, mid);
    }
}

//Just a practice to print in reverse using recursion.
void printReverse(int *arr, int index, int size)
{
    if(index < size) {
        printReverse(arr, index + 1, size);
    }
    cout << arr[index] << ",";
}

int main()
{

    int arr[] = {-1,2,1,-2,-2,0,1,100,-1000,10};

    int size = sizeof(arr)/ sizeof(int);

    cout << "Printing array:  " << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;

    mergeSort(arr, 0, size-1, size);

    cout << endl;
    cout << "Sorted array:: " << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << ",";
    }

    cout << endl << endl;
    cout << "Printing sorted array in reverse using Recursion: " << endl;
    printReverse(arr, 0, size-1);

    cout << endl;
    return 0;
}
