#include "NodeIml.cpp"

// using namespace std;

int main(){
    vector<int> node1 = {2,4,3};
    vector<int> node2 = {5,6,4};

    Node* vHead1 = NULL;
    Node* vHead2 = NULL;

    vHead1 = vHead1->VectorToNode(node1);
    vHead2 = vHead2->VectorToNode(node2);

    cout<< "Original List " << endl;
    vHead1->printNode(vHead1);
    vHead2->printNode(vHead2);

    vHead1 = vHead1->addTwoNumbers(vHead1, vHead2);

    // cout<<"main-print"<<endl;
    vHead1->printNode(vHead1);
    
    return 0;
}