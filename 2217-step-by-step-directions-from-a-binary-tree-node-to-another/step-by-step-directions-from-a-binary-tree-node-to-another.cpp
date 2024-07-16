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
	bool generate_path(TreeNode* root, int desired_node, string &path)
	{
		if (root == NULL)
		{
			return false;
		}
		if (root->val == desired_node)
		{
			return true;
		}

		if (generate_path(root->left, desired_node, path))
		{
			path.push_back('L');
		}
		else if (generate_path(root->right, desired_node, path))
		{
			path.push_back('R');
		}
		return !path.empty();
	}
	string getDirections(TreeNode* root, int startValue, int destValue)
	{
		string res = "", root_to_start = "", root_to_end = "";
		generate_path(root, startValue, root_to_start);
		generate_path(root, destValue, root_to_end);
		// I have Path from start node to Root node->str(root_to_start)
		// I have Path from end Node to Root Node->str(root_to_end)
		//Pop Back the Common Suffix from Both The String(Which Is Path from Lca Node to Root Node)
		while (root_to_start.size() > 0 and root_to_end.size() > 0 and root_to_end.back() == root_to_start.back())
		{
			root_to_end.pop_back();
			root_to_start.pop_back();
		}
		//Since Lca is Ancestor of Start And End Node
		//Path from start to LCA node->Replace every step with 'U'->because move in upward direction every time
		for (auto &x : root_to_start)
		{
			x = 'U';
		}
		//Reverse the string which stores path from root to destination
		reverse(root_to_end.begin(), root_to_end.end());
		res = root_to_start + root_to_end;

		return res;
	}
};
