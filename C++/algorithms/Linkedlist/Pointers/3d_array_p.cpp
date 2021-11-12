#include <iostream>

using namespace std;

void multiF(int (*p)[2][2]){
    cout << "here" << endl;
}


int main(){

    int a[3][2][2] ={
        {{100,200},{300,400}}, 
        {{500,600}, {700,800}}, 
        {{900,1000},{1100,1200}}};

    int (*p)[2][2] = a;

    cout << ***(p+1) <<endl; // right to left, inner side. 1000 needs ***, 100 needs *

    cout << *(*(*(a+2))+1) <<endl;

    cout << *(**a+9) <<endl;

    cout << **(*(a+2)+1) << endl; //1100
    cout << *(**a+10) <<endl; //1100

    cout << *(a[0][1]+1) << endl;
    cout << *(a[1]+1) <<endl;

    cout << a << " " << *a << " " << a[0] << " " << &a[0][0] << endl;
    cout << *(a[0][0]+1) <<endl; // 200

    //while passing mutli dimentional , sign args should be like this
    multiF(a);

    return 0;
}