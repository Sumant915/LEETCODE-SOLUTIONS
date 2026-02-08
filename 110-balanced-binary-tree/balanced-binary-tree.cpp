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
    int check(TreeNode*root,bool &bal){
        if(!root) return 0;
        int leftheight=check(root->left,bal);
        int rightheight=check(root->right,bal);
        if(abs(leftheight-rightheight)>1) {
           bal=false;
        }
        return 1+max(leftheight,rightheight);
    }
    bool isBalanced(TreeNode* root) {
        bool bal=true;
        check(root,bal);
        return bal;
    }
};