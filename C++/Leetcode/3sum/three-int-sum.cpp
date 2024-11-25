#include <iostream>
#include <unordered_set>

using namespace std;

/*
Given an integer array NUMS, return all the triplets [num[i], num[j], num[k]] where
num[i] + num [j] + num[k] == 0 and indices i j and k are all distinct.

The out put should not containt any duplicate triplets. You may return the output and the triplets in any order.

Example:
    nums = [-1,0,1,2,-1,-4]
    output:  [[-1,-1,2], [-1, 0, 1]]

    n 0 1 2  = -1  0  1 = 0
    n 1 2 4  =  0  1 -1 = 0
    n 0 3 4  = -1  2 -1 = 0

    the distinct triplets are [-1,0,1],[-1,-1,2] that have sum 0 and also their indexes are all distinct. 

    2. nums = [0,1,1] , output : [] because no possible solution.

    3. nums = [0,0,0], output : [0,0,0]
    
*/
// {2,1,3,8,6,4,5}  curr arr

// array exampl test = {8,6,1,7,3,2}//4
void sort(int *arr, int start, int end, int mid) {


    // cout << "printing full array " << endl; 
    // for(int i =start; i<= end; i++){
    // 	cout << arr[i] << ".,";
    // }
    // cout << endl;
    

    int first = start ; //0 2, mid-2= 2
    int second = mid + 1;

//    cout << "first half-> " << arr[first] << "," <<arr[mid] << endl;
  //  cout << "second half-> " << arr[second] << ", "<< arr[end] << endl;
    //cout << endl;

    int s1 = mid - start + 1;
//    cout << "s1 " << s1 << endl;
    int s2 = end - second + 1;
  //  cout << "s2 " << s2 << endl;

   // cout << endl;

    if(s1 == 1 && s2 == 1){
	if(arr[start] > arr[second]){
	    int temp = arr[start];
	    arr[start] = arr[second];
	    arr[second] = temp;
	}
	return;
    }

    int totalSize = s1 + s2;
    int mergedArr[totalSize] = {0};
    int index = 0;
    
    while(s1 != 0 && s2 != 0){

	if(arr[first] < arr[second] || arr[first] == arr[second]){
	    mergedArr[index] = arr[first];
//	    cout << "index " << index << ", added : " << mergedArr[index] << endl;
	    first++;
	    s1--;
	    ++index;
	}

	if(arr[second] < arr[first]){
	    mergedArr[index] = arr[second];
//	    cout << "index " << index << ", added : " << mergedArr[index] << endl;
	    second++;
	    s2--;
	    ++index;
	}
    }


    if(s1>0) {
//	cout << "first half remaining.. " << s1 << endl;
	for(int i=0; i< s1; i++){
	    mergedArr[index] = arr[first];
	  //  cout << "  " << arr[first] << ",";
	    first++;
	    index++;
	}
	cout << endl;
    }
    if(s2>0) {
//	cout << "second half remaining.. " << s2 << endl;
	for(int i=0; i< s2; i++){
	    mergedArr[index] = arr[second];
	    second++;
	    index++;
	}
	cout << endl;
    }



    int j = 0;
    for(int i = start; i <= end; i++) {
	arr[i] = mergedArr[j];
//	cout << "...." << mergedArr[j]; 
	j++;
    }

    //cout << endl;    

   // cout << endl;
    
    // for(auto i : mergedArr){
    // 	cout << i << ",";
    // }
    //cout << endl;


}


// pass an array
void mergeSort(int * arr, int start, int end, int size) {

    //While calculating mid (end-star)/2 happens first and then +start
    int mid = start + ((end - start) / 2); // 0 + (5 - 0)/ 2 = 2
    // cout << "    start-- " << arr[start] << endl;
    //cout << "    mid-- " << arr[mid] << endl;
    //cout << "    end --> " << arr[end] << endl;
    //cout << " ----- " << endl; 
    if(start <  end) {
	mergeSort(arr, start, mid, size);
	// cout << "mid+ " << endl;
	mergeSort(arr, mid+1, end, size);

	sort(arr, start, end, mid);
    }
    
}



int main(){


    // CM u to get to the outer brackets of a block of code.
    int arr[] = {-1,0,1,2,-1,-4};
    //int arr[] = {0,1,1};

    int size = sizeof(arr) / sizeof(int);
    
    cout << "size- > ajay " << size << endl;

    // int arr[][] = {
    //   {-1,0,1},
    //   {}
    // };

    unordered_set<int> set;
    
    for(int i = 0; i < size; i++){
	for(int j = i+1; j < size; j++){ 
	  
	    for(int k = 0; k < size; k++){
	      
	      if(k != i && k != j){

		  if(arr[i] + arr[j] + arr[k] == 0)
		  {
		      // 0, 1,

		      //		      cout << "pair found " << endl;

		      //		      cout << arr[i] << ", " << arr[j] << ", " <<arr[k] << endl;

		      //cout << i << ", " << j << ", " << k << endl;

		      int ijk[3] = {arr[i], arr[j], arr[k]};
		      mergeSort(ijk, 0, 3-1, 3);
		      string ajay ="ajay";
		      for(auto i : ijk){
			  cout << i << ", ";
		      }
		      
		    }		    
	      }else{
		//cout << "skipping - " << i << " and " << j << endl;
	       }

	    }
	}
    }

    //Important note: when you return an array from a function, the array decays into a pointer. This means
    // sizeof() operator will give the size of the pointer, not size of original array thus result will be wrong.
    // int size2 = sizeof(string)/sizeof(int);

    int array[] =  {2,1,3,8,1,8,6,4,4,5,1}; //{8,6,1,7,3,2}; // {2,1,3,8,6,4,5};
    int arrSize = sizeof(array)/ sizeof(int);

    //breakdown --  0 1 2 3 4 5

    // 0 as start on left side...
    // 0 5 - 2 mid ( 2 end )
    // 0 2 - 1 mid ( 1 end )
    // 0 1 - 0 mid ( 0 end )
    // 0 0 - 0     ( 0 end ) -- call stack breaks here!! start < end = false)
    //right side (mid + 1, end ) = end is last call stack's end.
    // 1 1 - 1 mid       -- call stack break because start < end == false.
    // 2 2 - 2 mid
    //        (0+(5-0)/2)
    
    mergeSort(array, 0, arrSize-1, arrSize);

    for(int i = 0 ; i < arrSize; i++){
	cout << array[i] << ",";
    }
    
    return 0;
}
