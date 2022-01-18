/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool recurseTree(TreeNode* curr_node,TreeNode* p,TreeNode* q)
    {
        if(curr_node==NULL)
        {
            return false;
        }
        int left=recurseTree(curr_node->left,p,q)? 1: 0;
        int right=recurseTree(curr_node->right,p,q) ? 1:0;
        int curr=(curr_node==p||curr_node==q) ? 1 : 0 ;
        if(left+right+curr>=2)
        {
            //cout<<"hii"<<'\n';
            ans=curr_node;
        }
        if(left+right+curr>0)
        {
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //return ans;
        recurseTree(root,p,q);
        return ans;
    }
};