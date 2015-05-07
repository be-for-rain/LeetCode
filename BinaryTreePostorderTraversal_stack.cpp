/*
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 * Sol:
 *		stack. 
 *		auto machine
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
    struct SNode {//super tree node
        TreeNode *node;
        int mark;
        SNode(TreeNode *nd = NULL) : node(nd), mark(0) {}
    };
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<SNode*> stk;
        SNode *tmp = new SNode(root);
        stk.push(tmp);
        while (!stk.empty()) {
            SNode *snode = stk.top();
            stk.pop();
            if (snode->node == NULL)
                continue;
            snode->mark++;
            if (snode->mark == 3) {
                ans.push_back(snode->node->val);
                continue;
            }
            stk.push(snode);
            if (snode->mark == 1) {
                stk.push(new SNode(snode->node->left));
            } else {
                stk.push(new SNode(snode->node->right));
            }
        }
        return ans;
    }
};
