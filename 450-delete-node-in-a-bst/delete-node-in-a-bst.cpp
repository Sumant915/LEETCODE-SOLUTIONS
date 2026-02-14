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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else{
            //leaf node
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            //right child exist

            else if(!root->left){
                TreeNode*temp=root->right;
                delete root;
                return temp;
            }
            //left child exist
            else if(!root->right){
                TreeNode*temp=root->left;
                delete root;
                return temp;
            }
            //both child exist 
            else{
                TreeNode*parent=root;
                TreeNode*child=parent->left;
                //find greatest elemnt in left side of parent
                while(child->right){
                    parent=child;
                    child=child->right;
                }
                if(parent==root){
                    //iss case ka matlab hai child k right me koi node hi nahi hai 
                    child->right=parent->right;
                    delete root;
                    return child;
                }
                else{
                    parent->right=child->left;
                    child->left=root->left;
                    child->right=root->right;
                    delete root;
                    return child;
                }
            }
        }
        return root;
    }
};