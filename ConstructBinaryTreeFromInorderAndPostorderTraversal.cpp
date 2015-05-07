/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * Sol:
 *		similar to the preorder&inorder version
 *		deal each element of postorder vector from back to front
 *		find its position in inorder vector
 *		then construct its right subtree
 *		left subtree then
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
    TreeNode *build(vector<int>::reverse_iterator &candidate, vector<int>::iterator st, vector<int>::iterator ed) {
        if (st == ed) {
            return NULL;
        }
        vector<int>::iterator it = find(st, ed, *candidate);
        TreeNode *new_node = new TreeNode(*it);
        ++candidate;
        new_node->right = build(candidate, it+1, ed);
        new_node->left = build(candidate, st, it);
        return new_node;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        vector<int>::reverse_iterator it = postorder.rbegin();
        return build(it, inorder.begin(), inorder.end());
    }
};
