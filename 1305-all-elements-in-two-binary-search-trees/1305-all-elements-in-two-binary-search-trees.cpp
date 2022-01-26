/**
 * Definition for a binary tree node.
 * struct TreeNode 
    {
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
    void dfs(vector<int>&store,TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        dfs(store,root->left);
        store.push_back(root->val);
        dfs(store,root->right);
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>tree_1,tree_2;
        dfs(tree_1,root1);
        dfs(tree_2,root2);
        
        int p1=0;//Position pointer for array-1
        int p2=0;//Position Pointer for Array-2
        vector<int>merged_array;
        while(p1<tree_1.size() and p2<tree_2.size())
        {
            if(tree_1[p1]<tree_2[p2])
            {
                merged_array.push_back(tree_1[p1++]);
            }
            else{
                merged_array.push_back(tree_2[p2++]);

            }
        }
      //  cout<<p2<<'\n';
        while(p1<tree_1.size())
        {
            merged_array.push_back(tree_1[p1++]);
        }
        while(p2<tree_2.size())
        {
            merged_array.push_back(tree_2[p2++]);
        }
        return merged_array;
    }
};