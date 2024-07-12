#include<iostream>
#include<vector>
#include<bits/stdc++.h>
//#include <map>

using namespace std;

unordered_map<string, unordered_map<char, int>>::iterator itr; //outer
unordered_map<char, int>::iterator inner;

void printHashMap(unordered_map<string, unordered_map<char,int>>& vec){

    unordered_map<string, unordered_map<char, int>>::iterator itr; //outer
    unordered_map<char, int>::iterator inner;

    for (itr = vec.begin(); itr != vec.end(); itr++){

        //cout << itr->first << endl;
        for (inner = itr->second.begin(); inner != itr->second.end(); inner++){
            cout <<itr->first << " ==> " << inner->first << "," << inner->second << " | ";
        }
        cout << endl;
    }
}

vector<vector<string>> groupAnagrams(vector<string>& strs){
    vector<vector<string>> vec;

    if(strs.size() == 0)
        return vec;


    unordered_map<string, unordered_map<char, int>> map;

    for (int i = 0; i < strs.size(); i++) {
        //cout << strs[i] << ",";

        
        unordered_map<char, int> curr;
        for (int j = 0; j < strs.size(); j++){
            

            // if(curr.find(strs[i][j]) != map.end()){
                
            // }else{
                curr[strs[i][j]]++;
           // }

        }
        map[strs[i]] = curr;
        curr.clear();
    }

    for (itr = map.begin(); itr != map.end(); itr++){

        //cout << itr->first << endl;
        for (inner = itr->second.begin(); inner != itr->second.end(); inner++){
            cout <<itr->first << " ==> " << inner->first << "," << inner->second << " | ";
        }
        cout << endl;
    }



    //printHashMap(map);

    return vec;
}





int main(){

    vector<string> strs =  {"act", "pots", "tops", "cat", "stop", "hat", "ajay"};

    groupAnagrams(strs);

    return 0;
}