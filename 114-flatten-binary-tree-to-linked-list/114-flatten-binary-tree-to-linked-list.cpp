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
    // Transverse the Tree through pre-order
    void preOrdered(TreeNode* root, vector<TreeNode*> &v){
        if(root == NULL) return;
        v.push_back(root);
        preOrdered(root->left, v);
        preOrdered(root->right, v);
    }
	
	
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> v;
        preOrdered(root, v);
        root->left = NULL;
        for(int i=1; i<v.size(); i++){
            root->right = v[i];
            v[i]->left = NULL;
            root = root->right;
        }
    }

};