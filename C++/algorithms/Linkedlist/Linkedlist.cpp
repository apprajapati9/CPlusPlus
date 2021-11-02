#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

void printList(Node* n){
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout<<endl;
}
/*
    Note: New node is always added before the head of a given Linked list.
    So 1->2->3->4, if we add 5, then it would be 5->1->2->3->4

    and newly added node becomes the new head of the new linked list. 
*/
void addNode(Node** head_reference, int new_data){
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_reference);

    (*head_reference) = new_node;
    /*
    In push the main important thing is to change head because
    head has reference to all the next nodes
    so once you push a node, simply make a new node's next element to be the
    first (head)'s node. for example...
    1-2-3, now adding 4 would
    4-> (next) -> 1
    1(next) -> has already ref of 2 and 3 .. so on

    so 4 (next) -> 1
    change node's head to 4, 
    so it would print as 4->1->2->3
    */
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    //allocate three nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
    /*
    Three blocks have been initialized dynamically. We have pointers to these 
    three blocks as head, second, and third. 
    */

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    cout<< "Original List " << endl;
    printList(head);

    //adds a node at the start, also known as push method.
    addNode(&head, 4);
    cout << "Push() = 4" << endl;
    printList(head);

    addNode(&head, 5);
    cout<< "Push() = 5" << endl;
    printList(head);

    return 0;
}