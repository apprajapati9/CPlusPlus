#include <iostream>

/*
Solution for Merge Two Sorted lists
https://neetcode.io/problems/merge-two-sorted-linked-lists

Important thing to remember :
    In this solution, I have internal mechanism of appending node. While on leetcode, you have to manually assign next node.

    temp = temp->next;

    in this solution, I have

    temp->appendNode(int value) it will automatically check head and iterate through last element and append a new created node.
    
*/

using namespace std;

class Node{
    public: 
        int val;
        Node *next;
};


class LinkedList{

    public:
        Node *head;
        Node *tail;
        int length;

        LinkedList() {
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        void appendNode(int value){
            Node *n = new Node(); // whenever you are in a function, it goes on stack, thus need to create a heap allocated object
            n->val = value;
            n->next = nullptr;

            Node *last = getLastNode();
            if(last != nullptr){
                last->next = n;
            }else{
                head = n;
            }

            length++;
        }

	void attachNodes(Node* node){
	    getLastNode()->next = node;
	}

        void printLinkedList(){
            Node *temp = head;
            while(temp) {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        bool isNodeNotNull(){
            return head != nullptr;
        }

	

        Node* getLastNode() {
            if(head != nullptr){
                Node *temp = head;
                while(temp->next){
                    temp = temp->next;
                }
                return temp;
            }else{
                return nullptr;
            }
        }
};

LinkedList* getMergedList(LinkedList* list1, LinkedList* list2){

    LinkedList *ans = new LinkedList();


    // list1 = head-> 1 - 2 - 4
    // list2 = head-> 1 - 3 - 5
    Node *t1 = nullptr;
    Node *t2 = nullptr;
    
    if(list1->isNodeNotNull()){
        t1 = list1->head;
    }
    if(list2->isNodeNotNull()){
        t2 = list2->head; 
    }

    if(t1 == nullptr && t2 != nullptr){
        ans->head = t2;
        return ans;
    }
    
    if(t2 == nullptr && t1 != nullptr){
        ans->head = t1;
        return ans;
    }

    //cout << "printing test values..." << endl;
    //cout << "t1 " << t1->val << " t2 " << t2->val <<endl;
    
    // At this point, both t1 and t2 are not null

    // 1 -> 2 - > 4
    // 1 -> 3 -> 5
    // in this case 1   and 2
    while(t1 || t2) {

	if(t1 && t2) {
	    
	    if(t1->val == t2->val){
		ans->appendNode(t1->val);
		ans->appendNode(t2->val); 

		if(t1->next){
		    t1 = t1->next;
		}else{
		    t1 = nullptr;
		}
		if(t2->next){
		    t2 = t2->next;
		}else{
		    t2 = nullptr;
		}
	    }
	    if(t1->val < t2->val){
		ans->appendNode(t1->val);
		
		if(t1->next){
		    t1 = t1->next;
		}else{
		    t1 = nullptr;
		}
		
	    }
	    if(t1->val > t2->val){
		ans->appendNode(t2->val);
		if(t2->next){
		    t2 = t2->next;
		}else{
		    t2 = nullptr;
		}
	    }
	}

	if(t1){
	    while(t1){
		ans->appendNode(t1->val);
		if(t1->next){
		    t1 = t1->next;
		}else{
		    t1= nullptr;
		}
	    }
	}

	if(t2){
	    while(t2){
		ans->appendNode(t2->val);
		if(t2->next){
		    t2 = t2->next;
		}else{
		    t2 = nullptr;
		}
	    }
	}
    }    
    
    return ans;
}

// refactored
LinkedList* mergedList(Node* node1, Node* node2){

    LinkedList* node = new LinkedList();


    while(node1 && node2){
	if(node1->val < node2->val){
	    // It is important to rememeber that no need to manually manipulate node's value.
	    // Doing node->next = node1, will save the entire node, thus no need of doing node->val = node
	    node->appendNode(node1->val);
	    node1 = node1->next;
	}else{
	    node->appendNode(node2->val);
	    node2 = node2->next;
	}
    }

    if(node1 == nullptr){
	node->attachNodes(node2);
    }
    if(node2 == nullptr){
	node->attachNodes(node1);
    }
    return node;
}

int main(){


    //Test case : [-9,3] and [5,7] = [-9,3,5,7]
    LinkedList *list1 = new LinkedList();

    list1->appendNode(1);
    list1->appendNode(2);	
    list1->appendNode(4);

       
    LinkedList *list2 = new LinkedList();
    list2->appendNode(1);
    list2->appendNode(3);

    list2->appendNode(5);	

    
    LinkedList *m = getMergedList(list1, list2);
    cout << "Using getMergedList() method" << endl;
    m->printLinkedList();

    LinkedList *m2 = mergedList(list1->head, list2->head);
    cout << "Using mergedList() method" << endl;
    m2->printLinkedList();
}
