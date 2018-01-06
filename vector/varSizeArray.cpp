#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    // number, and query 
    int n, q;
    cin >> n; // how many numbers to take input? 
    cin >> q; // query
    
    vector< vector<int> > nqArray(n);

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j=0; j < k ; j++){
            int data;
            cin >> data;
            nqArray[i].push_back(data);
        }
    }
   
//    for(int i = 0; i < nqArray.size(); i++){
//       for(int j =0; j < nqArray.at(i).size(); i++){
//           cout << nqArray[i].;
//       }
//    }
//    for(int i=0; i<nqArray.size(); i++){
//         for(int p=0; p<nqArray.at(i).size(); p++){
// 		    cout << nqArray[i][p] << "+";
//         }
//    }

//    vector<int> query(q);
   //query.reserve(q);
   //vector< vector<int> > jquery(q);
    vector<int> answers;

   
   for(int i =0 ; i < q; i++){
        int p;
        int ind;
        cin >> p;
        cin >> ind;

        answers.push_back(nqArray[p][ind]);
        //jquery[position].push_back(index);
        // cout << nqArray[position][index];
   
   }

    for(int i = 0; i < answers.size(); i++){
        cout << answers[i] << " ";
    }
   


    return 0;
}


// how to initialize and print vector ?

// vector doesn't need size, nor it needs to be deleted after use
//  vector<char> array;

//     char c = 0;

//     while( c != 'x'){
//         cin >> c;
//         array.push_back(c);
//     }

//     for(int i = 0 ; i < array.size(); i++){
//         cout << array[i] << ' ';
//     }

// same as vector 

