
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
            //cout << "last t-> " << t->val << endl;
            
            appendNode(newList, t->val);
            }

            ListNode *deleteFirst = newList;
            if(newList->next){
                deleteFirst = newList->next;
                delete newList;
            }

            return deleteFirst;
        }
};


int main(){

    // ListNode first = ListNode();
    // ListNode *head = &first;   //This works too if you want to add and remove notes using first. Difference is that 
                                    // if you use head pointer then head->MethodName(), for first its first.methodName()
    ListNode *head = new ListNode(1); // address of first is stored in head.

   // cout << sizeof(*head) << " " << sizeof(first) << " ";
    //out << sizeof(int) << endl;

    cout << "Append nodes add a num from 1-1000" << endl;
    int input = 0;
    cin >> input;
    while (input>0 && input < 1000)
    {
        head->appendNode(head, input);
        cin >> input;
    }
    

    // head->appendNode(head, 9);
    // head->appendNode(head, 19);
    // head->appendNode(head, 190);
    // head->appendNode(head, 199);
    // head->appendNode(head, 1990);
    // head->appendNode(head, 19900);
    // head->appendNode(head, 1990000);
    
 
    cout << "printing...";
    head->printNode(head);

    head = head->reverseList(head);

    cout << endl << "Reverse Nodes-> ";
    head->printNode(head);

    delete head;   
}
