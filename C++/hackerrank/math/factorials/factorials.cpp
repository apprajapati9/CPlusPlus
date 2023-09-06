#include <bits/stdc++.h>

int main(){
    int n = 0;
    std::cout << "Enter a num" << std::endl;
    std::cin >> n;
    std::cout << n << std::endl;

    double factorial = 1;
    while(n!=0){
        factorial *= n;  // 6! = 6*5*4*3*2*1 = 720 answer
        n--;
    }
    //equation for factorial =  n!=n*(n-1)!

    std::cout << factorial << std::endl;

    return 0;
}