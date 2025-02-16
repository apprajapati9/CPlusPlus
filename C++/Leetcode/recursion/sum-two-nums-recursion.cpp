#include <iostream>

using namespace std;

static int counter = 0;

/*
square.. 2^8 = 2*2*2*2*2*2*2*2

*/

int power(int a, int b){
    if(a == 0) {
	return 1;
    }else if(b == 0) {
	return 1;
    }
    else {
	counter++;
	return power(a, b-1) * a;
    }
}


int mul(int a, int b){// 8,2
    if(a == 0) {
	return 0;
    }else if(b == 0) {
	return 0;
    }else{
	counter++;
	return mul(a, b-1) + a; // 8,1 + 8
    }
}

/*
1. (8,4)
2. (8,3) + 8 + 32
3. (8,2) + 8 = 24
4. (8,1) + 8 = 16
5. (8,0) + 8 = 8

Now turn it upside down, so callstack would look like this
8,16,24,32 from 5 to 1. 
*/

int add(int a , int b) { // 1,2 ;; 1,1
    if( a == 0) {
	return b;  
    }else if ( b == 0) {
	return a; // 1
    }else{
	counter++;
	//cout << "a " << a << " b-1 " << b << endl;
	return add(a, b-1) + 1; // add(1,1) + 1, add(1,0) + 1, 
    }
}


/* Callstack: -- 
    1. add(1,2) -> returns 3
    2. add(1,1) + 1 -> 2+1 == returns 3
    3. add(1,0) + 1 -> 1+1 == returns 2
    4. returns a == 1 

    each function 1..3 resolves and returns value to upward called function
    you can think of this as upside down stack
    1. returns 2
    2. returns 3
    3. returns 3 back as sum.
*/


int main(){
    cout << "Hello world!" << endl;

    int sum = add(1,2);
    cout << "sum " << sum << endl << " in " << counter << " iterations" << endl;

    sum = 0;
    counter = 0;
    sum  = mul(8,4);
    cout << "mul " << sum << endl << " in " << counter << " iterations";

    cout << endl;

    counter = 0;
    sum  = power(2,8);
    cout << "pow.. " << sum << endl << " in " << counter << " iterations";

    
    return 0;
}
