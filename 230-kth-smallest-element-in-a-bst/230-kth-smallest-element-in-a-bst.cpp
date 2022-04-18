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
    int kthSmallest(TreeNode* root, int k) {
        int position = 0;
        return kthSmallestRec(root, k, position)->val;
    }
    TreeNode* kthSmallestRec(TreeNode* node, int k, int& position){
        if(node == NULL){ return node;}
        
        TreeNode* left = kthSmallestRec(node->left, k, position);
        if(left != NULL){
            return left;
        }
        
        position++;
        if(position == k){
            return node;
        }
        
        return kthSmallestRec(node->right, k, position);
    }
};