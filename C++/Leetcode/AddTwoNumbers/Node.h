class Node{
    public:
        int data;
        Node* next;

        void printNode(Node* node);
        int addTwoNumbers(Node* n1, Node* n2);
       // void insertNode(Node** head_node, int data);
        Node* VectorToNode(std::vector<int> &v);
};