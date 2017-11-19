#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
        int extra=0;
        ListNode* node = (ListNode*) malloc (sizeof(ListNode));
        ListNode* head = node;
        while(l1!=NULL || l2!=NULL || extra!=0) {
            node->val=0;
            if (l1!=NULL)    node->val+=l1->val;
            if (l2!=NULL)    node->val+=l2->val;
            if (extra != 0)node->val += extra;
            if (node->val>9) {
                node->val-=10;
                extra = 1;
            } else extra = 0;
            if (l1 != NULL) l1=l1->next;
            if (l2 != NULL) l2=l2->next;
            if(l1 || l2 || extra) {
                node->next = (ListNode*) malloc (sizeof(ListNode));
                node=node->next;
            }
        }
        node->next=NULL;
        return head;
    }
};

int main() {
    ListNode* l1 = (ListNode*) malloc (sizeof(ListNode));
    ListNode* l1_i =l1;
    ListNode* l2 = (ListNode*) malloc (sizeof(ListNode));
    ListNode* l2_i =l2;

    l1->val =2;
    l1->next = (ListNode*) malloc (sizeof(ListNode));
    l1=l1->next;
    l1->val =4;
    l1->next = (ListNode*) malloc (sizeof(ListNode));
    l1=l1->next;
    l1->val =3;
    l1->next=NULL;

    l2->val =5;
    l2->next = (ListNode*) malloc (sizeof(ListNode));
    l2=l2->next;
    l2->val =6;
    l2->next = (ListNode*) malloc (sizeof(ListNode));
    l2=l2->next;
    l2->val =4;
    l2->next=NULL;

    Solution s1;
    ListNode* Result = s1.addTwoNumbers(l1_i, l2_i);
    cout << Result->val;
    Result = Result->next;
    cout << Result->val;
    Result = Result->next;
    cout << Result->val;
};
