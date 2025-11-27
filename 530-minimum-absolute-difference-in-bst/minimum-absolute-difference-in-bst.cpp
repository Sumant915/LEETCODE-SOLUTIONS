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
    void minimumdiff(TreeNode*root,int &prev,int &ans,bool &flag){
        if(!root) return ;
        minimumdiff(root->left,prev,ans,flag);
        if(flag!=false){
            ans=min(ans,root->val-prev);
        }
        flag=true;
        prev=root->val;
         minimumdiff(root->right,prev,ans,flag);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        bool flag=false;
        int prev=0;
        minimumdiff(root,prev,ans,flag);
        return ans;
    }
};