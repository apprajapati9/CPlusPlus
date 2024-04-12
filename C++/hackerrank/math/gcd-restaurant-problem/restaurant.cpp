#include<iostream>

using namespace std;

void swapByPointers(int *a, int *b){
    int temp;

    if(b < a){
        temp = *b;
        *b = *a;
        *a = temp;
    }
}

void swapByReference(int &a, int &b){
    int temp;

    if(b < a){
        temp = b;
        b = a;
        a = temp;
    }
}

//Eucledean algorithm for GCD
int gcd_PassByRef(int &a, int &b){
    swapByReference(a, b);

    int r = 1;
    while(r != 0){
        r = b % a;
        b = a;
        a = r;
    }

    return a!=0?a:b;
}

int gcd_PassByValue(int a, int b){

    int r = 1;
    while(r != 0){
        r = b % a;
        b = a;
        a = r;
    }

    return a!=0?a:b;
}

void print(int a, int b){
    cout << a << "," << b << endl;
}

int restaurant(int a, int b){
    int div = gcd_PassByValue(a, b);
    return (a / div) * (b / div);
}

//Just another way- start from the lowest and keep checking for remainder.
int gcd_(int a, int b){
    int result = (a < b) ? a : b;
    while (result > 0){
        if(a % result ==0 && b % result == 0){
            break;
        }
        result--;
    }
    return result;
}

/*
Restaurant - https://www.hackerrank.com/challenges/restaurant/problem

Martha is interviewing at Subway. One of the rounds of the interview requires her to 
cut a break of size L*B into smaller idential pieces such that each piece is a square
having maximum possible side length with no left over piece of bread.

Note: This challenge is mainly for math that is worded in order to test your ability to understand
underlaying math concept.

"having maximum possible side length" - this line points to GCD. 
Greatest common divisor will give us the maximum possible side length of 2 numbers.

in the example test case
6 and 9 = 54.
GCD = 3.
GCD=3 means greatest commond piece is 3*3 = 9
54/9= 6

6 is the answer.

Other helper methods are given. Also added 2 ways to find GCD.
*/

int main(){

    int a = 6;
    int b = 9;

    cout << "restaurant ans=" << restaurant(a, b) << endl;
    return 0;
}