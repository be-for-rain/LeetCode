/*
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *                  / \
 *                         2   5
 *                               / \   \
 *                                    3   4   6
 *                                    The flattened tree should look like:
 *                                       1
 *                                           \
 *                                                2
 *                                                      \
 *                                                             3
 *                                                                     \
 *                                                                              4
 *                                                                                        \
 *                                                                                                   5
 *                                                                                                               \
 *                                                                                                                            6
 *
 * Sol:
 *		do pre-order traversal on the fly
 *		[NOTE] remember to update pre node!!
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
    void traverse(TreeNode *root, TreeNode *&pre) {
        if (root == NULL) {
            return;
        }
        TreeNode *tmp_left = root->left, *tmp_right = root->right;
        if (pre) {
            pre->right = root;
        }
        root->left = NULL;
        pre = root;
        traverse(tmp_left, pre);
        traverse(tmp_right, pre);
    }
    
    void flatten(TreeNode *root) {
        TreeNode *pre = NULL;
        traverse(root, pre);
    }
};
