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
   int treesum(TreeNode*root,unordered_map<int,int>&mp){
    if(!root) return 0;
    int left=treesum(root->left,mp);
    int right=treesum(root->right,mp);
    mp[left+right+root->val]++;
    return left+right+root->val;
   }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mp;
        treesum(root,mp);
        int maxi=0;
        for(auto &it:mp){
            maxi=max(maxi,it.second);
        }
        vector<int>ans;
        for(auto &it:mp){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};