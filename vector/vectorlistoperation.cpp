#include <vector>
#include <iostream> 

using namespace std;
int main(){

    vector<int> q;
    q.push_back(10);
    q.push_back(11);
    q.push_back(12);

    vector<int> v;
    for(int i=0; i<5; ++i){
        v.push_back(i);
    } //v contains 0 1 2 3 4 

    vector<int>::iterator it = v.begin() + 1; // 0+1= 1 

    it = v.insert(it, 33); // v = 0 33 1 2 3 4   insert (insert at index, value) , other values stay at same order

    v.insert(it, q.begin(), q.end()); // insert ( index, range from, range to) -- 0 10 11 12 33 1 2 3 4 

    it = v.begin() + 3;

    //reside ( iterator, range from ( inclusive), range to)
    v.insert(it, 3, -1); // 0 10 11 -1 -1 -1 12 33 1 2 3 4  

    it = v.begin() + 4; // 4
    v.erase(it);  // erase it means erase that position -- 0 10 11 -1 -1 12 33 1 2 3 4 

    it = v.begin() + 1; // 1
    v.erase(it, it + 4); //  0 12 33 1 2 3 4 

    v.clear();

    return 0;
}