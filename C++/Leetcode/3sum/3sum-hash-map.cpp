#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{

    vector<vector<int>> v(0, vector<int>(0));
    sort(nums.begin(), nums.end());
    unordered_map<int, int> count;

    int size = nums.size();
    // saving each num in hashmap and its count
    for(int n : nums) {
        count[n]++;
    }

    for(int i =0; i< size; i++) {
	count[nums[i]]--; //decreasing it.

	if(i > 0 && nums[i] == nums[i-1]){
	    continue;
	}

	for(int j = i+1; j < size; j++){
	    count[nums[j]]--;

	    if(j > i+1 && nums[j] == nums[j-1]) continue;

	    int target = -(nums[i] + nums[j]);
	    if(count[target] > 0){
		v.push_back({nums[i],nums[j],target});
	    }
	}

	for(int j = i+1; j < size; j++){
	    count[nums[j]]++;
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
