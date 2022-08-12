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
    TreeNode* LCA(TreeNode* root,TreeNode *p,TreeNode *q)
    {
        while(root!=NULL)
        {
            //if both roots are smaller than current root node
            //LCA Lies In Left Sub-tree
            if(root->val>p->val&&root->val>q->val)
            {
                root=root->left;
            }
            //if both roots are greater than current root node
            //LCA Lies In Right Sub-tree
            else if(root->val<p->val&&root->val<q->val)
                root=root->right;
            else
                break;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* LCA_NODE=LCA(root,p,q);
        return LCA_NODE;
    }
};