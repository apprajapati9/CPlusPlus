#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
//#include <map>

using namespace std;

// m (number of items in vector)
// complexity  (m * n log n )  - n log n for sort
void groupAnagrams(vector<string>& strs){

    unordered_map<string, vector<string>> map;
    unordered_map<string, vector<string>>::iterator itr;

    for(auto i : strs){
        string w = i;
        sort(w.begin(), w.end());
        map[w].push_back(i);
    }

    //print contents of map
    for (itr = map.begin(); itr != map.end(); itr++){
        cout << "[";
        for (int i = 0; i < itr->second.size(); i++){
            cout << itr->second.at(i);
            if(i != itr->second.size()-1)
                cout << ",";
        }
    
        cout << "]";
    }
}

//Reversing a string using pointer.
void reverseString(string* s, int size){
    int range = size / 2;

    //cout << range << endl;
    for (int i = 0; i < range; i++) {

        int index = (size-1) - i; // 4 - 0 = 4
        char temp = (*s)[i];
        cout << "temp " <<  temp << endl;
        cout << "index =" << (*s)[index] << endl;
        (*s)[i] = (*s)[index];
        (*s)[index] = temp;
    }
}

//Converts a number int to a string.
string convertNumToString(int num){

    string str;
    if(num > 9){
        while(num > 0){
            int r = num % 10;
            str +=  r + '0';  // 0 is 48 ascii , 1 - 49
            num = num / 10; 
        }
    }else{
        str = num + '0';
    }
    
    //reverseString(&str, sizeof(str));
    //cout << "string returned-> " << str << endl;
    return str;
}

void groupAnagramsWithoutSort(vector<string> & strs){

    unordered_map<string, vector<string>> map;

    for(auto i : strs){
        int arr[26] = {0};
        for(auto j : i){
            int index = (int)j - (int)'a'; // 97-97 = 0
            arr[index] += 1;
        }
        string str = "";
        for(auto k : arr) {
            str += convertNumToString(k+ (k-'a')); // here adding unique key index with number so no need to add , as delimiter to avoid edge cases.
           // str += ","; // adding "," to string to elimitate edge case like "abbbbbbbbbbb", "aaaaaaaaaaab", without delimiter this test case will fail
        }

        map[str].push_back(i);
    }

    cout << "[";
    for(auto itr: map) {
         cout << "[";
         for (int i = 0; i < itr.second.size(); i++ )
         {
             cout << itr.second[i];
             if (i != itr.second.size() - 1)
                 cout << ",";
         }
        
        cout << "] ";
    }
    cout << "]";
}

int main(){

    vector<string> strs =  {"act", "pots", "tops", "cat", "stop", "hat", "ajay"};

    //vector<string> strs = {"abbbbbbbbbbb", "aaaaaaaaaaab"};

    //groupAnagrams(strs);

    groupAnagramsWithoutSort(strs);

    return 0;
}