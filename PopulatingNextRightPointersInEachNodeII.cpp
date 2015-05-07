/*
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 *
 * You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *          1
 *                 /  \
 *                       2    3
 *                            / \    \
 *                                4   5    7
 *                                After calling your function, the tree should look like:
 *                                         1 -> NULL
 *                                                /  \
 *                                                      2 -> 3 -> NULL
 *                                                           / \    \
 *                                                               4-> 5 -> 7 -> NULL
 *
 * Sol : 
 *		dfs with depth
 *		use a vector to record rightmost node of each depth
 *		update rightmost[depth] when dfs a node with depth 'depth'
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeLinkNode *node, int depth, vector<TreeLinkNode *> &rightmost) {
        if (node == NULL) {
            return;
        }
        if (depth+1 > rightmost.size()) {
            rightmost.resize(depth+1);
        }
        if (rightmost[depth]) {
            rightmost[depth]->next = node;
        }
        rightmost[depth] = node;
        dfs(node->left, depth+1, rightmost);
        dfs(node->right, depth+1, rightmost);
    }
    
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode *> rightmost(64);
        dfs(root, 0, rightmost);
    }
};
