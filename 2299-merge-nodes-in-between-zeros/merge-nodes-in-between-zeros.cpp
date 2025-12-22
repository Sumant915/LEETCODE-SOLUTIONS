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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*curr=head;
        ListNode*dummy=new ListNode(-1);
        ListNode*tail=dummy;
        while(curr && curr->next){
            ListNode*count=curr->next;
            int sum=0;
            while(count->val!=0){
                sum+=count->val;
                count=count->next;
            }
            curr=count;
            tail->next=new ListNode(sum);
            tail=tail->next;
        }
        return dummy->next;
    }
};