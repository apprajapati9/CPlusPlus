#include<iostream>

using namespace std;

void my_solution(){
    unsigned int first = 1;
    unsigned int second = 2;
    unsigned int sum = 0;

    for (int i = 0; i < 20; i++){
        if( i == 1) {
            cout << i << " ";
        }

        if(i == 2) {
            cout << i << " ";
        }
        if(i > 2 && first >= 1) {
            sum = first + second;
            cout << sum << " ";

            first = second;
            second = sum;
            sum = 0;
        }
    }
}

//prints fibo series until the number input by user.
void print_fibo(){
    unsigned int f1 = 0, f2 = 1, nextTerm = 0, n;

    cout << "Enter a positive number: ";
    cin >> n;

    // displays the first two terms which is always 0 and 1
    cout << "Fibonacci Series: " << f1 << ", " << f2 << ", ";

    nextTerm = f1 + f2;

    while(nextTerm <= n) {
        cout << nextTerm << ", ";
        f1 = f2;
        f2 = nextTerm;
        nextTerm = f1 + f2;
    }
}

unsigned long fib(unsigned long n){
        if(n <=1){
            return n;
        }
        else{
            return fib(n - 1) + fib(n - 2);  //fn = Fn-1 + Fn-2 where F represents Function call.
        }
}

void using_equation(){
    for (int n = 0; n < 20; n++)
    {
        cout << fib(n) << " ";
    }
}

int main(){

    //print_fibo();
    using_equation();
    return 0;
}


























// int num = 0;

//     unsigned long s1 = 0;
//     unsigned long s2 = 1;
//     unsigned long nextS = 0;

//     while(num < 100){

//         if( num > 1) {
//             nextS = s1 + s2;
//             s1 = s2;
//             s2 = nextS;
//             cout << nextS << " ";
//         }else{
//             cout << num << " ";

//         }
//         num++;
//     }