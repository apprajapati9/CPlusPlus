#include<iostream>

using namespace std;

long long modulo = 1000000007;

/*
Summing N series - https://www.hackerrank.com/challenges/summing-the-n-series/problem

Sequence - Tn = n*2-(n-1)*2

This series comes down to square of the Sn, where N is the number you want to find out.

If N = 5 then based on the equation,
25-16 = 9

N is 5 so series is up to N;

which comes down to 25 which is square of 5.

*/

long long sumNSeries(long long n){
    n %= modulo;
    return n * n % modulo;
}

int main(){

    cout << sumNSeries(5351871996120528) << endl;

    return 0;
}

/*
Testcase

5351871996120528
2248813659738258
2494359640703601
6044763399160734
3271269997212342
4276346434761561
2372239019637533
5624204919070546
9493965694520825
8629828692375133

*/