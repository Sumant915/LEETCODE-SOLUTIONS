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
    void find(TreeNode*root,int &minimum,long long &sminimum){
        if(!root) return;
        if(root->val>minimum && root->val<=sminimum){
            sminimum=root->val;
        }
        find(root->left,minimum,sminimum);
        find(root->right,minimum,sminimum);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int minimum=root->val;
        long long sminimum=LLONG_MAX;
        find(root,minimum,sminimum);
        if(sminimum==LLONG_MAX) return -1;
        return int(sminimum);
    }
};