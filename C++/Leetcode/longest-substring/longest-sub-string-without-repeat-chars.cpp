#include <iostream>
#include <vector>
#include <algorithm> //fill method
#include <set>
using namespace std;


/*
Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
void printVector(vector<int> &v)
{
    for(size_t i = 0; i < v.size(); i++) {
        cout << v[i] << ",";
    }
    cout << endl;
}

void slidingWindow()
{

    //string s = "abcabcbb";
    //string s = "bbbbb";
    string s = "pwwkew";

    int len = 0;

    set<char> mSet;

    int counter = 0;
    for(size_t i = 0; i < s.size(); i++) {

	int left = i;
	
	while(mSet.count(s[left]) == 0) {
	    mSet.insert(s[left]);
	    counter++;
	    if(left + 1 < s.size()){
		left++;
	    }
	}
	
	len = counter > len ? counter : len; 
	counter = 0;
	mSet.clear();
    }

    cout << len;
}

int main()
{
    //testUsingAsciiVector();
    slidingWindow();

    return 0;
}
