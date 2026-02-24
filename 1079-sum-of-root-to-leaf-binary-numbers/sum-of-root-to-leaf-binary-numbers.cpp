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
    void findsum(TreeNode*root,int &sum,string binary){
        if(!root) return;
        binary+=to_string(root->val);
        if(!root->left && !root->right){
            sum+=stoi(binary,nullptr,2);
            return;
        }
        findsum(root->left,sum,binary);
        findsum(root->right,sum,binary);
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        string binary="";
        findsum(root,sum,binary);
        return sum;
    }
};