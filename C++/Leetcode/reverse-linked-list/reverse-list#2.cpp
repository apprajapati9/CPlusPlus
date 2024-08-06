

#include <iostream>

using namespace std;

class Node {
    public:
        int val;
        Node *next;

        Node(int value){
            this->val = value;
            next = nullptr;
        }

        ~Node(){

        }
};

class LinkedList{

    private:
    //Because outsider shouldn't be able to change these, even by mistake.
        Node *head;
        Node *tail;
        int length;

    public:
        
    
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    LinkedList(int value){
        Node *node = new Node(value);

        head = node;
        tail = node;
        length += 1;
    }

    ~LinkedList(){
        Node *temp = head;
        while(head){
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void getHead(){
        int value = head ? head->val : 0; //0 means NULL
        cout << "Head-> " << value << endl;
    }

    void getTail(){
        int value = tail ? tail->val : 0; //0 means NULL
        cout << "tail-> " << value << endl;
    }

    void getSize(){
        cout << "Size-> " << length << endl;
    }

    void prependNode(int value){
        Node *newNode = new Node(value);

        if(length == 0){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void appendNode(int value) {

        Node *newNode = new Node(value);
        
        //Below steps are unnecessary when you have node(value) constructor.
        // newNode->val = value;
        // newNode->next = nullptr;

        if(length == 0){
            head = newNode;
            tail = newNode;
            length++;
        }else{
            Node *temp = head;
            while(temp->next){
                temp = temp->next;
            }
            //got last
            temp->next = newNode;

            tail = newNode;
            length++; // don't forget to increase size; it will be useful when you have to iterate through nodes.

            // cout << "head " << head->val << endl;
            // cout << "tail updated " << tail->val << endl;
        }
    }

    void printLinkedList(){
        Node *temp = head;
        if(temp == nullptr)
            cout << "List is empty!";
        while(temp){
            cout << temp->val << endl;
            temp = temp->next;
        }

        cout << "Size is-> " << length << endl;
    }

    void deleteLastUsingDoublePointer(){
        if(length == 0)
            return;

        if(length == 1){ // edge case when length is 1 then pre n temp both will point to the same
            head = nullptr;
            tail = nullptr;
        }else{
            Node *temp = head;
            Node *pre = head;

            while(temp->next) {
                pre = temp; //head, head-next 
                temp = temp->next;  //head->next, head-next-next 
            }
            tail = pre;
            tail->next = nullptr;

            length--;
            delete temp;
        }
    } 

    void deleteLast(){

        if(length == 0)
            return;

        if(length == 1) {
            head = nullptr;
            tail = nullptr;
        }else{

            Node *temp = head;
            int counter = length - 1;
            while(counter > 1){
                temp = temp->next;
                counter--;
            }
            temp->next = nullptr;
            tail = temp; 
        }

        length--;
    }

    void deleteFirst()
    { // you must store that head in order to properly delete by delete temp;

        if(length == 0)
            return;

        Node *temp = head; // storing so when head moves to the next one, you can delete temp node which is FIRST
        if(length == 1) {
            head = nullptr;
            tail = nullptr;
        }else{
            head = head->next;
        }
        delete temp;
        length--;
    }

    Node* getNode(int index){
        if(index < 0 || index >= length){
            return nullptr;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }

        return temp;
    }

    Node* reverseLinkedList(){
        Node *node = new Node(1);
        if(length == 0 || length == 1) {
            return nullptr;
        }else{

            for (int i = length; i > 0; i--){
                Node *temp = head;
                for (int j = 0; j < i; j++) {
                    temp = temp->next;
                }


                if(node == nullptr){
                    node = temp;
                    node->next = nullptr;
                }else{
                    Node *here = node; 
                    while(here){
                        here = here->next;
                    }
                    here = temp;

                }
            }
        }
        return node;
    }

    void reverseLinkedListUsingPointers(){

        if(length == 1) {
            return;
        }
        Node *temp = head;

        head = tail;
        tail = temp;

        Node *before = nullptr;
        Node *after = temp;

        for (int i = 0; i < length; i++){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }

          
    }

};

int main(){

    LinkedList list;

    // list.getSize();
    // list.getHead();
    // list.getTail();
    //  //= LinkedList();

    list.appendNode(1);
    list.appendNode(2);
    list.appendNode(3);

    list.appendNode(4);
    list.appendNode(5);
    list.appendNode(6);

    list.printLinkedList();

    cout << "deleting last..." << endl;

    list.deleteLastUsingDoublePointer();

    list.printLinkedList();

    cout << "prepending..." << endl;

    list.prependNode(10);
    list.printLinkedList();

    cout << "deleting first..." << endl;

    list.deleteFirst();
    list.printLinkedList();

    int index = 1;
    cout << "getting a specific index at ->" << index << endl;

    int value = list.getNode(index) ? list.getNode(index)->val : 0; // 0 means nullptr
    cout << "The value at index->" << index << "is-> " << value << endl;

    cout << "Reversing..." << endl;
    
    list.reverseLinkedListUsingPointers();

    list.printLinkedList();

    cout << "Reversing again.. to get back original" << endl;

    list.reverseLinkedListUsingPointers();
    list.printLinkedList();

    cout << "------------------------ Stats ----------------/// " << endl;
    list.getSize();
    list.getHead();
    list.getTail();
    return 0;
}