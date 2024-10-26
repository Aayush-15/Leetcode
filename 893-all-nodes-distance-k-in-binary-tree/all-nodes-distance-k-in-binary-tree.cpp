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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        map<TreeNode*, TreeNode*>parent_mapping;

        queue<TreeNode*>que;
        parent_mapping[root] = root;
        que.push(root);
        while (!que.empty()) {
            TreeNode* curr_node = que.front();
            que.pop();
            if (curr_node->left != nullptr) {
                parent_mapping[curr_node->left] = curr_node;
                que.push(curr_node->left);
            }
            if (curr_node->right != nullptr) {
                parent_mapping[curr_node->right] = curr_node;
                que.push(curr_node->right);
            }
        }
        // Now I will start the BFS With Target Node And Traverse in All the 3 directions.(Parent and 2 child Nodes)
        //  TO make sure the Node is not traversed again.I need to Keep track of visited Nodes.
        unordered_map<TreeNode*, bool>visited;
        int curr_distance = 0;
        visited[target] = true;
        que.push(target);
        while (!que.empty()) {
            if (curr_distance == k) {
                break;
            }
            int current_level_sz = que.size();
            for (int i = 0; i < current_level_sz; i++) {
                TreeNode* curr_node = que.front();
                que.pop();

                if (curr_node->left != nullptr && visited[curr_node->left] != true) {
                    que.push(curr_node->left);
                    visited[curr_node->left] = true;
                }
                if (curr_node->right != nullptr && visited[curr_node->right] != true) {
                    que.push(curr_node->right);
                    visited[curr_node->right] = true;
                }
                if (parent_mapping[curr_node] != curr_node && visited[parent_mapping[curr_node]] != true) {
                    que.push(parent_mapping[curr_node]);
                    visited[parent_mapping[curr_node]] = true;
                }
            }
            curr_distance++;//It indicates the Level of Nodes Present in The Queue
        }
        vector<int>disance_k_nodes;
        while (!que.empty()) {
            TreeNode* curr_node = que.front();
            que.pop();
            disance_k_nodes.push_back(curr_node->val);
        }
        return disance_k_nodes;
        
    }
};