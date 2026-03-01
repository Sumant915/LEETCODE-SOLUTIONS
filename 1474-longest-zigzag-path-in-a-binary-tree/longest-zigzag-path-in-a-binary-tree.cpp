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
    void maxzigzag(TreeNode*root,bool dir, int count, int &longest){
        if(!root){
        return;
       }
       longest = max(count,longest);
       
       if(!dir){ //right=0,left=1 //pichli direction right thi tabhi direction li value 0 hai 
         if(root->left){
            maxzigzag(root->left,1,count+1,longest);
         }
          if(root->right){
            maxzigzag(root->right,0,1,longest);
         }
       }
       
       else{
         if(root->right){
            maxzigzag(root->right,0,count+1,longest);
         }
         if(root->left){
            maxzigzag(root->left,1,1,longest);
         }
       }
    }
    int longestZigZag(TreeNode* root) {
        int longest = 0;
        bool dir = 0;
        maxzigzag(root->left,1,1,longest);
        maxzigzag(root->right,0,1,longest);
        
        return longest;
    }
};