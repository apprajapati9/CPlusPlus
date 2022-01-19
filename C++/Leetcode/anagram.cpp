#include<iostream>
#include<bits/stdc++.h>
// must include map 
#include <map>

using namespace std;

void printHashMaps(map<char,int> &mapStr1, map<char,int> &mapStr2){
    map<char, int>::iterator itr;
    

    cout <<"Map1" << endl;
    for(itr = mapStr1.begin(); itr != mapStr1.end(); ++itr){
        cout << "\t" << itr->first << "," << itr->second << endl;
    }
    cout <<"Map2" << endl;
    for(itr = mapStr2.begin(); itr != mapStr2.end(); ++itr){
        cout << "\t" << itr->first << "," << itr->second << endl;
    }
}

int main(){

    string str1;
    string str2; 

    std::cout << "Enter first string!: "<< endl;
    std::cin >> str1;

    std::cout << "Enter seconnd string : " <<endl ;
    std::cin >> str2;

    map<char, int> mapStr1;
    map<char, int> mapStr2;

    char char_array[str1.length()+1];
    char char_array2[str2.length()+1]; 

    int size_str1 = str1.length();
    int size_str2 = str2.length();

    for(int i=0; i< size_str1; i++){ // <=size_str1, if wants to add null character.
        // char_array[i] = str1[i];
        if(mapStr1.find(str1[i]) != mapStr1.end()){
            //if key found...
            int curr = mapStr1[str1[i]];
            cout << "curr value: " << curr << endl;
            mapStr1[str1[i]] = curr+1;
           // mapStr1.insert(pair<char, int>(str1[i],curr+1));
            // above commented code of adding key pair doesn't work.
   
        }else{
            //if key not found, initialize with 1. 
            mapStr1[str1[i]] = 1;
        }
    }

        for(int i=0; i< size_str2; i++){ // <=size_str1, if wants to add null character.
        // char_array[i] = str1[i];
        if(mapStr2.find(str2[i]) != mapStr2.end()){
            //if key found...
            int curr = mapStr2[str2[i]];
         
            mapStr2[str2[i]] = curr+1;
           // mapStr1.insert(pair<char, int>(str1[i],curr+1));
            // above commented code of adding key pair doesn't work.
   
        }else{
            //if key not found, initialize with 1. 
            mapStr2[str2[i]] = 1;
        }
    }

    //if you want to print hashMap
    //printHashMaps(mapStr1, mapStr2);

    if(str1.length() != str2.length()){
        cout << "Diff Size. Not anagrams." << endl;
    }else{
        
        auto pred = [] (auto mapStr1, auto mapStr2) {
            return (mapStr1.first == mapStr2.first) && 
                    (mapStr1.second == mapStr2.second) ;
        };

        if(std::equal(mapStr1.begin(), mapStr1.end(), mapStr2.begin(), pred)){
            cout << "Anagrams.." << endl;
        }else{
            cout << "Not anagrams.." << endl;
        }

    }

    return 0;
}