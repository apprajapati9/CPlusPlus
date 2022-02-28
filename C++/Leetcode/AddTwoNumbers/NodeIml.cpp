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

// void Node::insertNode(Node** head){

//     Node *new_node = new Node();
//     Node *last_node = *head;
//     new_node->data = data;
//     new_node->next = NULL;

//     if(*head == NULL){
//         *head = new_node;
//         return;
//     }

//     while(last_node->next != NULL){
//         last_node = last_node->next; 
//     }
//     last_node->next = new_node;
// }


int  Node::addTwoNumbers(Node* n1, Node* n2){

    bool carry = false;
    int sum;
    vector<int> sums;

    Node* head = new Node(); 

    while(n1 != NULL || n2 != NULL){
       
        Node *new_node = new Node();
        int n1data, n2data;
        if(n1 == NULL){
            n1data = 0;
        }else{
            n1data = n1->data;
        }
         if(n2 == NULL){
            n2data = 0;
        }else{
            n2data = n2->data;
        }

        if(carry){
            sum = n1data + n2data + 1;
            carry = false;
            
        }else{
            sum = n1data + n2data;
        }
            
        if(sum/10 >= 1 && n1->next !=NULL && n2->next != NULL){
            carry = true;
            sum = sum%10;
            sums.push_back(sum);
        }else{
            if(carry){
                sums.push_back(sum+1);
                carry = false;
            }else{
                sums.push_back(sum);
            }
            
        }
        n1 = n1->next;
        n2 = n2->next;
        //head->insertNode(&new_node);
    }

    Node* new_node = NULL;
    
    
    for(int i=sums.size()-1; i <= sums.size(); i-- ){
        
        Node* temp_node = new Node();
        Node* last_node = new_node;

        temp_node->data = sums[i];
        temp_node->next = NULL;

        if(new_node == NULL){
            new_node = temp_node;
        }else{
            while( last_node->next != NULL){
                last_node = last_node->next;
            }

            last_node->next = temp_node;
        }
        
        // std::cout << sums[i] << ", ";
        // new_node->data = sum[i];
        // new_node-next = NULL;
    }

    new_node->printNode(new_node);


    // for ( int x : sums){
	// 	std::cout << x << ", ";
	// }

    return 0;
}

// Node* Node::VectorToNode(Node** head, vector<int> &v){
    
//     for(int x: v){
//         Node* new_node = new Node();
//         new_node->data = x;
//         new_node->next = NULL;

//         Node* temp_node = *head;

//         if(*head == NULL){
//             *head = new_node;
//         }else{
//             while(temp_node->next != NULL){
//                 temp_node = temp_node->next;
//             }
//             temp_node->next = new_node;
//         }
//     }
//     return head* ;
// }