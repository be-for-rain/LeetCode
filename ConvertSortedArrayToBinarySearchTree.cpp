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
    TreeNode *insertInterval(vector<int> &num, int left, int right) {
        if (left == right) {
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode *new_node = new TreeNode(num[mid]);
        new_node->left = insertInterval(num, left, mid);
        new_node->right = insertInterval(num, mid+1, right);
        return new_node;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
       TreeNode *root = insertInterval(num, 0, num.size());//NULL;
       return root;
    }
};
