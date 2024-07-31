
#include <iostream>

using namespace std;

// struct Node{
//     int val;
//     Node *next;
// };

class ListNode{
    public:
        int val;
        ListNode *next;

        ListNode(){
            val = 0;
            next = nullptr;
        }   

        ListNode(int value){
            val = value;
            next = nullptr;
        }

        void appendNode(ListNode* head, int value){
            ListNode *n = new ListNode(value); // whenever you are in a function, it goes on stack, thus need to create a heap allocated object
            ListNode *temp = head; // duplicating head

            //This case is necessary because initial node has next pointing to nullptr
            if(!temp->next){
                //if null
                temp->next = n;
                return;
            }
            while (temp->next) //9 
            {
                //cout << temp->val << endl; //0 
                temp = temp->next; // 9
            }
        
            temp->next = n;
        }

        void printNode(ListNode *head){
            ListNode *temp = head;
            cout << endl;
            //cout << "printing fun temp head " << temp->val << endl;
            while(temp){
                cout << temp->val << "," ;
                temp = temp->next;
            }
        }

        ListNode* reverseList(ListNode *head){
            ListNode *temp = head; 

            //find last
            int size = 0;
            while(temp->next){
                size++;
                temp = temp->next;
            }
            //cout << "size of list " << size << endl;
            //cout << endl << "last-> " << temp->val << endl;
            ListNode *newList = new ListNode();
            
            for (int i = size; i >= 0; i--) {
            ListNode *t = head; 
            for (int j = 0; j < i   ; j++){
                t = t->next;
            }
            // cout << "last t-> " << t->val << endl;
            appendNode(newList, t->val);
            }

            return newList;
        }
};


int main(){

    ListNode first = ListNode();
    ListNode *head = &first; // address of first is stored in head.

    first.appendNode(head, 9);
    first.appendNode(head, 19);
    first.appendNode(head, 190);
    first.appendNode(head, 199);
    first.appendNode(head, 1990);
    first.appendNode(head, 19900);
    first.appendNode(head, 1990000);
    
 
    cout << "printing...//" << endl;
    first.printNode(head);

    head = first.reverseList(head);

    first.printNode(head);

    delete head;   
}
