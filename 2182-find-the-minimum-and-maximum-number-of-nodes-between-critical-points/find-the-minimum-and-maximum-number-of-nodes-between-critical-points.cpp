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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==nullptr) return {-1,-1};
        ListNode*prev=head;
        ListNode*curr=prev->next;
        int firstNode=0;
        int recent_Node=0;
        int count=2;
        int max_dist=INT_MIN;
        int min_dist=INT_MAX;
        vector<int>ans(2,-1);
        while(curr->next){
            if(((curr->val<curr->next->val) && (curr->val<prev->val)) ||((curr->val>curr->next->val) && (curr->val>prev->val))){
                if(firstNode==0){
                    firstNode=count;
                    recent_Node=count;
                }
                else{
                    max_dist=max(max_dist,count-firstNode);
                    min_dist=min(min_dist,count-recent_Node);
                }
                recent_Node=count;
            }
            count++;
            prev=curr;
            curr=curr->next;
        }
        if(max_dist!=INT_MIN && min_dist!=INT_MAX){
            ans[0]=min_dist;
            ans[1]=max_dist;
        }
        return ans;
    }
};