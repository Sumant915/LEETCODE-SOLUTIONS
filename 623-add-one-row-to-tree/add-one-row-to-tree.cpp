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
    void row(TreeNode*root,int val,int depth,int level){
        if(!root) return;
        if(level>=depth) return;
        if(level==depth-1){
            TreeNode*temp1=new TreeNode(val);
            TreeNode*temp2=new TreeNode(val);
            temp1->left=root->left;
            root->left=temp1;
            temp2->right=root->right;
            root->right=temp2;
            return;
        }
        row(root->left,val,depth,level+1);
        row(root->right,val,depth,level+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*temp=new TreeNode(val);
            temp->left=root;
            root=temp;
            return root;
        }
        int level=1;
        row(root,val,depth,level);
        return root;
    }
};