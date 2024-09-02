
#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next;
};

class ListNode{
    public:
        Node *head;
        int length = 0;

        ListNode(){
            head = nullptr;
        }   

        int getLength(){
            return length;
        }

        void appendNode(int value){
            Node *n = new Node(); // whenever you are in a function, it goes on stack, thus need to create a heap allocated object
            n->val = value;
            n->next = nullptr;

            if(head != nullptr) {
                Node *temp = head;                 
                while (temp->next) 
                {
                    temp = temp->next;
                }
                temp->next = n;

            }else{
                head = n;
            }
            length++;
        }

        void printNode(){
            Node *temp = head;
            cout << endl;
            while(temp){
                cout << temp->val;
                if(temp->next) cout << ",";
                temp = temp->next;
            }
        }

        void reverseList(){
            Node *temp = head;
            Node *before = nullptr;
            Node *after = temp;

            while(temp!=nullptr){
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;

            }
            delete[] temp;
            head = before;
        }

        void cleanMemory(){
            Node *current = head;
            Node *next = nullptr;
            while(current){
                next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
            length = 0;
        }
};

void listFromUser(ListNode* head){
    cout << "Append nodes add a num from 1-1000" << endl;
    int input = 0;
    cin >> input;
    while (input>0 && input < 1000)
    {
        head->appendNode(input);
        cin >> input;
    }
}
int main(){
    ListNode *head = new ListNode(); 

    //adding 1.. 10 values in linkedlist.
    for (int i = 0; i < 10; i++){
        head->appendNode(i + 1);
    }

    cout << "printing...";
    head->printNode();

    head->reverseList();

    cout << endl << endl << "Reverse Nodes-> ";
    head->printNode();

    cout << endl << endl;
    cout << "length of linkedlist-> "  << head->getLength();

    head->cleanMemory();
}
