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
    void leaves(TreeNode*root,vector<int>&arr){
        if(!root) return;
        if(!root->left && !root->right) arr.push_back(root->val);
        leaves(root->left,arr);
        leaves(root->right,arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1;
        vector<int>arr2;
        leaves(root1,arr1);
        leaves(root2,arr2);
        if(arr1.size()!=arr2.size()) return 0;
        for(int i=0;i<arr1.size();i++){
            if(arr1[i]!=arr2[i]) return 0;
        }
        return 1;
    }
};