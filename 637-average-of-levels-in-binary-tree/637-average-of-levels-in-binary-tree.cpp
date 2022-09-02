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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double>ans;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            double curr_sum=0;
            int curr_level_size=que.size();
            for(int index=0;index<curr_level_size;index++)
            {
                TreeNode*curr_node=que.front();
                que.pop();
                curr_sum+=(curr_node->val);
                if(curr_node->left)
                {
                    que.push(curr_node->left);
                }
                if(curr_node->right)
                {
                    que.push(curr_node->right);
                }
            }
            ans.push_back(curr_sum/(double)curr_level_size);
        }
        return ans;
    }
};