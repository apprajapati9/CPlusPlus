#include <iostream>

using namespace std;

#include "main.h"
#include "Transaction.h"

int main(){

    double balance = 0.0;
    Transaction tr;

    for(int i =0 ; i < NO_TRANSACTIONS; i++){
        enter(&tr);
        display(&tr);
        add(&balance, &tr);
    }

    cout << "Balance :" << balance << endl;
}

// void add(double* bal, const Transaction *tr){
//     bal =  bal +  tr->amount;
// }