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
    void bfs(TreeNode* root,vector<int>&Level_Sum){
            int curr_level=0;
            queue<TreeNode*>que;
            que.push(root);
            while (!que.empty()) 
            {
                int current_level_sum = 0;    // Sum for the current level
                int level_size=que.size();
                for (int i = 0; i < level_size; ++i) {
                    TreeNode* curr_node = que.front();
                    que.pop();
                    current_level_sum += curr_node->val; // Accumulate the sum

                    if (curr_node->left) {
                        que.push(curr_node->left);
                    }
                    if (curr_node->right) {
                        que.push(curr_node->right);
                    }
                }
        
            Level_Sum.push_back(current_level_sum); // Store the sum for the current level
        }
    }
    void dfs(TreeNode* root,int level,int value,vector<int>&Level_Sum){
        if(root==NULL) return;

        root->val=value;
        int next_level_sum=0;
        if(level+1<Level_Sum.size()){
            next_level_sum=Level_Sum[level+1];
        }
        if(root->left!=NULL){
            next_level_sum-=root->left->val;
        }
        if(root->right!=NULL){
            next_level_sum-=root->right->val;
        }
        dfs(root->left,level+1,next_level_sum,Level_Sum);
        dfs(root->right,level+1,next_level_sum,Level_Sum);

    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>Level_Sum;
        bfs(root,Level_Sum);
        dfs(root,0,0,Level_Sum);
        return root;
        
    }
};