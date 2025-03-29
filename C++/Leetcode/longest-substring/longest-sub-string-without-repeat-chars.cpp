#include <iostream>
#include <vector>
#include <algorithm> //fill method
#include <unordered_set>

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

/*
The solution is based on technique called "Sliding Window"
for example
   pwwkew
   ^
   ^ <------- Two pointers pointing there.

   pwwkew
   ^^
   pwwkew
   ^ ^   <---- Exists so we shrink from the left side
   pwwkew
    ^^   <---- Still exists because we shrunk from left which was pointing to ^p character
   pwwkew
     ^^ <-- repeat...
   pwwkew
     ^ ^ <-- 3 len
   pwwkew
     ^  ^ <-- remove from left which is pointing to ^w, effectively removes duplicate and thus return 3

     The main important thing to remember here that when we shrink the window from the left, it automatically
     means if character isn't gone then that substring is invalid and thus we need to remove more until
     there's none left in the set.


   */

//Gotten from leetcode discussions
void slidingWindowSet()
{
    //string s = "abcabcbb";
    //string s = "bbbbb";
    string s = "pwwkew";

    int left = 0;
    int len = 0 ;//returned value

    unordered_set<char> set;

    for(size_t i = 0; i < s.length(); i++) {

        while(set.count(s[i]) == 1) {
            set.erase(s[left]);
            left++;
        }

        set.insert(s[i]);
        len = len > (i - left + 1) ? len : i-left+1;
    }

    cout << "Ans: " << len << endl;
}

//My own solution
void slidingWindow()
{

    //string s = "abcabcbb";
    //string s = "bbbbb";
    string s = "pwwkew";

    int len = 0;

    unordered_set<char> mSet;

    int counter = 0;
    for(size_t i = 0; i < s.size(); i++) {

        int left = i;

        while(mSet.count(s[left]) == 0) {
            mSet.insert(s[left]);
            counter++;
            if(left + 1 < s.size()) {
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
    // slidingWindow();
    slidingWindowSet();
    return 0;
}
