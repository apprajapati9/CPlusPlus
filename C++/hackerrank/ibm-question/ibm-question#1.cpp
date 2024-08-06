
/*
Problem statement :
    Consider a pair of integers, (a,b), the following operations can be performed on a,b in any order
    zero or more times.

    a,b -> (a + b, b)
    a,b  -> (a, a + b)

    Return a string that denotes whether or not (a,b) can be converted to (c,d) by performing the operation
    zero or more times.

    a,b - 1,1
    c,d - 5,2

    1+1, 1 -> 2, 1,
        2+1, 1 -> 3, 1
            3+1, 1 -> 4 + 1;
                4+1, 1 -> 5, 1 (5 FOUND)
    
    1, 1+1 -> 1, 2  ( 2 FOUND.. ) 
        1, 1+2 -> 3

    so (5,2) is possible.


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

#include<iostream>

using namespace std;

void isPossible(int a, int b, int c, int d){
    bool alternate = false;

    if(c > d){
        int temp = d;
        d = c;
        c = temp;
    }

    cout << "c and d-> " << c << " " << d << endl;

    int tempA = a;
    while(tempA < c){
        tempA = tempA + b; 
        cout << tempA << " ";
    }

    cout << endl;
    int tempB = b;
    while( tempB < d){
        tempB = tempA + tempB;
        cout << tempB << " ";
    }

    cout << endl
         << "a-b= " << tempA << "-" << tempB << endl;
    if(tempA==c && tempB==d){
        cout << "Yes";
    }else{
        cout << "No";
    }

}

int main(){

    //int a = 1, b = 1, c = 5, d = 2;
    //int a = 1, b = 4, c = 5, d = 9; //Yes answer test case
    int a = 1, b = 2, c = 3, d = 6; // no answer test case

    isPossible(a, b, c, d);
}