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

/* practice test myself.

#include <iostream>

using namespace std;



int* merge(int* a, int start, int end, int m){
 
    cout << "start, end-> " << "(" << a[start] << "," << a[end] << ")" << ", m-" << a[m] << endl;
    
    // cout << "start, end-> " << "(" << a[start] << "," << a[end] << ")" << ", m-" << a[m] << endl;
    if(a[start] > a[end]){
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
    }
    
    // cout << "array print-> " << endl;
    // for(int i=start; i<end; i++){
    //     cout << a[i] << ",";
    // }
    // cout << endl;
    
    
    return a;
   // break;
}

void mergeSort(int arr[], int start, int end){
  
  if(start < end){
    int middle = start + (end-start)/2;// 5+(9-5)/2 = 5+4/2=4
  
  //cout << "start ->" << start << endl;
  //cout << "middle-> " << middle << endl;
 // cout << "end ->" << end << endl;
  //cout << "---------------------left" << endl;
  mergeSort(arr, start, middle);
  //cout << "---------------------right" << endl;
  mergeSort(arr, middle+1, end);

    merge(arr, start, end, middle);
  }
  
}

int main()
{
    int arr[] = {70,50,30,10,20,60,40}; //{1,5,4,3,10,2,6,7,9,8}; // 9 items *  4 bytes- 36 sizeof
    
    int size = sizeof(arr)/sizeof(int); //sizeof gives size in bytes.
    cout<< "size-> " << size << endl;
    mergeSort(arr,0, size-1);
    
     //cout << "array print-> " << endl;
    for(int i=0; i<size; i++){
        cout << arr[i] << ",";
    }
    cout << endl;

    return 0;
}


*/