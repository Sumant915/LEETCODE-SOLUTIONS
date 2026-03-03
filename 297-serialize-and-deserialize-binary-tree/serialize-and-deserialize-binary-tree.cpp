/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    // Encodes a tree to a single string.
class Codec{
  public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string s = "";

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                s += to_string(node->val);
                s += ",";  
                q.push(node->left);
                q.push(node->right);   // n,n,n]
            } else {
                s += "n,";              //1,200,3,n,n,4,5,n,n,n,n,     
        }
        }
        return s;
    } 
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if (data == "") return nullptr;
        queue<TreeNode*> q;
        int i = 0;
        string temp = "";
        // ---- root read karo ----
        while (i < data.size() && data[i] != ',') {
            temp += data[i];
            i++;
        }
        i++;
        TreeNode* root = new TreeNode(stoi(temp));
        q.push(root);
        // ---- remaining nodes ----
        while (!q.empty() && i < data.size()) {
            TreeNode* node = q.front();
            q.pop();
            // ----- LEFT -----
            temp = "";
            while (i < data.size() && data[i] != ',') {
                temp += data[i];
                i++;
            }
            i++;
            if (temp != "n") {
                TreeNode* leftNode = new TreeNode(stoi(temp));
                node->left = leftNode;
                q.push(leftNode);
            }
            // ----- RIGHT -----
            temp = "";
            while (i < data.size() && data[i] != ',') {
                temp += data[i];
                i++;
            }
            i++;
            if (temp != "n") {
                TreeNode* rightNode = new TreeNode(stoi(temp));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));