class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        rightView(root, view, 0);
        return view;
    }
private:
    void rightView(TreeNode* root, vector<int>& view, int level) {
        if (!root) {
            return;
        }
        if (view.size() == level) {
            view.push_back(root -> val);
        }
        rightView(root -> right, view, level + 1);
        rightView(root -> left, view, level + 1);
    }
};
