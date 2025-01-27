#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
};

class LinkedList
{
public:
    Node* head;
    int length;

    LinkedList()
    {
        head = nullptr;
        length = 0;
    }

    LinkedList(int val)
    {
        Node* node = new Node();
        node->val = val;
        node->next = nullptr;
        head = node;
    }

    int getListSize()
    {
        return length;
    }

    Node* getLastNode()
    {
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        return temp;
    }

    void appendNode(int value)
    {
        Node* n = new Node();
        n->val = value;
        n->next = nullptr;

        if(head == nullptr) {
            head = n;
        } else {
            Node* last = getLastNode();
            last->next = n;
        }
        length++;
    }

    void printList()
    {
        Node* temp = head;
        while(temp) {
            cout << temp->val << ",";
            temp = temp->next;
        }
        cout << endl;
    }

    void printList(Node* currHead)
    {
        Node*temp = currHead;
        while(temp) {
            cout << temp->val << ",";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* reverseLinkedList(Node* head)
    {
        Node* temp = head;

        Node* before = nullptr;
        Node* after = nullptr;

        while(temp) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }

        return before;
    }

    void reorderLinkedList()
    {
        Node* temp = head;

        //copy the list
        LinkedList *list = new LinkedList();
        int size = 0;

        while(temp) {
            list->appendNode(temp->val);
            temp = temp->next;
            size++;
        }

        cout << "printing copied list" << endl;
        printList(list->head);

        // reverse.
        list->head = reverseLinkedList(list->head);
        printList(list->head);

        //weave..
        int current = 0;
        temp = head;
        Node *r = list->head;

        LinkedList* ans = new LinkedList();

        while(current < size/2) {

            ans->appendNode(temp->val);
            ans->appendNode(r->val);
            temp = temp->next;
            r = r->next;
            current++;
        }
        printList(ans->head);

    }
};

int main()
{
    LinkedList* list = new LinkedList();
    list->appendNode(2);
    list->appendNode(4);
    list->appendNode(6);
    list->appendNode(8);

    list->printList();

//    cout << list->getListSize() << endl;

    list->reorderLinkedList();
    return 0;
}
