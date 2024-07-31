#include <iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans; 
    
    unordered_map<int, int> map;
    
    for(auto i: nums){
        map[i]++;
    }
    
    for(auto i=map.begin(); i!= map.end(); i++){
        cout << i->first <<"->" << i->second << endl;
    }
    
    cout << endl << "------------" << endl;
    
    unordered_map<int, unordered_set<int>> m;
    
    for(int i =0; i< nums.size(); i++){
        //insert value of key-i from map--- into m
        m[map[nums[i]]].insert(nums[i]);
    }
    
    for(auto i=m.begin(); i!= m.end(); i++){
        cout << "key " <<i->first << " ";
        for(auto j : i->second){
            cout << "value" << "  " << j << endl;
        }
    }
    
    for(int i=nums.size(); i> 0 && k!=0; i--){
        if(m.find(i) != m.end()){
            for(auto i: m[i]){
                ans.push_back(i);
                k--;
            }
        }
    }
    
    cout << "ANS:" << endl;
    for(auto i: ans){
        cout << i << " "; 
    }
    
    return ans;
}

int main() {
    
    vector<int> nums = {1,1,1,2,2,3,3,3};
    int k = 2; 
    topKFrequent(nums, k);
    
    return 0;
}