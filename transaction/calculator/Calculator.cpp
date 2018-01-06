#include <iostream>
#include "calculator.h"

using namespace std;

int power( int base, int exp ) {
	int i , result = 1;
	for( i=0;i< exp; i++){
		result *= base;
	}
	return result;
}

// Exponent finding --  divide result by base until its greater or equals to base , keep the counter each time
int exponent( int result, int base){
	int exp = 0;
	while( result >= base) { // 32 > 2 , 16 > 2 ,2 = 2
		exp++; // 1, 2 ,3, 4 , 5
		result /= base; // result = result/base(32/2) = 16 , 16/2 = 8,  8/2, 4/2 = 2, 2/ 2
	}
	return exp;
}

int main(){

	int po, exp;

	po = power( 2, 5);
	exp = exponent(power(2, 5), 2);

	cout << "power :" << po << " exp : " << exp;

	return 0;
}