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
    /*
    Greedy Approach Will Not Work For This Case
   4
    \
	   1
		 \
		   2
			  \
				3
     
*/
    /*
    The general idea here is that at each node you have two choices.
You can either decide to rob that node, or skip it.
From this central idea, we can derive the following logic.

At each node, we return the possibilities if we had decided to rob that node, or if we had decided to skip it (this is represented in the structure RobbedRoot).

To find out the maximum stolen money if the robber had decided to steal from the current node, we must skip the left and right nodes.
int robThisNode = root->val + robLeft.skippedRoot + robRight.skippedRoot;
This is so that we do not trip the alarms of two adjacent house nodes.

However, if we decide to skip the current node, we have two options for the left and right sides.
We can now rob the left and/or right node, as our skipping of the current node means that we won't trip the alarm.
But we can also decide to skip the left and/or right node.

This is because greedily robbing the node just because you have the option to does not guarantee that you will make the maximum profit, as by robbing a node, you could block off an adjacent higher value node which could lead to a higher profit.
    */
    
struct RobbedRoot {
    int robbedRoot;
    int skippedRoot;
};

class Solution {
private:
    RobbedRoot robDFS(TreeNode* root) {
        if (root == nullptr) {
            return RobbedRoot{0, 0};
        }
        
        RobbedRoot robLeft = robDFS(root->left);
        RobbedRoot robRight = robDFS(root->right);
        
        int robThisNode = root->val + robLeft.skippedRoot + robRight.skippedRoot;
        int skipThisNode = max(robLeft.robbedRoot, robLeft.skippedRoot) + max(robRight.robbedRoot, robRight.skippedRoot);
        
        return RobbedRoot{robThisNode, skipThisNode};
    }
public:
    int rob(TreeNode* root) {
        RobbedRoot finalState = robDFS(root);
        
        return max(finalState.robbedRoot, finalState.skippedRoot);
    }
};
