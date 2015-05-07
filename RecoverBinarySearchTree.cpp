/*
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 *
 *
 * Sol:
 *    for a valid BST, its inorder traversal should be a sorted array
 *    so inorderly traverse it on the fly, locate these two nodes
 *		[case 0] there's only one place where a[i+1] >= a[i], a[i] & a[i+1] are what we need
 *		[case 1] there are two places where a[i+1] >= a[i], a[j+1]>=a[j] -- choose a[i+1] & a[j]
 *		 
 * It also means given a sorted array with 2 mis-swapped nodes, find them out
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
    //inorder traversal on the fly
    void findMisNodes(TreeNode *node, TreeNode *&pre, vector<TreeNode*> &mis_nodes) {
        if (node == NULL) {
            return;
        }
        findMisNodes(node->left, pre, mis_nodes);
        if (pre && pre->val >= node->val) {
            mis_nodes[1] = node;
            if (!mis_nodes[0]) {
                mis_nodes[0] = pre;
            }
        }
        pre = node;
        findMisNodes(node->right, pre, mis_nodes);
    }

    void recoverTree(TreeNode *root) {
        vector<TreeNode*> mis_nodes(2);
        TreeNode *pre = NULL;
        findMisNodes(root, pre, mis_nodes);
        int tmp = mis_nodes[0]->val;
        mis_nodes[0]->val = mis_nodes[1]->val;
        mis_nodes[1]->val = tmp;
    }
};

