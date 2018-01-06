#include <iostream>

using namespace std;

// This is C way of pass by reference 
// in C++ this is known as pass by pointer
inline void swap( int *a, int *b){

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// c++ call by reference 

void swap_(int &x, int &y){

	int temp;
	temp = x;
	x = y;
	y = temp;

}

int main(){

	int x = 100, y =200;

	//swap(&x, &y); // pass by pointers
	swap_(x, y);
	cout << "x : "<< x << "y : "<< y << endl; 
	
	return 0;
}

// c++ has three ways 
//1. call by value, 2. call by pointer , 3. call by reference 


