#include <iostream>
#include <vector>
/*
Problem: Write a function which will take an integer array as an input 
and return all the integers that doesn't appear more than once in it. 

input : array[] = 1,2,3,3,4,4,5,3,5
output: {1,2}

*/

using namespace std;

void printArray(vector<int> &v){
    if(v.size()>=1){
        cout << "[";
        for(int i= 0; i < v.size(); i++){
            cout << v[i];
            if(i == v.size()-1){
                cout <<"";
             }else{
                cout << ",";
            }
         }
         cout << "]" << endl;
    }else{
        cout << "All elements appear more than once.";
    }
    
}

int main(){

    int arraysize = 0;
    vector<int> answer;
	cout<<"how many values in array?" << endl;
	cin >> arraysize;
    
    int array[arraysize-1]; //for example 6... array[6] = 0, 1, 2, 3, 4, 5
				
	for(int i=0; i < arraysize; i++ ){
		cout << "element= " << i+1 << " ";
		cin >> array[i];
	}
    
    for (int i= 0; i<arraysize; i++){
        cout << array[i] << ","; 
    }
    cout << endl;

    int counter = 0;
    for(int i=0; i < arraysize; i++){
        cout << "i=" << array[i] <<endl;
        for(int j=0; j < arraysize; j++){
            cout << "j="<< array[j] <<endl;
            if(array[i] == array[j]){
                counter++;
                if(counter > 1){
                    break;  
                    //limits full iteration of array if already found more than once 
                }
            }
        }
        if(counter == 1){
           counter = 0;
           answer.push_back(array[i]);
        }else{
            counter = 0;
        }
    }
    printArray(answer);
    return 0;
}
//TODO : Return answer as int array from function 