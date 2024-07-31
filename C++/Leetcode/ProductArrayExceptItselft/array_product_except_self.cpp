#include <iostream>

using namespace std;

void bruteForce()
{
    int arr[] = {2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]); // 16/4 = 4

    int ans[size];

    for (int i = 0; i < size; i++){
        int sum = 1;
        for (int j = 0; j < size; j++){
            if(i!=j){
                sum *= (arr[j]);
            }
        }
        ans[i] = sum;
        sum = 1;
    }

    for (int i = 0; i < size; i++){
        cout  << ans[i] << " ";
    }
    
}

void usingDivision(){
    int arr[] = {-1,1,0,-3,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    int total = 1;
    for (int i = 0; i < size;i++) {
        int value = arr[i] == 0 ? 1 : arr[i];
        total *= value;
    }
    //cout << "total " << total << endl;

    for (int i = 0; i < size;i++) {
        arr[i] = total / arr[i];
        
        cout << arr[i] << " ";
    }

}

//prefix postfix
void oN() {

    //array
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]); // 16/4 = 4 size.

    //find prefixes
    int prefixResult[size] = {1}; // This will initialize all elements with 1
    int lastSum = 1;

    for (int i = 1; i < size; i++) {
        int prefixElementIndex = i - 1; // 1, 1
        int prefixValue = prefixResult[i]; // 
        // lastSum = 
        prefixResult[i] = lastSum; 
    }
}

int main()
{

    cout << "brute force" << endl;
    bruteForce();
    cout << "----------" << endl;

    usingDivision();
    //int size = sizeof(p) / sizeof(p[0]);

    // for (int i = 0; i < size; i++){
    //     cout << p[i] << endl;
    // }

    return 0;
}