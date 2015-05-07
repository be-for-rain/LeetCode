/*
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * Sol:
 *		for each element in preorder list, find its position in inorder list
 *		then solve it recursively
 *
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
    TreeNode *build(vector<int>::iterator &start, vector<int>::iterator bg, vector<int>::iterator ed) {
        if (bg == ed) {
            return NULL;
        }
        vector<int>::iterator it = find(bg, ed, *start);
        TreeNode *new_node = new TreeNode(*it);
        ++start;
        new_node->left = build(start, bg, it);
        new_node->right = build(start, ++it, ed);
        return new_node;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        vector<int>::iterator it = preorder.begin();
        TreeNode *root = build(it, inorder.begin(), inorder.end());
        return root;
    }
};
