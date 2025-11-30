/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*&ans){
        if(!root) return nullptr ;
         if(root->val==p->val || root->val==q->val){
            return root;
        }
        TreeNode*left=lca(root->left,p,q,ans);
        TreeNode*right=lca(root->right,p,q,ans);
        if(left && right){
            ans=root;
            return ans;
        }
        return left?left:right;
     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=nullptr;
        TreeNode*temp=lca(root,p,q,ans);
        return ans?ans:temp;
    }
};