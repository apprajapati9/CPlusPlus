#include<iostream>
#include<vector>

using namespace std;

class X {

    public :
        X() : val_(0){

        }
        X(int val) : val_(val){

        }

        int get() {
            return val_;
        }

        void set(int val){
            val_ = val;
        }

        void print(){
            cout << val_  << endl;
        }

    private :
        int val_;
};

void printVector(vector<X> mVector){
    for(int i= 0; i < mVector.size(); i++){
        mVector[i].print();
    }
}

int main(){

    //Version 1. 
     vector<X> ax;
    // ax.resize(10);

    // for(int i=0; i < 10 ; i++){
    //     ax[i].set(i);
    // }

    //Version 2. 
    ax.reserve(10); // make room for 10 elements
    for(int i = 0; i < 10 ; i++){
        ax.push_back(X(i)); // with second constructor 
    }

    printVector(ax);


    return 0;
}

/*
Note that both insert() and erase() are not very efficient for vectors. 
They are expected to perform in amortized linear time, O(n)+. 
If your application often uses insertion and erasure, vector probably isn't the best choice of a container for you.
*/
