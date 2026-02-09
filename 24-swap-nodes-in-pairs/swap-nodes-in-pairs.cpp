/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       if(!head || !head->next) return head;
        ListNode*dummy=new ListNode(-1);
        ListNode*prev=dummy;
        ListNode*first=head;
        ListNode*second=first->next;
        while(first && second){
            ListNode*fut=second->next;
            prev->next=second;
            second->next=first;
            first->next=fut;
            prev=first;
            first=first->next;
            if(first!=nullptr){
            second=first->next;
            }
        }
    return dummy->next;
    }
};