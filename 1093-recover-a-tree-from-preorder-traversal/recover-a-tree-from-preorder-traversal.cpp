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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*,int>>st;
        int i=0;
        string s;
        while(i<traversal.size() && traversal[i]!='-') {
                    s+=traversal[i];
                    i++;
                }
        int num=stoi(s);
        int count_dash=0;
        TreeNode*root=new TreeNode(num);
        st.push({root,0});
        while(i<traversal.size()){
            if(traversal[i]=='-'){
                count_dash++;
                i++;
            }
            else{
                string k;
                int j=i;
                while(j<traversal.size() && traversal[j]!='-') {
                    k+=traversal[j];
                    j++;
                }
                i=j;
                num=stoi(k);
                int level=count_dash-1;
                while(!st.empty() && st.top().second!=level){
                    st.pop();
                }
                TreeNode*temp=new TreeNode(num);
                TreeNode*curr=st.top().first;
                if(curr->left){
                    curr->right=temp;
                }
                else{
                    curr->left=temp;
                }
                st.push({temp,level+1});
                count_dash=0;
            }
        }
        return root;
    }
};