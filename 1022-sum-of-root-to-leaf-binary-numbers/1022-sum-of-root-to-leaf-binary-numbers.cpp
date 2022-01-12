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
    int sum=0;
    void dfs(TreeNode* root,vector<int>&curr_list)
    {
        if(root->left==NULL and root->right==NULL)
        {
            curr_list.push_back(root->val);
            int curr_sum=0;
            int sz=curr_list.size();
            for(int i=sz-1,j=0;i>=0;i--,j++)
            {
                curr_sum+=(curr_list[i]*(pow(2,j)));
            }
            sum+=curr_sum;
           // cout<<curr_sum<<'\n';
            curr_list.pop_back();
            return;
        }
        if(root->left)
        {
            curr_list.push_back(root->val);
            dfs(root->left,curr_list);
            curr_list.pop_back();
        }
        if(root->right)
        {
            curr_list.push_back(root->val);
            dfs(root->right,curr_list);
            curr_list.pop_back();
        }
        
        
        
    }
    int sumRootToLeaf(TreeNode* root) 
    {
        vector<int>curr_list;
        dfs(root,curr_list);
        return sum;
    }
};