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
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int ans=0;
        if(root==NULL)
        {
            return 0;
        }
        if(root->val>=low and root->val<=high)
        {
           
            ans+=root->val;
            ans+=rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        }
        //Go to Left as right subtree all node values would be greater than its root node
        else if(root->val>high)
        {
            ans+=rangeSumBST(root->left,low,high);
        }
        //Go to Right as Right subtree all node values would be greater than its root node
        else if(root->val<low)
        {
            ans+=rangeSumBST(root->right,low,high);
        }
        return ans;
    }
};