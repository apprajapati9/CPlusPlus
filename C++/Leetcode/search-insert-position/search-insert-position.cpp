#include <iostream>
#include <vector>

using namespace std;

/*
35. Search insert position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

you must write an algorithm with O (log n) runtime complexity.

nums = [1,3,5,6] t=5, output = 2
nums = [1,3,5,6] t=2, output = 1
nums = [1,3,5,6] t=7, output = 4

*/

int searchInsert(vector<int>& nums, int start, int end, int target) {
    
    int mid = 0;
    while(start <= end) {
	mid =  start + (end - start) / 2;

	if(nums[mid] == target){
	    return mid;
	}else
	if(nums[mid] > target) {
	    end = mid - 1; 
	}else{
	    start = mid + 1;
	}
    }
    

    //return mid or else start because its lower than the target n where it needs to be.
    return start; 
}


int main(){
    vector<int> v = {1,3,5,6,8}; // 1 + (3 - 1) / 2 .. 3/2 = 1
    int t = 7;
    int ans = searchInsert(v, 0, v.size()-1, t);
    cout <<  "Answer: " << ans << endl;
    return 0;
}
