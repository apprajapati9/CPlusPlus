#include "NodeIml.cpp"

// using namespace std;

int main(){
    // vector<int> node1 = {2,4,3};
    // vector<int> node2 = {5,6,4};


    // Node* vHead1 = NULL;
    // Node* vHead2 = NULL;

    // head1->VectorToNode(head1, node1);
    // head2->VectorToNode(head2, node2);

///*
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    //allocate three nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
    
    head->data = 2;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    Node* head1 = NULL;
    Node* second1 = NULL;
    Node* third1 = NULL;

    //allocate three nodes in the heap
    head1 = new Node();
    second1 = new Node();
    third1 = new Node();
    
    head1->data = 5;
    head1->next = second1;

    second1->data = 6;
    second1->next = third1;

    third1->data = 4;
    third1->next = NULL;
//*/
    cout<< "Original List " << endl;
    head->printNode(head);
    head1->printNode(head1);

    head1->addTwoNumbers(head, head1);
    
    return 0;
}