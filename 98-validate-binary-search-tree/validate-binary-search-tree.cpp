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
   void check(TreeNode*root,int &prev,bool &flag,bool &valid){
    if(!root) return;
    check(root->left,prev,flag,valid);
    if(flag!=false){
        if(root->val<=prev){
            valid=0;
        }
    }
    flag=true;
    prev=root->val;
    check(root->right,prev,flag,valid);
   }
    bool isValidBST(TreeNode* root) {
        bool valid=1;
        bool flag=false;
        int prev=0;
        check(root,prev,flag ,valid);
        return valid;
    }
};