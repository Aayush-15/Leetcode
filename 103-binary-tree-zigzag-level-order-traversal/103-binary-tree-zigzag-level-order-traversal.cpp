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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        queue<TreeNode*>que;
        if(root==NULL)
        {
            return ans;
        }
        que.push(root);
        int height=0;
        while(!que.empty())
        {
            int sz=que.size();
            height++;
            vector<int>curr;
            while(sz>0)
            {
                TreeNode* curr_root=que.front();
                que.pop();
                
                curr.push_back(curr_root->val);
                if(curr_root->left!=NULL){
                    que.push(curr_root->left);
                }
                
                
                if(curr_root->right!=NULL){
                     que.push(curr_root->right);
                }
               
                sz--;
            }
            if(height%2==0)
            {
                reverse(curr.begin(),curr.end());
            }
            ans.push_back(curr);
            
        }
        return ans;
    }
};