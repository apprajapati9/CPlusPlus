// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int *farray; 

void printArray(int* any, int size){
    for(int i=0; i < size; i++){
        cout << any[i] << endl;
    }
}

int* swap(int* left, int lSize, int* right, int rSize){
    int l[lSize];
    int r[rSize];
    
    for(int i=0;i<lSize;i++){
        l[i] = left[i];
    }
    
    printArray(l,lSize);
    
    for(int i=0;i<rSize;i++){
        r[i] = right[i];
    }
    
    printArray(r,rSize);
    
    int farray[lSize+rSize];  //local stack allocated array..

    //int *farray = new int[lSize + rSize];

    for(int i=0;i<lSize+rSize; i++){
        farray[i]= 0;
    }
    
    printArray(farray, 4);
    if(l[0]>r[0]){
        for(int i=0;i<rSize;i++){
            farray[i] = r[i];
        }
        
        printArray(farray,rSize);
        
        for(int i=0;i<lSize;i++){
            farray[i+rSize]=l[i];
        }
        cout << "-0--" <<endl;
        printArray(farray,lSize+rSize);
    }

    //this is local variable so pointer returns local pointer to that array,
    //however, when function finishes, it destorys that memory so accessing that pointer..
    //will have nothing there because memory is destoryed, thus accessing that pointer cause seg fault.
    
    //to fix this you can just dynamically allocate memory.
    return farray;
}

int main() {
    // Write C++ code here
    int arr1[] ={5,6};
    int arr2[] ={7,10};
    
    int *a = swap(arr2, 2, arr1, 2);
    
    printArray(a,4);

    //delete[] farray;

    return 0;
}

/*

#include <iostream>

using namespace std;


void printArray(int* any, int size){
    for(int i=0; i < size; i++){
        cout << any[i] << endl;
    }
}

int swap(int* left, int lSize, int* right, int rSize){
   
    int final[lSize+rSize];
    if(left[0]>right[0]){
        for(int i=0;i<rSize;i++){
            final[i] = right[i];
        }
        
        for(int i=0;i<lSize;i++){
            final[rSize+i]=left[i];
        }
    }
    return 0;
}


//print in reverse order bcz recursion will continue from the last condition that break the loop
int* merge(int* a, int start, int end, int m){
 
    
    cout << "start, middle, end -> " << "(" << a[start] << "," << a[m] << "," << a[end] << ")" <<  endl;
    
    // int left = 
    
    cout << endl;
    cout << "start, end-> " << "(" << start << "," << end << ")" << ", m-" << m << endl;
    
    cout << "------------------------------------------" << endl;

    int leftC = m - start +1 ; // 1-0 = 1 , upper bound index
    int rightC = end-m; //6-3 - 1 = 3-1 =2

    int leftArray[leftC];
    int rightArray[rightC];

    int counter = 0;
    for(int i=start; i<= m; i++){
        cout << a[i] << "," << endl;
        leftArray[counter] = a[i];
        counter++;
    }
    cout << "<-->" <<endl;
    
    
    counter= 0;
    //1,2,3,4,  5,6,7  -- m+1  .. end 6
    for(int i=m+1; i<= end; i++) {
        cout << a[i] << "," << endl;
        rightArray[counter] = a[i];
        counter++;
    }
    // cout << leftC << endl; //0- 3 = total 4 elements
    // cout << rightC << endl; // 0-2= total 3 elements
  
    // bool isTwo = leftC == rightC;
    
    
    // printArray(leftArray, leftC);
    // cout << endl;
    // printArray(rightArray, rightC);
    
    
     if(leftC == rightC){
         int c=0;
         
         for(int i=0; i< rightC; i++){
             for(int j = 0; j < rightC; j++){
                 if(leftArray[i] > rightArray[j]){
                     cout << "---->" << a[i+start] << endl;
                     cout << "---->" << a[m+1+j] << endl;
                    //a[i+start] = rightArray[j];
                   // a[m+1+j] = leftArray[i];
                 }
             }
         }
        // if(leftArray[0] > rightArray[0]){
        //         for(int i = start; i <= m ; i++){
        //             a[i] = rightArray[c];
        //             c++;
        //         }
                
        //         c=0;
        //         for(int i = m+1; i <= end ; i++){
        //             a[i] = leftArray[c];
        //             c++;
        //         }
        //     }
    }
    
    if(rightC < leftC){
        
    }
    
    // while(leftC > 0 || rightC > 0){
        
    //     if(a[start] > a[m+1]) {
    //         int temp = a[start];
    //         a[start] = a[m+1];
    //         a[m+1] = temp;
    //     }
        
    //     start++;
    //     m+1;
        
    //     leftC--;
    //     rightC--;
    // }
  
  
    cout << "end!" << endl;
    
    return a;
   // break;
}

void mergeSort(int arr[], int start, int end){
  
  if(start < end){
    int middle = start + (end-start)/2;// 5+(9-5)/2 = 5+4/2=4
  
  //cout << "start ->" << start << endl;
  //cout << "middle-> " << middle << endl;
 // cout << "end ->" << end << endl;
  //cout << "---------------------left" << endl;
  mergeSort(arr, start, middle); 
  //cout << "---------------------right" << endl;
  mergeSort(arr, middle+1, end);

    merge(arr, start, end, middle);
  }
  
}

int main()
{
    int arr[] = {70,30,49,50,40,20,1,77}; //{1,5,4,3,10,2,6,7,9,8}; // 9 items *  4 bytes- 36 sizeof
    
    int size = sizeof(arr)/sizeof(int); //sizeof gives size in bytes.
    cout<< "size-> " << size << endl;
    mergeSort(arr,0, size-1);
    
     //cout << "array print-> " << endl;
    for(int i=0; i<size; i++){
        cout << arr[i] << ",";
    }
    cout << endl;

    return 0;
}


*/ 