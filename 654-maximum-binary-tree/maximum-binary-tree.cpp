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
    int findmax(vector<int>&nums,int l,int h){
        int max=l;
        for(int i=l;i<=h;i++){
            if(nums[i]>nums[max]){
                max=i;
            }
        }
        return max;
    }
    TreeNode*construct(vector<int>&nums,int l,int h){
          if(l>h){
            return nullptr;
          }
          int maxi=findmax(nums,l,h);
          TreeNode*root=new TreeNode(nums[maxi]);
          root->left=construct(nums,l,maxi-1);
          root->right=construct(nums,maxi+1,h);
          return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums,0,nums.size()-1);
    }
};