#include<bits/stdc++.h>

int main(){
    float a = 3;
    float b = 2; // a:b

    float c = 0;
    float d = 5; // c:d
    //finding c which means it can be written as a:b = x:d = Find X?

    std::cout.precision(4);
    float ratio = (float) 3/2; //you must cast that to float to get decimal point 
    // cout.precision(2) can be used to show how many decimal points wanted.
    
    c = ratio * d; 
    std::cout << "ratio is=" <<ratio << " answer=" << c << std::endl;

    return 0;
}