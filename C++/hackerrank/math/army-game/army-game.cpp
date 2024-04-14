#include<iostream>

using namespace std;

int gameWithCells(int n, int m){
    return (n + n % 2) * (m + m % 2) / 4;
}

int gameWithCell(int n, int m){
    if(m*n%4==0){
        return m * n / 4;
    }else{
        m % 2 != 0 ? m += 1 : m;
        n % 2 != 0 ? n += 1 : m;
        return m * n / 4;
    }
}

/*
Problem: https://www.hackerrank.com/challenges/game-with-cells/problem - Army game
Given m and n graph, if you drop supplies at strategic points on the sheet, 
marking each drop point with a red dot. If a base (one cell) contains atleast one package inside
or on the top of its border fence, then it is considered supplied.
So given m and n, whats the min number of packages that must be drop to supply all of bases?

Overall this can be easily solved by dividing it by 4.
Problem happens when you have odd numbers which causes remainder.

Every number can be divided by 2 other than odd numbers. 
When there's odd number, only 1 needs to be added to make it divisble by 2, i.e. 3+1= 4 or 23+1=24
so adding 1 makes it divisable by 2 and if n%2==0 then n%4==0 as well 

we are adding 1 extra row or column when either m or n is odd to equalize and be able to 
divide by 4 which gives the answer correctly. We are adding 1 extra column but we aren't 
calculating it, 
for example 5x5.

we can see that 5*5 will be 25 grid lines of graph. 
25/4 = 16, 4x4 will be occupied in the graph.
remaining one line each side
5 box or cell or base in this example, only requires 2 dots to supply if you divide by 2.
so 4+2 M side, 
and +2 N side extra... which makes it 8.
And at the corner remains 1 cell that doesn't intersect any because of remainder 1..
Thus 1 extra dot.. 
total required 9 to supply to every base.  

you can do the same with 3*3 grid graph as well. 
Essentially, %2 remainder will tell us if there's extra column / row need to be calculated.
If so we can add extra row or column to evenly distribute and be divisble by 4.
Play around with graph box and visualize, it will give you clear understanding.
*/

int main(){

    //999x999 expected output = 25000
    int m =999;
    int n = 999;

    cout << gameWithCells(n, m) << endl;

    return 0;
}