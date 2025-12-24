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
    ListNode* removeNodes(ListNode* head) {
        ListNode*curr=head;
        ListNode*prev=nullptr;
        while(curr){
            ListNode*fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
      //ab prev jo hoga wo reverse linked list ka head me hoga
      ListNode*head2=prev;
      curr=head2;
      prev=nullptr;
      int Max_val=INT_MIN;
      while(curr){
        if(Max_val>curr->val){
            prev->next=curr->next;
            curr=curr->next;
        }
        else{
            Max_val=curr->val;
            prev=curr;
            curr=curr->next;
        }
      }
      //ab jo new linked list form hui hai usse reverse kardo 
      curr=head2;
      prev=nullptr;
      while(curr){
            ListNode*fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        return prev;
    }
};