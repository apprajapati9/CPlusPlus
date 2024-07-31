







#include<iostream>

using namespace std;

class Solution {
    public: 
        int myAtoi(string s){

            return 0;
        }
};

void passChar(const char* s){

    for (int i = 0; s[i] != '\0'; i++){
        cout << s[i] << " ";
    }
}

int main(){
    cout << "hello ajay11 -- welcome atoi" << endl;

    string s = "ajay";

    passChar(&s[0]);

    string num = "1234";

    cout << endl;
    for(auto i: num) {
        int num = i - '0'; // 1- 49   0 - 48 - 49-48 = 1 
        cout << (int) i << endl;
        cout << "num converted-" << num << endl;
    }

    int base = 1;
    int sum = 0;
    //int base = 0;
    for (int i = num.size() - 1; i >= 0; i--){
        sum = sum + (base  * (num[i] - '0'));
        base *= 10;
    }

    cout << "number " << sum << endl;
    return 0;
}           