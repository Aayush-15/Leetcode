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
    int ans;
    void Dfs(TreeNode* root,int maxi,int mini)
    {
        
        if(root==NULL)
        {
            return;
        }
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        // cout<<root->val<<" "<<maxi<<" "<<mini<<'\n';
        ans=max(ans,abs(maxi-mini));
        Dfs(root->left,maxi,mini);
        Dfs(root->right,maxi,mini);
    }
    int maxAncestorDiff(TreeNode* root) 
    {
        ans=0;
        int maxi=root->val;
        int mini=root->val;
        Dfs(root,maxi,mini);
        return ans;
    }
};