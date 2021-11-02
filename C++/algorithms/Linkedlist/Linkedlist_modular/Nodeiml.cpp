#include "Node.h"
#include <cstddef>
#include <iostream>

using namespace std;

void Node::printList(Node *n){
    while (n != NULL){
        std::cout << n->data << " ";
        n = n->next;
    }
    std::cout<<endl;
}


/*
    Note: New node is always added before the head of a given Linked list.
    So 1->2->3->4, if we add 5, then it would be 5->1->2->3->4

    and newly added node becomes the new head of the new linked list. 
*/
void Node::addNode(Node** head_reference, int new_data){
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



/*
    Insert a node after specific node. 
*/
void Node::insertAfterNode(Node* prev_node, int new_data){

    //Check if the given prev node is null, if null, show an error message
    if(prev_node == NULL){
        cout << "The given previous node must not be NULL";
        return;
    }

    //New node created
    Node *new_node = new Node();
    // new node's data assigned
    new_node->data = new_data;

    //new_node's next one would be previous one's next because
    // we are adding a node after previous one mentioned.
    // ie 1,2,3,4 - adding 9, prev is 3, so 3's next is 4..
    // so new node 9's next would be 4
    //thus 1->2->3->9->4 
    //so we are 3 (prev_node)'s next one is current new node (9)s next node
    new_node->next = prev_node->next;
    
    //after 3, we are adding 9, so 3->9, so prev_node(3)->next is 9.
    prev_node->next = new_node;
}


/*also known as Append node.
  in this case you have to go through all nodes from HEAD, 
  o(n) times to get to the end and then append that node to the last one.
*/
void Node::insertNodeAtEnd(Node** head_reference, int new_data){
    //New node to append at last
    Node *new_node = new Node();

    //clone of head_ref to assign n save last node's pointer
    Node *last_node = *head_reference;

    // 1-2-3-4->NULL , so 4th is last node, 
    //if we add new node 10, then last 10->NULL,
    // so we assign 10 and assign next pointer to NULL
    new_node->data = new_data;
    new_node->next = NULL; 

    //if first node is null, then make it the head
    // if 10th is first node, then it will do, 10->NULL. 
    if(*head_reference == NULL){
        *head_reference = new_node;
        return;
    }

    //traverse till last node, when next_node pointer is null, means its last
    while(last_node->next != NULL){
         last_node = last_node->next;
    }

    //so we got 1->2->3->4->NULL, so 4th was last_node ie. 4->NULL
    // New node is 10->NULL
    //so assigning last node's next as new node, 
    //this will turn 4->NULL, into 4->10.. and 10th next node is empty
    //making it the last node. 
    last_node->next = new_node;

}