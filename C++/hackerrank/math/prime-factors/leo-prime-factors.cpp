#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
finds factors of a particular number and stores in vector.

int n = n is the range of numbers to check for prime/factors.
*/
void find_factors(int n){

    vector<vector<int>> factors;

    vector<int> factor;

    int counter = 0;

    for (int i = 1; i <= n;i ++){
        for (int j = 1; j <= i;j++){
            if(i%j == 0){
                //cout << j << " ";
                factor.push_back(j);
            }
        }
        factors.push_back(factor);
        factor.resize(0);
       // cout << endl;
    }

    cout << "========" << endl;

    for (int i = 0; i < factors.size(); i++)
    {
        for (int j = 0; j < factors[i].size(); j++){

            cout << factors[i][j] << " ";
        
        }
        cout << ",";
    }

    //Test for accessing particular index.
    cout << "-------" << endl;
    for (int i = 0; i < factors[10].size();i++){ //n-1
        cout << factors[10][i] << endl;
    }
}

bool isPrime(int n){
    //corner case
    if(n <= 1){
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++){
        if( n % i == 0){
            return false;
        }
    }

    return true;
}


int main(){
    
    //long long n = 10000000000;
    //long long n = 500;
    //long long n = 5000;
    //long long n = 3;
    long long n = 2;

    // find_factors(n);  // this is to implement/understand the logic of finding a prime number.

    // isPrime(2) ? cout << "true" : cout << "false" << endl;

    long long product = 1;
    int counter = 0;
    for (int i = 1; i <= n; i++) {
        if(isPrime(i)){
            product *= i;
            if(product < n || product == n){
                counter++;
            }else{
                break;
            }
        }
    }

    cout << "answer: " << counter  << "product: " << product << endl;
    return 0;
}

/*
Explanation of this problem: HackerRank

Given number Q, as input indicating how many numbers to check. 
Based on Q, that many integers N are entered. 
if q=6, then 6 numbers N needs to be entered/queried.

Now each number N, will be counted as range [1,n]

In that range, you have to find prime number factors that can be below the given N. 

This is a terribly written question.

They want you to know how many unique prime factors it takes for 
the product of these prime factors to exceed the upper bound given.

For example, with 500, 2*3*5*7 = 210 and 2*3*5*7*11 = 2310, 
so there can be at most 4 unique prime factors for numbers between 1 and 500.

*/