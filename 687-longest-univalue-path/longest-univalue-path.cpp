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
   int findpath(TreeNode*root,TreeNode*parent,int &maxpath){
    if(root==nullptr) return 0;
    int left= findpath(root->left,root,maxpath);
    int right=findpath(root->right,root,maxpath);
    if(root->left && root->left->val != root->val)
            left = 0;
    if(root->right && root->right->val != root->val)
            right = 0;
    maxpath = max(maxpath, left + right);
    if(parent && root->val == parent->val)
            return 1 + max(left,right);
    return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        int maxpath=0;
        findpath(root,root,maxpath);
        return maxpath;
    }
};