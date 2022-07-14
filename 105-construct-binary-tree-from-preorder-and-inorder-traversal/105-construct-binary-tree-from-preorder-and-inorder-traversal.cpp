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
    map<int,int>mp;//storing the indices of preorder
    int pre_index=0;
    
    TreeNode* BuildTree(int left,int right,vector<int>&preorder)
    {
        if(left>right)
            return nullptr;
        int curr=preorder[pre_index++];
        TreeNode* tmp=new TreeNode(curr);
        int mid=mp[tmp->val];
        tmp->left=BuildTree(left,mid-1,preorder);
        tmp->right=BuildTree(mid+1,right,preorder);
        return tmp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        for(int i=0;i<preorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int n=inorder.size();
        TreeNode* root=BuildTree(0,n-1,preorder);
        return root;
    }
};