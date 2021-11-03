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
    // 1 2 3

    head->addNode(&head, 45);
    head->printList(head);
    // 45 1 2 3

    head->insertAfterNode(second, 9);
    head->printList(head);
    // 45 1 2 9 3

    head->insertNodeAtEnd(&head, 40);
    head->printList(head);
    // 45 1 2 9 3 40
   
    head->deleteNode(&head,9);
    head->printList(head);
    // 45 1 2 3 40

    head->addNode(&head, 50);
    head->printList(head);
    // 50 45 1 2 3 40

    head->insertNodeAtEnd(&head, 30);
    head->printList(head);
    // 50 45 1 2 3 40 30

    head->deleteNode(&head,2);
    head->printList(head);
    // 50 45 1 3 40 30

    head->deleteLastNode(&head);
    head->printList(head);
    // 50 45 1 3 40 

    return 0;
}