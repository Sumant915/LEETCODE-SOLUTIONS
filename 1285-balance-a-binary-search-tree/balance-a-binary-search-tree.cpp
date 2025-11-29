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
    TreeNode* newbalancebst(vector<int>&inorder,int start,int end){
        if(start>end) return nullptr;
         int mid=start+(end-start)/2;
         TreeNode*temp=new TreeNode(inorder[mid]);
         temp->left=newbalancebst(inorder,start,mid-1);
         temp->right=newbalancebst(inorder,mid+1,end);
         return temp;
    }
    void newbst(TreeNode*root,vector<int>&inorder){
        if(!root) return ;
        newbst(root->left,inorder);
        inorder.push_back(root->val);
        newbst(root->right,inorder);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        newbst(root,inorder);
        int start=0;
        int end=inorder.size()-1;
       return newbalancebst(inorder,start,end);
    }
};