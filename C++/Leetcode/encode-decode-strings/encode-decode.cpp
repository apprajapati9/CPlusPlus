// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

string encode(vector<string>& strs) {
        string str = "";
        for(auto i: strs){
            str += i;
            str += "||";
        }
        return str;
    }       

    vector<string> decode(string s) {
        vector<string> v;
        string str ;
        for(int i= 0; i < s.size(); i++){
            cout << s[i] << " ";
            if(s[i] == '|' && s[i++] == '|'){ //whenever we do s[i++] == '|', it actually increments the value of i and skips that element in for loop, be careful with this.
                v.push_back(str);
                //cout << "value pushed: " << str << " " <<endl;
                str = "";
                
            }else{
                str += s[i];
                //cout << "value pushed: " << str << " " <<endl;
                
            }
        }
        return v;
    }

int main() {
    vector<string> v = {"neet","code","love","you"};
    string str = encode(v);
    cout << encode(v) << endl;
    
    vector<string> n;
    n = decode(str);
    
    cout << endl << "decoding.." << endl;
    for(auto i: n){
        cout << i << " ";
    }

    return 0;
}