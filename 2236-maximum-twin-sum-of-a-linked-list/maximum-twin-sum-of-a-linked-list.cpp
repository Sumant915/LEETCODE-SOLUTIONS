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
    int pairSum(ListNode* head) {
       ListNode*slow=head;
       ListNode*fast=head;
       while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
       }
       ListNode*head2=slow->next;
       slow->next=nullptr;
       ListNode*prev=nullptr;
       ListNode*curr=head2;
       while(curr){
        ListNode*fut=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fut;
       }
       head2=prev;
       int max_sum=0;
       while(head && head2){
           int value = head->val + head2->val;
           max_sum=max(max_sum,value);
           head = head->next;
           head2 = head2->next;
       }
       return max_sum;
    }
};