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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int maxsum=INT_MIN;
        int level=1;
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            while(size--){
            TreeNode*temp=q.front();
            sum=sum+temp->val;
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
         }
         if(sum>maxsum){
            ans=level;
            maxsum=sum;
         }
         level++;
     }
     return ans;
    }
};