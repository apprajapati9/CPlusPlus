// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

/* Problem statement :
Design an algorithm to encode a list of strings to a single string.
The encoded string is then decoded back to the original list of strings.

Input: ["leet","code","loveeeeeeeeeee","you"]

Output:["leet","code","loveeeeeeeeeee","you"]

Two methods are provided with following signatures to implement

string encode(vector<string> strs)   <--- To encode vector of strings into a single string
vector<string> decode(string str)    <--- To decode string generated by encode function to its original form and return as a vector

Solution:

You can use a delimiter to split values while encoding so that way 
    when we decode we would know which delimiter to use to split and get the original word.

Here in this example, I used   n# as delimiter where N is the number of words in a letter.

So encoded string would look something like this.
    4#leet4#code14#loveeeeeeeeeee3#you

n# would tell us that we need next 4 characters for 1 string
4#,
4#,
14#,
3#
So while decoding check for the number and # sign to split then add N number of characters into a string 
to get the original word and put in a vector to return original strings.
*/

using namespace std;

//reverses string, example - 231 to 132.
string reverseString(string str){
    //string reversed = "";
    for(int i= 0; i< str.size()/2; i++){
        
        int index = (str.size()-1) - i ; // 2 -0, 2, 2-1 - 1
        
        //swap 
        char c = str[i];
        str[i] = str[index];
        str[index] = c;
    }
    return str;
}

//Converts a given number to string i.e 99 to "99"
string numToString(int num){
    string str = "";
    if(num > 9){
        while(num > 0){
            int r = num % 10;  
            str += r + '0';
            num = num / 10; 
        }
    }else{
        str += num + '0';
    }
    //cout << "num->" << str << endl; 
    return str;
}

//Converts a given string to a number i.e "99" to 99.     
int strToNum(string str){
    int num = 0;
    if(str.size() > 1){
        
        for(auto i: str){
            num =  num*10 + (i - '0');
        }
        return num;
        
    }else{
        int value = (int) str[0];
        value -= '0'; // minus to get to value 9...   9=57, 0=48 -->  57-48 = 9
        return value;
    }
}

//Encode string with N#String i.e 4#Ajay <- 4 (num of characters) # (delimiter) and Ajay is string.
string encode(vector<string>& strs) {
        string str = "";

        for(auto i: strs){
            //str += i.size() + '0';  // This alone only works if one digit number, doesn't work for 2digits num.
            str += reverseString(numToString(i.size()));
            
            str += '#';
            str += i;
        }

        return str;

    }
    
//Decoding a given encoded string.     
vector<string> decode(string s){
    vector<string> strs;
    string num;
    string str="";
    int currentNum = 0;

    for(int i=0;i<s.size();i++){
        
        if(s[i] == '#'){ 
            currentNum = strToNum(num);
      
            num = "";
            for(int j = i+1; j <= i+currentNum; j++){
                str += s[j];
            }
            strs.push_back(str);
            str = "";
            i += currentNum; //resetting i to resume loop.
            
        }else{
            num += s[i]; 
        }
    }
    return strs;
}

int main() {

    //vector<string> strs = {"AjayVeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimesVeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimes 12#space->VeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimesVeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimesAjay"};
    vector<string> strs = {"leet", "code", "loveeeeeeeeeee", "you"};
    string str = encode(strs);
    cout << "Encoded String-> " <<  str << endl;
    
    vector<string> de;
    de = decode(str);

    cout << "decoded string-> ";
    
    for(auto i: de){
        cout << i << " ";
    }
    
    //cout << reverseString("231") << endl;
    
    return 0;
}