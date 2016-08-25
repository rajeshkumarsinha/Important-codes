/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if(root){
            stringstream sso;sso<<root->val;
            string u;sso>>u;
            s+=u;s+=" ";
            s+=serialize(root->right);
            s+=serialize(root->left);
        }
        else{
            s+="-123 ";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* solve(stringstream &sso){
        int u;sso>>u;
        if(u==-123)return NULL;
        TreeNode* root=new TreeNode(u);
        root->right=solve(sso);
        root->left=solve(sso);
        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream sso(data);
        return solve(sso);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));