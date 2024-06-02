#include <iostream>

using namespace std;

void swap(int *a, int indexX, int indexY)
{ // int a[] or int* a both are same.
    int temp = 0;

    cout << "swap->" << a[indexX] << "," << a[indexY] << endl;

    if (a[indexX] > a[indexY])
    {
        temp = a[indexX];
        a[indexX] = a[indexY];
        a[indexY] = temp;
    }
}

void merge(int *a, int first, int last, int mid)
{

    // cout << "first: " << first << endl;
    // cout << "mid: " << mid << endl;
    // cout << "last: " << last << endl;

    // cout << "---------------" << endl;
}

void mergeSort(int *a, int left, int right)
{
    if (left < right)
    {
        auto mid = left + (right - left) / 2; // right/2 works but only for left side, right side needs adjustments.
        // int size = sizeof(a) / sizeof(a[0]);
        cout << "left = " << left << ", mid: " << mid << ",right: " << right << endl;
        cout << "left = " << a[left] << ", mid: " << a[mid] << ",right: " << a[right] << endl;
        cout << "---" << endl;
        //  cout << "-------- array---" << endl;
        //     for (int i = left; i <= right; i++){
        //         cout << a[i]  << ","<< endl;
        //     }
        //     cout << "-----------" << endl;
        // return;
        mergeSort(a, left, mid); // l0 , m3

        mergeSort(a, mid + 1, right); // l4, r=7

        cout << "final elements" << endl;
        cout << "left ->" << left << ", right ->" << right << ",mid ->" << mid << endl;
        cout << "------" << endl;
        merge(a, left, right, mid);
    }
}

int main()
{

    int a[] = {64, 25, 12, 22, 11};
    // int a[] = {6, 3, 4, 1, 5, 2, 7, 0};

    int size = sizeof(a) / sizeof(a[0]);

    cout << "main() size " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
    mergeSort(a, 0, size - 1);

    // sort(a, 0, size-1, size);

    // if (size % 2 == 0)
    // {
    //     for (int i = 0; i < size; i += 2)
    //     {
    //         // cout << "indexes" << i << ", " << i + 1;
    //         swap(a, i, i + 1);
    //     }
    // }
    // else
    // {
    //     for (int i = 0; i < size - 1; i += 2)
    //     {
    //         // cout << "indexes" << i << ", " << i + 1;
    //         swap(a, i, i + 1);
    //     }
    // }

    for (int i = 0; i < size; i++)
    {
        //   cout << a[i] << "," << endl;
    }

    return 0;
}