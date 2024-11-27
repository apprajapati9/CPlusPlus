#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/*
All three int sum solutions depend on array being sorted.

time complexity: O(n2)
space complexity: O(1) or O(n)
*/
vector<vector<int>> threeSum(vector<int> &nums)
{

    vector<vector<int>> v; //(0, vector<int>(0));
    sort(nums.begin(), nums.end());

    int size= nums.size();

    for(int i = 0; i < size; i++) {

        if(i > 0 && nums[i] == nums[i-1]) {
            continue; //skip this iteration and jump to next.
            // in sorted array if -1, -1, exists then we are skipping and going to the last -1 index.
        }

        int left = i+1;
        int right = size-1;

        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum < 0) { // if sum = -1 then need +1 which would only exit on left++ side bcz array is sorted.
                left++;
            } else if(sum > 0) { // if sum = 1 then have to add -1 to get to 0, which will only exist if -- right bcz arr is sorted.
                right--;
            } else {
                v.push_back({nums[i],nums[left], nums[right]});
                left++;
                while(nums[left] == nums[left-1] && left < right) {
                    left++;
                }
            }
        }
    }
    return v;
}

int main()
{
    //test cases
    vector<vector<int>> nums = {
        {-1,0,1,2,-1,-4},
        {0,0,0},
        {0,1,1},
        {-30,-20,15,10,-10,20,25},
        {10,-20,15,5,25,-10,-5},
        {30,-50,-10,10,20,-30},
        {-1,0,1,0}
    };

    vector<vector<int>> v;

    for(auto i: nums) {
        v = threeSum(i);

        cout << "Unique triplets: " << endl;
        for(auto j: v) {
            for(auto k: j) {
                cout << k << ",";
            }
            cout << endl;
        }
        cout << endl;
    }
}
