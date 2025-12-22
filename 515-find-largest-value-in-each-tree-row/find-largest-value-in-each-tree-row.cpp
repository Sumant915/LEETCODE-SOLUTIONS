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
    void largest(TreeNode*root,int level,vector<int>&arr){
        if(!root) return ;
        if(arr.size()==level){
            arr.push_back(root->val);
        }
        else {
            arr[level]=max(arr[level],root->val);
        }
        largest(root->left,level+1,arr);
        largest(root->right,level+1,arr);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>arr;
        largest(root,0,arr);
        return arr;
    }
};