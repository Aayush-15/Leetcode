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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr){
            return vector<vector<int> >();
        }
        vector<vector<int>>result;
        queue<TreeNode*>que;
        que.push(root);
        bool left_to_right=true;
        while(!que.empty()){
            int sz=que.size();
            vector<int>curr_row(sz,0);
            for(int i=0;i<sz;i++){
                TreeNode* curr_node = que.front();
                que.pop();

                int index=(left_to_right)?i:(sz-i-1);
                curr_row[index] = curr_node->val;
                if(curr_node->left){
                    que.push(curr_node->left);
                }
                if(curr_node->right){
                    que.push(curr_node->right);
                }

            }
            left_to_right = !left_to_right;
            result.push_back(curr_row);
        }
        return result;

        
    }
};