#include <iostream>
#include <vector>
#include <unordered_map>

/* Problem description : https://leetcode.com/problems/top-k-frequent-elements/description/

Steps to solve this
1. Use hashmap to calculate how many occurance


*/


using namespace std;

class Solution
{
public:
    void printMap(unordered_map<int, int> &m)
    {
        cout << "printing map->" << endl;
        unordered_map<int, int>::iterator itr;
        for (itr = m.begin(); itr != m.end(); itr++)
        {
            cout << itr->first << " " << itr->second << endl;
        }
        cout << "print map done!" << endl;
    }


    std::vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        const int size = nums.size();
        cout << "size-" << size << endl;

        unordered_map<int,int> map;

        vector<vector<int>> values(size+1, vector<int>(1, 00)); // init all to 0
        
        // int arr[size][size] = {0};  //TODO why not Variable length array at runtime.

        

        for (int i = 0; i < size; i++)
        {
            map[nums[i]]++;
        }

        for(auto i : map){
            values[i.second].push_back(i.first);
        }


        printMap(map);

        cout << "values size" << values.size() << endl;
        for (int i = 0; i < values.size(); i++)
        {
            // for(auto j : values[i]){
            //     cout << j << " ";
            // }
            for (int j = 0; j < values[i].size(); j++)
            {
                cout << values[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = values.size()-1; i > 0 && k != 0; --i){
            //cout << "size of inn value" << values[i].size() << endl;
            for (int j = 0; j < values[i].size(); ++j){
                if(j > 0 ){//&& values[i][j]){
                    //cout << "value to be added" << values[i][j] << endl;
                    ans.push_back(values[i][j]);
                    k--;
                }
            }
        }

        for(auto i : ans){
            cout << "ans " << i << " ";
        }

        // printMap(map);

            return ans;
    }
};

int main()
{

    // vector<int> nums = {1, 1, 1, 1, 2, 2, 3, 3, 3, 0, 4, 5};
    //vector<int> nums = {1, 2, 7};
    //vector<int> nums = {7, 7};
    vector<int> nums = {3,0,1,0};
    int k = 1;

    Solution s;

    nums = s.topKFrequent(nums, k);

    // for (auto i : nums)
    // {
    //      cout << i << " ";
    // }

    return 0;
}