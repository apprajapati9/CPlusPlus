#include<iostream>
#include "transaction.h"

using namespace std;

void enter(struct Transaction* tr) {

	cout << "Enter the account number : ";
	cin >> tr->acct;
	cout << "Enter the account Type ( d - debit, c - credit ) : " ;
	cin >> tr->type;
	cout << "Enter the account amount : ";
	cin >> tr->amount;

}

void display(struct Transaction* tr){
	cout << "Account " << tr->acct;
	cout << ((tr->type == 'd') ? " Debit $" : " Credit $") << tr->amount;
	cout << endl;
}
