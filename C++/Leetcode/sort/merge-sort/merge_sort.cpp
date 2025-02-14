#include <iostream>

using namespace std;

void print(int *a, int size)
{
    for (int i = 0; i < size; i++) {
        cout << a[i] << ",";
    }
    cout << endl;
}
void swap(int *a, int indexX, int indexY)
{
    // int a[] or int* a both are same.
    int temp = 0;

    cout << "swap->" << a[indexX] << "," << a[indexY] << endl;

    if (a[indexX] > a[indexY]) {
        temp = a[indexX];
        a[indexX] = a[indexY];
        a[indexY] = temp;
    }
}

//{64, 25, 12, 22, 11};
void merge(int *a, int first, int last, int mid)
{
    int left = first;
    int right = mid + 1;

    // int s1 = mid - first + 1; // 0, 2, = 2 - 0 = 2
    // int s2 = last - right + 1 ; // 4 - 2 = 2

    //int totalSize = s1 + s2;

    int temp[last+1] = {0};
k
    int index = 0;
    while(left <= mid && right <= last) {

        if(a[left] < a[right] || a[left] == a[right]) {
            temp[index] = a[left];
            left++;
        } else {
            temp[index] = a[right];
            right++;
        }
        index++;
    }

    //  print(temp, totalSize);
    while(left <= mid) {
        temp[index++] = a[left++];
    }

    while(right <= last) {
        temp[index++] = a[right++];
    }

    index = 0;
    for(int i = first; i <= last; i++) {
        a[i] = temp[index];
        index++;
    }

}


void mergeSort(int *a, int left, int right)
{
    if (left < right) {
        auto mid = left + (right - left) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, right, mid);
    }
}


int main()
{

    int a[] = {64, 25, 12,22, 22, 11,-1};
    // int a[] = {6, 3, 4, 1, 5, 2, 7, 0};

    int size = sizeof(a) / sizeof(a[0]);

    // cout << endl;
    mergeSort(a, 0, size - 1);


    print(a,size);
    return 0;
}

