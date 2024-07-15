#include <iostream>
using namespace std;

string numToString(int num){
    string str = "";
    int save = num;
    int divisor = 1;
    while(num > 10){
        num = num / 10; 
        divisor *= 10;
    }
    
    while(divisor != 1){
        int right = save / divisor;// 1234/ 1000 - 1, 2, 3
        save %= divisor;// 234 , 34, 4
        divisor /= 10;
        str += right + '0';
    }
    str += save + '0';
    
    return str;
}

int main() {

    int num = 0;
    cout << "Enter positive number to convert into a string ";
    cin >> num;

    while(num != 0){
        string str = numToString(num);
        cout << "converted " << num <<  " to string (0 to exit!) ->" << str << endl;
        cin >> num;
    }

    return 0;
}