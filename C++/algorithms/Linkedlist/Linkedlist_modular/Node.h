class Node {
    public:
        int data;
        Node* next;

        void printList(Node* n);
        void addNode(Node **new_node, int new_data);

        void insertAfterNode(Node *prev_node, int new_data);
        void insertNodeAtEnd(Node **head_node, int new_data);

        void deleteNode(Node **node, int new_data);
        void deleteLastNode( Node **head);
};