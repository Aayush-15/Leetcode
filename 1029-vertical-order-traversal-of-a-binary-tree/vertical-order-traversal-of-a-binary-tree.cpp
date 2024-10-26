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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>Vertical_Order_Traversal_Array;
		map<int, map<int, multiset<int>>> ordering;//Stores the X And Y Co-Ordinates
		queue<pair<TreeNode*, pair<int, int>>>que;

		que.push({root, {0, 0}});
		while (!que.empty()) {
			TreeNode* curr_node = que.front().first;
			int x = que.front().second.first; //It Stores the Width
			int y = que.front().second.second;// It Stores the Depth/Height
			que.pop();
			ordering[x][y].insert(curr_node->val);
			if (curr_node->left != nullptr) {
				que.push({curr_node->left, {x - 1, y + 1}});

			}
			if (curr_node->right != nullptr) {
				que.push({curr_node->right, {x + 1, y + 1}});
			}
		}
		for (auto x : ordering) {
			vector<int>vertical_ordering;
			for (auto q : x.second) {
				//Q is of type map<int(Y-Val),multiset<int>>
				for (auto itr : q.second) {

					vertical_ordering.push_back(itr);
				}
			}
			Vertical_Order_Traversal_Array.push_back(vertical_ordering);
		}
		return Vertical_Order_Traversal_Array;
    }
};