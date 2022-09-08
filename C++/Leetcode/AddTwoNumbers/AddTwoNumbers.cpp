#include "NodeIml.cpp"

// using namespace std;

void printSumNodes(vector<int> v1, vector<int> v2){
    Node* vHead1 = NULL;
    Node* vHead2 = NULL;

    vHead1 = vHead1->VectorToNode(v1);
    vHead2 = vHead2->VectorToNode(v2);

    cout<< "Original List " << endl;
    vHead1->printNode(vHead1);
    vHead2->printNode(vHead2);

    vHead1 = vHead1->addTwoNumbers(vHead1, vHead2);

    // cout<<"main-print"<<endl;
    vHead1->printNode(vHead1);
    cout<< " -------- End of Result -----------" << endl;
}

int main(){
    //test cases
    vector<int> node1 = {2,4,9};
    vector<int> node2 = {5,6,4,9};  //--> correct output: [7,0,4,0,1]

    vector<int> v1 = {9,9,9,9,9,9,9};
    vector<int> v2 = {9,9,9,9};

    vector<int> v3 = {2,4,3};
    vector<int> v4 = {5,6,4};

    vector<int> v5 = {0};
    vector<int> v6 = {0};

    printSumNodes(v1, v2);
    printSumNodes(node1, node2);
    printSumNodes(v3,v4);
    printSumNodes(v5,v6);
    return 0;
}

