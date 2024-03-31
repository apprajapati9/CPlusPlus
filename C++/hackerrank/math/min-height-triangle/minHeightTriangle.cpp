#include<bits/stdc++.h>

/*
Problem statement: Given base and area, find the smallest integer H, such that there exists a tringle
of height h, base b, having an area of at least a.
Input: base=4, and area =6
answer= 3

Thoughts:
Formula needed is triangle area. Area =1/2*b*h.
From in this problem, we have base and area but not h. 

So we can find height by the equation - Height = 2A/base
and similarly Base = 2A/height


*/

int findHeight(int base, int area){
    return (2 * area + base - 1) / base;  
    //Simple formula is 2A/BASE but problem states we have to return integer
    //so to round up we are adding same amount of base to inflate area which will give us 
    //rounded down value by default in int.
    //The trick is to add exactly the same amount in area but -1 so it will inflate by 1 only,
    //thus 11.76 (approx) will be rounded up to 12.76 and int will print only 12 (which is the right answer)
}

int main(){
    int base = 0, area = 0;
    std::cout << "Enter base and area" << std::endl;
    std::cin >> base >> area;

    std::cout << "Height=" << findHeight(base, area) << std::endl;
    return 0;
}