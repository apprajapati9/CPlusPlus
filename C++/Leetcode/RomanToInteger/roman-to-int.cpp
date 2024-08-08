

/*

Problem statement : https://leetcode.com/problems/roman-to-integer/

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

*/
#include <iostream>
#include <unordered_map>
#include <climits>
#include <limits>

using namespace std;



//Important thing to note is that when you pass a string array,
//it gets converted to 2D array.

/*
Memory Block Layout:
+--------------------+
|    arr[0]          |
|--------------------|
|  0  "MCMXCIV"      |  <- arr[0][0] M
|  1  "III"          |  <- arr[1][0] I
|  2  "LVIII"        |  <- arr[2][0] L
+--------------------+

*/

void passStrArray(const string *arr, int size){
   // cout << "size " <<  size << endl; 
    for(int i = 0; i < size; i++){
        
        for(int j = 0; j < arr[i].size(); j++){ //size() or length() works.
            cout << arr[i][j] << " ";
        }
        
        //below works as well. 
        // for(auto j : arr[i]){
        //     cout << j << " ";
        // }
        
       // cout << arr[i] << endl;
    }
}

void findInt( unordered_map<char,int> map){
    
    string arr[] = {"MCMXCIV", "III", "LVIII"};
    
    for(auto str : arr){
        int curr = 0;
        int next = 0;
        int num = 0;
        for(int i=0; i < str.size();i++){
            //cout << endl;
            int sum = 0;
            
            curr = map[str[i]];
            if(i!= str.size()){
                next = map[str[i+1]]; 
            }
            
            if(next > curr){
                 sum = curr - next; 
                 if(sum < 0 ) {
                     sum = -sum; // or sum *= -1;
                     i+=1;
                 }
            }else{
                sum = curr; 
            }
           
            
            // cout << "curr- " << curr << endl;
            // cout << "next - " << next << endl;
            // cout << "sum - " << sum << endl;
            num = num+sum;
            //cout << str[i];
        }
        cout << endl;
        cout << "final " <<  num <<  endl;
    }
}

int main() {
    
    //to find limit of unsigned int.
    //unsigned int i = numeric_limits<unsigned int>::max();
    //cout << i << endl;
    
    
    unordered_map<char, int> map;
    
    map.insert({'M',1000});
    map.insert({'D', 500});
    map.insert({'C', 100});
    map.insert({'L', 50});
    map.insert({'X', 10});
    map.insert({'V', 5});
    map.insert({'I', 1});
    
    string arr[] = {"MCMXCIV", "III", "LVIII"};
    
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << size << endl;
    
    passStrArray(arr, size);
    
    findInt(map);
    
    return 0;
}