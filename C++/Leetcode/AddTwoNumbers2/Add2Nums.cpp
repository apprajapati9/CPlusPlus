#include "ListNode.h"
#include <vector>

using namespace std;
/*
    NOTE : This implementation of AddTwonumbers is same, but here I am trying to implement
    same methods that were shown on Leetcode to try out my own implementation of full code.

    On Leetcode, you will only be executing a method, but here, you can see all moving parts of it. 

    Folders : AddTwoNumbers and AddTwoNumbers2 - both are same. First one is my own implementation 
    and the latter is my own implementation but methods are as same as shown on Leetcode website.
*/
int main(){

    
    vector<int> list1 = {2,4,9};
    vector<int> list2 = {5,6,4,9}; // --> correct output: [7,0,4,0,1]

    ListNode* l1 = new ListNode();
    l1 = l1->VectorToNode(list1);

    ListNode* l2= new ListNode();
    l2 = l2->VectorToNode(list2);

    l1->printlist(l1);
    l2->printlist(l2);

    ListNode* sum = new ListNode();
    sum = sum->AddTwoNumbers(l1, l2);
    sum->printlist(sum);

}

// Execute this method if you want digits input from user
// It is efficient to use hard coded value to test faster for test cases of this example.
void inputFromUser(){
    int sizeOfFirstVector = 0;
    int sizeOfSecondVector = 0; 

    vector<int> list1;
    vector<int> list2;

    cout << "Enter how many digits wanted in first number?" << endl;
    cin >> sizeOfFirstVector;
    cout << endl;

    cout << "Enter how many digits wanted in second number?" << endl;
    cin >> sizeOfSecondVector;
    cout << endl;

    cout << "Enter " << sizeOfFirstVector << " numbers, each with pressing return" << endl;
    int input;
    for(int i=0; i< sizeOfFirstVector; i++){
        cin >> input;
        list1.push_back(input);
    }

    cout << endl << "Enter " << sizeOfSecondVector << " numbers, each with pressing return" << endl;
    for(int i=0; i<sizeOfSecondVector; i++){
        cin >> input;
        list2.push_back(input);
    }
}