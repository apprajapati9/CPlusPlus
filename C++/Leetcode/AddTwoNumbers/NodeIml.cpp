#include <vector>
#include "Node.h"
#include <cstddef> //For constants like NULL. 
#include <iostream>


using namespace std;

void Node::printNode(Node* n){
    std::cout << "[";
    while(n != NULL){
        std::cout<< n->data;
        if(n->next != NULL){
             cout << ",";
        }
        n = n->next;
    }
    std::cout <<"]"<<endl;
}

void Node::printReverse(Node* n){
    
    if(n == NULL){
        return;
    }  
    Node::printReverse(n->next);
    
    cout << n->data;
}

Node*  Node::addTwoNumbers(Node* n1, Node* n2){

    int carry = 0; 
    int sum;
    Node* new_node = NULL;
    vector<int> sums;

    while(n1 != NULL || n2 != NULL || carry == 1){ // carry ==1 condition prevents last digits scenario where 10 is remainder.
        
        int n1data = n1 ? n1->data : 0; // better than n1 == NULL? 0 : val
        int n2data = n2 ? n2->data : 0;

        sum = carry==1 ? n1data + n2data + 1 : n1data + n2data;
        carry = 0;
            
        if(sum/10 >= 1){
            carry = 1;
            sum = sum%10; // remainder

            sums.push_back(sum);
        
        }else{
            sums.push_back(sum);
        }
        //make sure to check non null value otherwise it could cause seg fault.
        if(n1 != NULL) n1 = n1->next;
        if(n2 != NULL) n2 = n2->next;
    }

    for(int i = 0; i< sums.size(); i++){
        
        if(sums[i]/10 >= 1){
            new_node->insert(&new_node, sums[i]/10);
            new_node->insert(&new_node, sums[i]%10);
        }else{
            new_node->insert(&new_node, sums[i]);
        }
    }    
    
    return new_node;
}

Node* Node::VectorToNode(vector<int> &v){
    
    Node *root = NULL;
    for(int x: v){
        Node* new_node = new Node();
        new_node->data = x;
        new_node->next = NULL;

        Node* temp_node = root;

        if(root == NULL){
            root = new_node;
        }else{
            while(temp_node->next != NULL){
                temp_node = temp_node->next;
            }
            temp_node->next = new_node;
        }
    }
    return root ;
}

void Node::insert(Node** head, int data){

    Node* new_node = new Node();
    Node* temp;

    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
    }else{
        temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}