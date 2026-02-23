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
    int product(TreeNode*root,long long &totalsum,long long &maxp){
        if(!root) return 0;
        long long left =product(root->left,totalsum,maxp);
        long long right=product(root->right,totalsum,maxp);
        long long currsum=root->val+left+right;
        maxp=max(maxp,(totalsum-currsum)*currsum);
        return int(currsum);
    }
    int maxProduct(TreeNode* root) {
       long long totalsum=0;
       long long maxp=1;
       totalsum=product(root,totalsum,maxp);
       product(root,totalsum,maxp);
       return int(maxp%1000000007);
    }
};