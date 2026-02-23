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
    void findsum(TreeNode*root,TreeNode*parent,TreeNode*grandparent,int &sum){
        if(!root) return;
        if(grandparent){
        if(grandparent->val%2==0) {
            sum+=root->val;
        }
        }
        findsum(root->left,root,parent,sum);
        findsum(root->right,root,parent,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        TreeNode*parent=nullptr;
        TreeNode*grandparent=nullptr;
        int sum=0;
        findsum(root,parent,grandparent,sum);
        return sum;
    }
};