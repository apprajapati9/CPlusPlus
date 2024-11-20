#include <iostream>

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

    
    while(t1 || t2){
        if(t1->val == t2->val){
            ans->appendNode(t1->val);
            ans->appendNode(t2->val);

            t1 = t1->next;
            t2 = t2->next;

        }

        if(t1->val < t2->val){
            ans->appendNode(t1->val);
            t1 = t1->next;

        }

        if(t2->val < t1->val) {
            ans->appendNode(t2->val);
            t2 = t2->next;
	    

        }
    }
    
    return ans;
}

int main(){
    LinkedList *list1 = new LinkedList();

    list1->appendNode(1);
    list1->appendNode(2);
    list1->appendNode(4);
    
    LinkedList *list2 = new LinkedList();

    list2->appendNode(1);
    list2->appendNode(3);
    list2->appendNode(5);

    list1->printLinkedList();
    list2->printLinkedList();


    //Test empty lists
    LinkedList *empty1 = new LinkedList();
    cout << "priting test.";
    empty1->appendNode(1);
    LinkedList *empty2 = new LinkedList();
    empty2->appendNode(2);

    LinkedList *m = getMergedList(empty1, empty2);
    m->printLinkedList();
}
