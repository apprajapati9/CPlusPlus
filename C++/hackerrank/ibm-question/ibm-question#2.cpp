/*
// Another question was on  regex ->
    Given a binary string, find a regex that checks whether that binary number when converted to a decimal
    is a power of two or not. 

    0101010 -> 42 in decimal - which is not a power of 2. 

    possible answer:
        If a binary number is a power of 2, then its leftmost bit must be a 1 and all other bits after that 
        if any must be a 0. 
        therefore, ^10*$ will do a job. 

        if the number can have leading zeros, use 0* at the start to match them as well
        so ^0*10*$  is a possible answer.

*/

#include <iostream>
#include <regex>
#include <algorithm>

using namespace std;

int main(){

    int num = 4;

    //convert to binary
    string binary = "";

    while(num > 0){
        int remainder = num % 2;
        binary += (remainder + '0');
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    cout << binary << endl;

    regex expression("^0*10*$"); // so all power of 2 will always have 10->000 but start is always 1 n then 00000. 
    //once you understand that this problem becomes easier.

    string ans = regex_match(binary, expression) ? "Matched" : "Not matched"; 
    cout << ans << endl;
}