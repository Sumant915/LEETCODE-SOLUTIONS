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
    void countNode(ListNode*curr,int &count){
        while(curr){
            curr=curr->next;
            count++;
        }
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int count=0;
        countNode(head,count);
        int end=count-k+1;
        ListNode*first=head;
        ListNode*second=head;
        while(--k){
              first=first->next;
        }
        while(--end){
            second=second->next;
        }
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        return head;
    }
};