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

    void recurse(TreeNode* root,vector<int>&resultant){
        if(root==NULL){
            return;
        }
        recurse(root->left,resultant);
        recurse(root->right,resultant);
        resultant.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>resultant;
        recurse(root,resultant);
        return resultant;
    }
};