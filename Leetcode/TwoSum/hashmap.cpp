#include <iostream>

// must include map 
#include <map>

//using iterator to go through all mapvalues
#include <iterator>

using namespace std;

int main()    {

    //empty map container 
    map<int, int> hashmap;
    map<string, int> hashmap2;

    //initialize iterator on map
    map<int, int>::iterator myIterator;


    hashmap.insert(pair<int, int>(1, 10));
    // access with a particular key hashmap[7];
    hashmap2.insert(pair<string, int>("ajay",9));

    for(myIterator = hashmap.begin(); myIterator != hashmap.end(); ++myIterator){
        cout << myIterator->first << "->" << myIterator->second << endl;
    }

    cout << hashmap[1] << endl; // print value of 1-> value, 1 act as KEY , value would be 10
    cout << hashmap["ajay"] << endl;

    //cout << hashmap.find()

 

    return 0;
}