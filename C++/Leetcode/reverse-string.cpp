#include<iostream>

using namespace std;


//method to swap without extra array.
char* swap(char* arr, int a, int b){
    char temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    
    return arr;
}

void swapWithoutExtraMemory(){
    string name = "123456"; // 5 is size

    //convert into character
    char arr[name.size()]; // [0,1,2,3] = [y,a,j,a]
    
    for(int i=0;i<name.size();i++){
        arr[i] = name[i];
    }
    
    int mSize= name.size()-1; // 2
    
    for(int i = mSize; i > mSize/2; i--) { // 4    4 - 
        int currentIndex = (name.size()-1) - i;  
        swap(arr, currentIndex, i);
    }

    for(auto i: arr){
        cout << i << ",";
    }
}

void swapWithArray(){
    string name = "ajay"; // 5 is size
    
    //convert into character
    char arr[name.size()]; // [0,1,2,3] = [y,a,j,a]

    for(int i = name.size()-1; i >= 0; i--) { // 4    4 - 
        cout << i << endl;
        int currentIndex = (name.size()-1) - i;  
        // (size-1) = 4, - 4  = 0 
        // size -1  = 4, 3 =  1
        // size -1 = 4, 2  =2 
        arr[currentIndex] = name[i];
    }

    for(auto i: arr){
        cout << i << ",";
    }
}

int main(){

    swapWithoutExtraMemory();
}