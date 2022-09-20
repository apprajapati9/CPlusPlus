#include<iostream>
#include<vector>

using namespace std;

int main(){

    int sizeOfVector = 0;
    vector<int> v;

    cout << "How many elements in an array?" << endl;
    cin >> sizeOfVector;

    int input;
    for(int i=0; i < sizeOfVector; i++){
        cin >> input;
        v.push_back(input);
    }

    int target;
    cout << "Enter target ";
    cin >> target;
    cout << endl;

    int start = 0;
    int end = v.size()-1;
    cout << "end index = " << end << endl;
    int middle;

    int index = -1;

    while(start <= end){
        middle = (start + end) / 2;
        cout << "middle is= " << middle << endl;

        if(v[middle] == target){
            cout << middle << " is target" << endl;
            index = middle;
            start = middle + 1;
        }

        else if( target > v[middle]){
            start = middle + 1;
        }

        else if(target < v[middle]){
            end = middle - 1; 
        }
        
    }

    cout << "Num not found" << endl;
    

    return 0;
}