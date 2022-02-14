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
    int dfs(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left_subtree_height=dfs(root->left);
        int right_subtree_height=dfs(root->right);
        return max(left_subtree_height,right_subtree_height)+1;
    }
    int maxDepth(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        int ans=dfs(root);
        return ans;
    }
};