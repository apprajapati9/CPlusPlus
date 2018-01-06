#include<iostream>

using namespace std;

#include "tester.h"

int main(){

	int passed = 0;
	passed += testSuite(3, 3, 125);
	passed += testSuite(5, -3, 125);
	cout << passed << "Tests passed" << endl;

}
