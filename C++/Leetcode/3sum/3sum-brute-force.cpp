#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void printSet(set<vector<int>> s)
{
    for(auto i: s) {
        for(auto j: i) {
            cout << j << ",";
        }
        cout << endl;
    }
}

// Function to test how set works.
void setShowcase()
{
    set<vector<int>> s;

    vector<int> v = {-1,0,-1};
    vector<int> v2 = {0,-1,-1};
    vector<int> v3 = {0,-1,-1};


    // Set will not allow same order of vector
    s.insert(v);
    s.insert(v2);
    s.insert(v3);

    // added 3 but will print only 2 because v2==v3 are same.
    // so set will only pick unique ones.
    printSet(s);
}

vector<vector<int>> threeSum(vector<int> & nums)
{
    int size = nums.size();
    set<vector<int>> uset;

    //if you sort nums, you prevent duplicate triplets with the help of set
    sort(nums.begin(), nums.end());

    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            for(int k = j+1; k < size; k++) {

                if(nums[i] + nums[j] + nums[k]==0) {
                    uset.insert({nums[i], nums[j], nums[k]});
                }
            }
        }
    }

    //This works but return v<v>>(begin,end) will also work
    // for(auto i: uset){
    // 	ans.push_back(i);
    // }
    // return ans;

    return vector<vector<int>>(uset.begin(), uset.end());
}

/*

Unique triplets using set data structure.
The important step is to sort the numbers first which would result in producing same order of 3 indexes
and when you add that to set<>, it will prevent any duplicate ones.
1. sort nums
2. if i,j,k == 0 , then add to set.
3. print set/vector

Time complexity : O(n3)  - 3 times running loop.
Space complexity : O(m)  - m is the number of triplets

*/
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


    return 0;
}
