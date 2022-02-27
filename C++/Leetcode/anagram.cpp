#include<iostream>
#include<bits/stdc++.h>
// must include map 
#include <map>

using namespace std;

void printHashMaps(map<char,int> &mapStr1, 
                    map<char,int> &mapStr2){
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

void isAnagram(string str1, string str2) {

    map<char, int> mapStr1;
    map<char, int> mapStr2;

    int size_str1 = str1.length();
    int size_str2 = str2.length();

    for(int i=0; i< size_str1; i++){ // <=size_str1, if wants to add null character.

        if(mapStr1.find(str1[i]) != mapStr1.end()){
            //if key found...
            int curr = mapStr1[str1[i]];

            mapStr1[str1[i]] = curr+1;
           // mapStr1.insert(pair<char, int>(str1[i],curr+1));
            // above commented code of adding key pair doesn't work.
   
        }else{
            //if key not found, initialize with 1. 
            mapStr1[str1[i]] = 1;
        }
    }

        for(int i=0; i< size_str2; i++){ // <=size_str1, if wants to add null character.
  
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

    if(str1.length() != str2.length()){
        cout << "Diff Size. Not anagrams." << endl;
    }else{
        
        auto pred = [] (auto mapStr1, auto mapStr2) {
            return (mapStr1.first == mapStr2.first) &&  //can work without comparing keys
                    (mapStr1.second == mapStr2.second) ;
        };

        if(std::equal(mapStr1.begin(), mapStr1.end(), 
            mapStr2.begin(), pred)){
            cout << "Anagrams.." << endl;
        }else{
            cout << "Not anagrams.." << endl;
        }

    }
}

bool isAnagramBool(string str1, string str2){
    int s1 = str1.length();
    int s2 = str2.length();

    if(s1 != s2){
        return false;
    }else{

        map<char, int> map1;
        map<char, int> map2;
        
        for(int i =0; i < s1 ; i++) {
            if(map1.find(str1[i]) != map1.end()){
                int occurance = map1[str1[i]];
                map1[str1[i]] = occurance+1;
            }else{
                map1[str1[i]] = 1;
            }

            if(map2.find(str2[i]) != map2.end()){
                int occurance = map2[str2[i]];
                map2[str2[i]] = occurance+1;

            }else{
                map2[str2[i]] = 1;
            }
        }

        auto pred = [] (auto map1, auto map2) -> bool {
            return (map1.first == map2.first) && 
                (map1.second == map2.second);
        };

        if(equal(map1.begin(), map1.end(), 
                map2.begin(), pred)){
            return true;
        }else{
            return false;
        }
    }
}

bool areAnagramUsingSort(string str1, string str2) {
    //get lengths of both strings
    int l1 = str1.length();
    int l2 = str2.length();
    if(l1 != l2){
        return false;
    }

    sort(str1.begin(), str2.end());
    sort(str2.begin(), str2.end());

    for (int i =0; i < l1; i++) {
        if(str1[i] != str2[i])
            return false;
    }
    return true;
}

bool anagramUsingOneMap(string str1, string str2){
    int s1 = str1.length();
    int s2 = str2.length();
    map<char, int> map;

    if(s1 != s2){
        return false;
    }else{

        for(int i=0; i<s1; i++){

            if(map.find(str1[i]) != map.end()){
                int occurance = map[str1[i]];
                map[str1[i]] = occurance + 1; 

            }else{
                map[str1[i]] = 1;
            }
        }

        for(int i=0;i<s1;i++){
            if(map.find(str2[i]) != map.end()){
                int occurance = map[str2[i]];
                map[str2[i]] = occurance - 1; 

                int val = map[str2[i]];
                if(val == 0) {
                    map.erase(str2[i]);
                }

            }else{
                return false;
            }
        }

    }
    return map.size() == 0;
}

bool isAnagramAuto(string s1, string s2) {
    unordered_map<char, int> m1, m2;

    for(auto i:s1){
        m1[i]++;
    }

    for(auto i:s2){
        m2[i]++;
    }
    return m1==m2;
}


#define TOTAL_CHARS 256
bool bruteForceAnagrams(string str1, string str2){
    int count[TOTAL_CHARS] = {0}; //initializes an array of 256 ints with 0s.
    int i;

    //anagram - nagaram
    // str1[i] && str2[i] = checks if there's some value in both.
    for(i=0; str1[i] && str2[i]; i++){
        count[str1[i]]++;
        //cout << count[str1[i]] << endl; // to debug / understand
        count[str2[i]]--;
        //cout << count[str2[i]] << endl;  // to debug/understand
    }

    if(str1[i] || str2[i]){
        return false;
    }

    for(i = 0; i< TOTAL_CHARS; i++){
        if(count[i])  //This will check based on 0 or 1. 1 being true, 0 being false, so if there's 1, it will execute to return false.
            return false;
    }
    return true;
}

/*
Testcase strings..

"anagram"
"nagaram"
"garden"
"danger"
"salesman"
"nameless"
"salesmen"
"nameless"
"car"
"rat"
"car"
"car"
*/

int main(){

    string str1;
    string str2; 

    std::cout << "Enter first string!: "<< endl;
    std::cin >> str1;

    std::cout << "Enter seconnd string : " <<endl ;
    std::cin >> str2;

    if(bruteForceAnagrams(str1, str2)){
        cout << "Anagrams..." <<endl;
    }else{
        cout << "Not Anagrams..." << endl;
    }
    
    
    //isAnagram(str1, str2);  //with print statement
    //printHashMaps(mapStr1, mapStr2);  //if you want to print hashMap
    
    return 0;
}