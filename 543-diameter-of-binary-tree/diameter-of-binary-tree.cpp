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
   int findmaxd(TreeNode*root,int &maxd){
     if(!root) return 0;
     int left=findmaxd(root->left,maxd);
     int right=findmaxd(root->right,maxd);
     maxd=max(maxd,right+left);
     return 1+max(left,right);
   }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxd=0;
        findmaxd(root,maxd);
        return maxd;
    }
};