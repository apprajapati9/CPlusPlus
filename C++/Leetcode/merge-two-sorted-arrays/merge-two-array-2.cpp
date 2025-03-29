#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v){
    for(size_t i = 0; i < v.size(); i++) {
     	cout << v[i] << ","; 
    }
    cout << endl;
}

/*
Merge two sorted arrays without extra space.

The main idea to remember is that instead of starting left and right index from 0,
we are starting from the end and taking bigger elements and filling based on the mergedIndex, which points to the last element and goes down as we fill elements.
*/
void merge(vector<int> &a, vector<int> &b, int m, int n) {

    //initialize two pointers for the end of the two arrays and one pointer for the end of merged array
    int left = m-1;
    int right = n-1;

    int mergedIndex = m+n-1;
    cout << left << right << mergedIndex << endl;
    cout << endl << endl;

    while(right >= 0) {

	if(left >= 0 && a[left] > b[right]) { //left >= 0 is necessary otherwise it checks and compares with garbage values
	    a[mergedIndex] = a[left];
	    mergedIndex--;
	    left--;
	}else{
	    a[mergedIndex] = b[right];
	    mergedIndex--;
	    right--;
	}
    }
    printVector(a);
}


int main(){
    vector<int> a = {1,2,3,0,0,0}; //m
    vector<int> b = {2,5,6};

    vector<int> a1 = {4,5,6,0,0,0}; //m=3, n =3
    vector<int> b1 = {1,2,3};

    vector<int> a2 = {4,0,0,0,0,0}; //M=1, n = 5
    vector<int> b2 = {1,2,3,5,6};

    vector<int> a3 = {1}; //m=1, n = 0
    vector<int> b3 = {};

    vector<int> a4 = {0,0,3,0,0,0,0,0,0};
    vector<int> b4 = {-1,1,1,1,2,3};

    vector<int> a6 = {1,2,3,0,0,0};
    vector<int> b6 = {4,5,6};

    vector<int> a5 = {1,2,4,5,6,0}; //5
    vector<int> b5 = {3}; //1

   // merge(a ,b ,3,3);
    //merge(a1,b1,3,3);
 // merge(a2,b2,1,5);
 // merge(a3,b3,1,0);
  merge(a4,b4,3,6);

    return 0;
}
