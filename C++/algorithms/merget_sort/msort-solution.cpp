#include <iostream>
#include <vector>

using namespace std;

/*
The diff between my own solution and this is that I actually sorted two halves and then changed main arr
In here, arr is stored first and based on comparison of stored array, main arr is changed.

So basically both implementation are same.
*/
void merge(int *arr, int start, int mid, int end)
{

    int left = start;
    int right = mid + 1;

    int s1 = mid - left + 1;
    int s2 = end - right + 1;

    vector<int> l(s1);
    vector<int> r(s2);

    //saving range of left and right in temp arr
    for(int i=0; i<s1; i++) {
        l[i]= arr[left+i];
    }

    for(int i=0; i<s2; i++) {
        r[i]= arr[right+i];
    }

    int i = 0;
    int j = 0;
    while(i < s1 && j < s2) {

        if(l[i] <= r[j]) {
            arr[left] = l[i];
            i++;
        } else {
            arr[left] = r[j];
            j++;
        }
        left++;
    }

    while(i < s1) {
        arr[left] = l[i];
        left++;
        i++;
    }
    while(j < s2) {
        arr[left] = r[j];
        left++;
        j++;
    }
}

void mergeSort(int *arr, int start, int end)
{
    if(start < end) {

        int mid = start + (end-start)/2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, start, mid, end);
    }
}

int main()
{

    // vector<vector<int>> v= {
    //     {12,3,2,-11,-2,1,7,9,1,10,200},
    //     {6,3,1,2,3,4}
    // };

    int arr[] = {12,3,2,-11,-2,0,5,6,-11}; //

    int size = sizeof(arr)/ sizeof(int);
    for(auto i : arr) {
        cout << i <<",";
    }
    cout << endl;
    mergeSort(arr, 0, size-1);


    for(auto i : arr) {
        cout << i <<",";
    }
    return 0;

}
