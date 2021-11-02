#include "Nodeiml.cpp"

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
    head->printList(head);

    head->addNode(&head, 45);
    head->printList(head);

    head->insertAfterNode(second, 9);
    head->printList(head);

    head->insertNodeAtEnd(&head, 40);
    head->printList(head);
   
    return 0;
}