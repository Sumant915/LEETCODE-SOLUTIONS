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
    
    bool isEvenOddTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            if(level%2==0){
                TreeNode* a=q.front();
                q.pop();
                n=n-1;
                if(a->val%2==0) return 0;
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                while(n--){
                  TreeNode*temp=q.front();
                  q.pop();
                  if(temp->val%2==0) return 0;
                  if(a->val>=temp->val) return 0;
                  a=temp;
                  if(temp->left) q.push(temp->left);
                  if(temp->right) q.push(temp->right);
                }
                level++;
            }
            else{
                TreeNode* a=q.front();
                q.pop();
                n=n-1;
                if(a->val%2==1) return 0;
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
                while(n--){
                  TreeNode*temp=q.front();
                  q.pop();
                  if(temp->val%2==1) return 0;
                  if(a->val<=temp->val) return 0;
                  a=temp;
                  if(temp->left) q.push(temp->left);
                  if(temp->right) q.push(temp->right);
                }
                level++;
            }
        }
        return 1;
    }
};