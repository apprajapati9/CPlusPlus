#include <bits/stdc++.h>

/* Problem statement:

If a given number of attendees, n, shakes hands exactly one time with every other attendee,
how many handshakes are there?

for example, n=3, so possible handshakes are, 

1->2
1->3
2->3
Thus 3 handshakes. 

Thoughts:
The visualization helps here. These are unique handshakes by which I mean is that
one handshake is equivalent of handshake back and forth. For example, 2 attendees, 
1 handshakes with 2, and vice cersa which means 2 handshakes, however we only calculate unique ones.
Thus, 2 attendees only shakes hands 1 time because we don't want to calculate same person handshake with same counterpart.

4 attendees, so 4*4 = 16 possible permutations. 
only 1 person at a time shakes hands with others which means 4-1, 1 person only can shake hands 
with 3 person. Thus n*(n-1) possible combinations. 

4(4-1)=12. Now 12 handshakes are not calculated uniquely as I described above. 1 handshake to
the other, let it be 2, and 2 shakes with 1, is 1 handshake thus we divide it by 2. 

Equation for solving= n*(n-1)/2  will give us the amount of handshakes needed.
*/

int main(){
    int i = 0;
    std::cout << "How many attendees? : ";
    std::cin >> i;

    std::cout << "Answer: paired handshakes->" << i * (i - 1) / 2 << std::endl; // equation=i*(i-1)/2
}