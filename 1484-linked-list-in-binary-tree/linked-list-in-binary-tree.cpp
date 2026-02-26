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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void find(ListNode*head,TreeNode*root,bool &ans,ListNode*dummy){
        if(ans) return;
        if(!head){
            ans=true;
            return;
        }
        if(!root) return;
        if(root->val==head->val){
            find(head->next,root->left,ans,dummy);
            find(head->next,root->right,ans,dummy);
        }
        if(head==dummy){
        find(dummy,root->left,ans,dummy);
        find(dummy,root->right,ans,dummy);
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool ans=0;
        ListNode*dummy=head;
        find(head,root,ans,dummy);
        return ans;
    }
};