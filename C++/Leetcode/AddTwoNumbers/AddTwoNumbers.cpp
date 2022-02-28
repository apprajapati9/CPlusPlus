#include "NodeIml.cpp"

// using namespace std;

int main(){
    vector<int> node1 = {9,9,9};
    vector<int> node2 = {5,6,4};


    Node* vHead1 = NULL;
    Node* vHead2 = NULL;

    vHead1 = vHead1->VectorToNode(node1);
    vHead2 = vHead2->VectorToNode(node2);

/*
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    //allocate three nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
    
    head->data = 9;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 9;
    third->next = NULL;

    Node* head1 = NULL;
    Node* second1 = NULL;
    Node* third1 = NULL;

    //allocate three nodes in the heap
    head1 = new Node();
    second1 = new Node();
    third1 = new Node();
    
    head1->data = 9;
    head1->next = second1;

    second1->data = 9;
    second1->next = third1;

    third1->data = 9;
    third1->next = NULL;

    // cout<< "Original List " << endl;
    // head->printNode(head);
    // head1->printNode(head1);

    // head1->addTwoNumbers(head, head1);
*/
    cout<< "Original List " << endl;
    vHead1->printNode(vHead1);
    vHead2->printNode(vHead2);

   // vHead1->addTwoNumbers(head, head1);
    
    return 0;
}