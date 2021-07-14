#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   
    int limit;
    cin >> limit ;
    int array[limit];
    cout << "limit: " << limit << endl;
    for( int i = 0; i < limit; i++ ){
        cin >> array[i];
    }
    
    // sort an array ascending 
    //std::sort(array, array+limit);
    
    for(int i = 0; i < limit; i++){
        cout << array[limit - i - 1] << " ";
    }

    // 

    return 0;
}


