class Node{
    public:
        int data;
        Node* next;

        void printNode(Node* node);
        Node* addTwoNumbers(Node* n1, Node* n2);
        void insert(Node** head_node, int data);
        Node* VectorToNode(std::vector<int> &v);
        void printReverse(Node* head);
};