/*

Question: 

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

*/



#include<iostream>
#include<vector>

using namespace std;


void printVect(vector<int> &v)
    {
        cout << "[";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i != v.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }


vector<int> bubble_sort(vector<int> &v){

    for(int i=0; i < v.size()-1; i++){
        
        for (int j = i+1; j < v.size(); j++){

            if(v[j] < v[i]){
                
                int temp = v[j];
                v[j] = v[i];
                v[i] = temp;

            }

        }
    }
    return v;
}


int quick_sort_pivot_index(vector<int> &v, int start, int end){
    
    
    int pivot = end;

    int partitionIndex = start;

    for(int i= start; i < end; ++i){

        if(v[i] < v[pivot]){
            swap(v[i], v[partitionIndex]);
            ++partitionIndex;
        }
    }

    swap(v[partitionIndex], v[pivot]);
    return partitionIndex;

}

void quick_sort(vector<int> &v, int start, int end){

    if(start < end){

        int pivot = quick_sort_pivot_index(v, start, end);

        quick_sort(v, start, pivot - 1);
        quick_sort(v, pivot+1, end);
    }
}

int findKthLargest(vector<int> &nums, int k){

    // quick_sort(nums, 0, nums.size()-1);  -- Uncomment this to execute own implementation of sorting using quick sort
   // printVect(nums);

    sort(nums.begin(), nums.end());  // in built library sort function to sort.

    int biggest = 0;
    
    for(int i = nums.size()-1; i >= 0 ; i--){
        if(k!=0){
                biggest = nums[i];
                k--;
        }
            
    }

    return biggest;
}



int main(){

    //vector<int> v = {3,2,1,5,6,4};
    vector<int> v = {3,2,3,1,2,4,5,5,6};
    
    cout << findKthLargest(v, 4) << endl;

    return 0;
}

//Note: This challenge can also be solved by using heaps, concept which i have yet to learn, but Heap can be used as well for this. 
//Please try to implement this using Heap when you learn.