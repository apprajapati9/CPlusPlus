#include <iostream>
#include <bits/stdc++.h>
#include <ctime>


using namespace std;

void search(int* a, int num, int start, int end) {
	int mid = start + (end - start) / 2; // 5/2   6+2 = 8  
	//cout << "start-end->" << start << " " << end << ", mid value " << mid <<  endl;

	if(start < end) {
	      if(a[mid] == num) {
	            cout << "Found element at index->" << mid;
	            //return;
	      }
		else if(num < a[mid]) {
			search(a, num, start, mid);
		} else if(num > a[mid]) {
			search(a, num, mid+1, end);
		}
	}else{
	    if(a[end] == num){
	       cout << "Found element at index->" << end; 
	    }else{
	      cout << "Doesn't exist!";
	    }
	}
      
}


void binarySearch(int* a, int num, int size) {
	cout << "size->" << size << endl;
	
	time_t begin = clock();
	search(a,num, 0, size-1);
	time_t end = clock();
	
	double diff = double(end - begin) / CLOCKS_PER_SEC;
    
	cout << endl;
	cout << "Time taken->" <<diff  << endl;
}

void normalSearch(int* a, int size, int num){
    
    time_t begin = clock();
    
    for(int i = 0; i < size; i++) {
        if(a[i] == num){
            cout << "Found num! at " << i << endl;
        }
    }
    time_t end = clock();
    
    double diff = double(end - begin) / CLOCKS_PER_SEC;
    cout << endl;
	cout << "Time taken->" <<diff  << endl;
}


int main()
{
// 	int arr[] = {1,3,4,6,7,9,11,30,40,50,60,71,88,91,100,105,110,111,120,140,145,150};
    //int size = sizeof(arr)/ sizeof(arr[0]);
    
    
    int size = 10000;
    int arr[size];
    
    
    for(int i=0; i< size; i++){
        arr[i] = i;
    }
	
    
    int searchNum = 5000;
    
	binarySearch(arr, searchNum, size);

	normalSearch(arr, size, searchNum);

	return 0;
}