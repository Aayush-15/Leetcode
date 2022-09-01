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
    int count=0;
    int Total_node=1;
    void dfs(TreeNode* root,int maxi)
    {
        if(root==NULL)
            return;
        Total_node++;
        maxi=max(maxi,root->val);
        if(root->val<maxi)
        {
            count++;
        }
        if(root->left)
        {
             dfs(root->left,maxi);
        }
        if(root->right)
        {
             dfs(root->right,maxi);
        }
        
    }
    int goodNodes(TreeNode* root) 
    {
        int curr_val=root->val;
        dfs(root->left,curr_val);
        dfs(root->right,curr_val);
        return Total_node-count;
    }
};