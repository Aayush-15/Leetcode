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
    TreeNode* dfs(vector<int>&nums,int l,int r)
    {
        if(l==r)
        {
            TreeNode* curr_node=new TreeNode(nums[l]);
            return curr_node;
        }
        if(l>r)
        {
            return nullptr;
        }
        int mid=(l+r)/2;
        TreeNode* curr_node=new TreeNode(nums[mid]);
        curr_node->left=dfs(nums,l,mid-1);
        curr_node->right=dfs(nums,mid+1,r);
        return curr_node;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int l=0;
        int r=nums.size()-1;
        return dfs(nums,l,r);
    }
};