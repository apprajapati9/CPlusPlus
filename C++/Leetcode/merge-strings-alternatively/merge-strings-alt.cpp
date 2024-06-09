#include<iostream>

using namespace std; 

//Problem statement : https://leetcode.com/problems/merge-strings-alternately/description/

string mergeStringAlt(string word1, string word2){

    int s1 = word1.size(), s2 = word2.size();
    string finalString="";

    int one = 0, two = 0;
    while (one < s1 || two < s2){
        if(one < s1){
            finalString += word1[one];
            one++;
        }
        if(two < s2){
            finalString += word2[two];
            two++;
        }
    }
    return finalString;
}

//Using char array - in this approach, firstly comparing equal size n then append remaining.
string mergeAlternately(string word1, string word2)
{

    int size1 = 0;
    for (char ch : word1)
    {
        ++size1;
    }

    int size2 = 0;
    for (char ch : word2)
    {
        ++size2;
    }

    int smallerSize = size1 < size2 ? size1 : size2;
    char charArray[size1 + size2]; ////had to do +2 for null space character on leetcode online compiler

    for (int i = 0; i < smallerSize; i++)
    {
        int position = i * 2;
        charArray[position] = word1[i];
        charArray[position+1] = word2[i];
    }

    //normalizing..  abc abcd
    int start = smallerSize * 2;
    if(size1 > size2){
        for (int i = size2; i <= size1; i++){
            charArray[start] = word1[i];
            start++;
        }
    }else{
        for (int i = size1; i <= size2; i++){
            charArray[start] = word2[i];
            start++;
        }
    }

    string finalString;
    for (std::size_t i = 0; charArray[i] != '\0'; ++i) {
        finalString += charArray[i];
    }
   
    return finalString;
    }

    int main(){
        string mString = mergeStringAlt("ajayyy1", "ajay");

        cout << mString << endl;
        return 0;
    }