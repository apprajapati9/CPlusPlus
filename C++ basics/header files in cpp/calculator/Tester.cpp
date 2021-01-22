#include<iostream>
#include "calculator.h"

using namespace std;

int testSuite( int BASE, int EXPONENT, int RESULT) {

	int passed = 0; 
	int result;
	result = power( BASE, EXPONENT ) ;
	if( result == RESULT){
		cout << "Raise to power test passed" << endl;
		passed++;
	}else{
		cout << "Raise to power test failed" << endl;
	}

	result = exponent( RESULT, BASE);
	if( result == EXPONENT) {
		cout << "Find expontent test passed " << endl;
		passed ++ ;
	}else{
		cout << "Find exponent test failed" <<endl;
	}

	return passed;
}
