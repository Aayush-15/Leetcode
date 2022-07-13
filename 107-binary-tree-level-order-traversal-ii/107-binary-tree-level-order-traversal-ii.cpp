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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
         vector<vector<int>>level_order;
        if(root==NULL)
        {
            return level_order;
        }
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            int sz=que.size();
            vector<int>curr_level;
            for(int i=0;i<sz;i++)
            {
                TreeNode* curr_node=que.front();
                que.pop();
                curr_level.push_back(curr_node->val);
                if(curr_node->left)
                {
                    que.push(curr_node->left);
                }
                if(curr_node->right)
                {
                    que.push(curr_node->right);
                }
            }
            level_order.push_back(curr_level);
        }
        reverse(level_order.begin(),level_order.end());
        return level_order;
    }
};