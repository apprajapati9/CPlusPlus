#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

/*
The problem statement:  https://leetcode.com/problems/contains-duplicate/description/

Given an integer array nums, return true if any value appears at least twice in the array
and return false if every element is distinct.

nums = {1,2,3,1}
output : true

nums = {1,2,3,4}
Output : false
*/

bool bruteForceSolution(int* a, int size){

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if(i != j && a[i] == a[j]){
                return true;
            }
        }
    }
    return false;
}

bool usingSet(int* a, int size) {

    unordered_set<int> mSet;

    for (int i = 0; i < size; i++){
        if(mSet.count(a[i]))
            return true;
        mSet.insert(a[i]);
    }

    return false;
}

bool usingMap(int *a, int size){
    unordered_map<int, int> map;

    for (int i = 0; i < size; i++){
        if(map.find(a[i]) != map.end()){ // Checking if find didn't reach till end, means element found.
            return true;
        }else{
            map[a[i]]++;
        } 
    }
    return false;
}

int main() {

    int arr[] = {1, 2, 3, 1}; //You can use vector too here.
    int size = sizeof(arr) / sizeof(int);

    // brute force, checking all indexes and comparing - o(n)2 runtime complexity
    string msg = bruteForceSolution(arr, size)? "Duplicate found!" : "No Duplicate found!";
    cout << msg << endl;

    //Using set data structure - o(n) - time complexity
    msg = usingSet(arr, size) ? "Duplicate found!" : "No Duplicate found!";
    cout << msg << endl;

    //Using set data structure - O(n) - time complexity
    msg = usingMap(arr, size) ? "Duplicate found!" : "No Duplicate found!";
    cout << msg << endl;

    return 0;
}