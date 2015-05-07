/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * Sol:
 *		use stack
 *		push node->right first, node->left second
 */

/**

 * Definition for binary tree

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class Solution {

public:

    vector<int> preorderTraversal(TreeNode *root) {

        vector<int> ans;

        stack<TreeNode*> stk;

        stk.push(root);

        while (!stk.empty()) {

            TreeNode *node = stk.top();

            stk.pop();

            if (node) {

                ans.push_back(node->val);

                stk.push(node->right);

                stk.push(node->left);

            }

        }

        return ans;

    }

};
