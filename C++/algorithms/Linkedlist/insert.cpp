#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next_node;
};
/*
    Insert a node after specific node. 
*/
void insertAfterNode(Node* prev_node, int new_data){

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
    new_node->next_node = prev_node->next_node;
    
    //after 3, we are adding 9, so 3->9, so prev_node(3)->next is 9.
    prev_node->next_node = new_node;
}
/*also known as Append node.
  in this case you have to go through all nodes from HEAD, 
  o(n) times to get to the end and then append that node to the last one.
*/
void insertNodeAtEnd(Node** head_reference, int new_data){
    //New node to append at last
    Node *new_node = new Node();

    //clone of head_ref to assign n save last node's pointer
    Node *last_node = *head_reference;

    // 1-2-3-4->NULL , so 4th is last node, 
    //if we add new node 10, then last 10->NULL,
    // so we assign 10 and assign next pointer to NULL
    new_node->data = new_data;
    new_node->next_node = NULL; 

    //if first node is null, then make it the head
    // if 10th is first node, then it will do, 10->NULL. 
    if(*head_reference == NULL){
        *head_reference = new_node;
        return;
    }

    //traverse till last node, when next_node pointer is null, means its last
    while(last_node->next_node != NULL){
         last_node = last_node->next_node;
    }

    //so we got 1->2->3->4->NULL, so 4th was last_node ie. 4->NULL
    // New node is 10->NULL
    //so assigning last node's next as new node, 
    //this will turn 4->NULL, into 4->10.. and 10th next node is empty
    //making it the last node. 
    last_node->next_node = new_node;

}

void printList(Node* n){
    while (n != NULL){
        cout << n->data << " ";
        n = n->next_node;
    }
    cout<<endl;
}

int main(){
    Node * head = new Node();
    Node * second = new Node();
    Node *third = new Node();

    head->data =1;
    head->next_node = second;

    second->data=2;
    second->next_node = third;
    
    third->data=3;
    third->next_node = NULL;

    insertAfterNode(second, 9);
    printList(head);

    insertNodeAtEnd(&head, 11);
    printList(head);
}
