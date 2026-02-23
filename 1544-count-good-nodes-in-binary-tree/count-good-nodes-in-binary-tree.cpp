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
    int countgood(TreeNode*root,int maxnode,int &count){
          if(!root) return 0;
          if(root->val>=maxnode) {
            count++;
            maxnode=root->val;
            }
          if(root->left){
            countgood(root->left,max(root->left->val,maxnode),count);
          }
          if(root->right){
            countgood(root->right,max(root->right->val,maxnode),count);
          }
          return count;
    }
    int goodNodes(TreeNode* root) {
        int maxnode=INT_MIN;
        int count=0;
        return countgood(root,maxnode,count);
    }
};