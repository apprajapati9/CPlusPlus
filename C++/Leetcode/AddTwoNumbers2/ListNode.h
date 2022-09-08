#include <iostream>
#include <vector>
using namespace std;

class ListNode {

    public:
        int val;
        ListNode *next;
        
        void printlist(ListNode *n){
            cout << "[";
            while( n != nullptr){
                cout << n->val ;
                if(n->next != nullptr) {
                    cout << ",";
                } 
                n = n->next;
            }
            cout << "]" << endl;
        }
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}

        ListNode* AddTwoNumbers(ListNode* l1, ListNode *l2){
            int carry = 0;
            int sum;
            ListNode *head = new ListNode(0);
            ListNode *current_node = head;

            while(l1 != nullptr || l2 != nullptr || carry == 1){
                
                int num1 = l1 ? l1->val : 0;
                int num2 = l2 ? l2->val : 0;

                sum = carry == 1 ? num1 + num2 + 1 : num1 + num2;
                carry = 0;
                if(sum/10 >= 1){
                    carry = 1;
                    sum = sum%10; 
                    current_node->next = new ListNode(sum);
                    current_node = current_node->next;
                }else{
                    current_node->next = new ListNode(sum);
                    current_node = current_node->next;
                }

                l1 = l1? l1->next : nullptr;
                l2 = l2? l2->next : nullptr;
            }
            return head->next;
        }

        ListNode* VectorToNode(vector<int> &v){
            ListNode * root = nullptr;

            for(int x : v){
                ListNode* new_node = new ListNode();
                new_node->val = x;
                new_node->next = nullptr;

                ListNode* temp_node = root;

                if(root == nullptr){
                    root = new_node;
                }else{
                    while(temp_node->next != nullptr){
                        temp_node = temp_node->next;
                    }
                    temp_node->next = new_node;
                }
            }

            return root;
        }
};