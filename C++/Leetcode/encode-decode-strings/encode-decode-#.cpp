// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

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

string numToString(int num){
    string str = "";
    if(num > 9){
        while(num > 0){
            int r = num % 10; // 2 
            str += r + '0';
            num = num / 10; 
        }
    }else{
        str += num + '0';
    }
    cout << "num->" << str << endl; 
    return str;
}
    
int strToNum(string str){
    int num = 0;
    if(str.size() > 1){
        
        for(auto i: str){
            num =  num*10 + (i - '0');
        }
        return num;
        
    }else{
        int value = (int) str[0];
        value -= '0'; // minus to get to value 9...
        return value;
    }
}

string encode(vector<string>& strs) {
        string str = "";

        for(auto i: strs){
            //str += i.size() + '0';
            str += reverseString(numToString(i.size()));
            
            str += '#';
            str += i;
        }

        return str;

    }
    
    
vector<string> decode(string s){
    vector<string> strs;
    string num;
    string str="";
    int currentNum = 0;
    //cout << s;
    for(int i=0;i<s.size();i++){
        
        if(s[i] == '#'){ 
            currentNum = strToNum(num);
           // cout << currentNum << endl;
            num = "";
            for(int j = i+1; j <= i+currentNum; j++){
                str += s[j];
            }
           // cout << str << endl;
            strs.push_back(str);
            str = "";
            i += currentNum; //resetting i to resume loop.
            
        }else{
            num += s[i]; // 0
        }
    }
    return strs;
}

int main() {
    // Write C++ code here
    vector<string> strs = {"AjayVeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimesVeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimes space->VeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimesVeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimesAjay"};
    string str = encode(strs);
    cout << "Encoded String->" <<  str << endl;
    
    //cout << strToNum("1") << endl;
    
    vector<string> de;
    de = decode(str);
    
    cout << "decoded vector" << endl;
    for(auto i: de){
        cout << i << " ";
    }
    
    //cout << reverseString("231") << endl;
    
    return 0;
}