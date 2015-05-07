/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *buildInterval(ListNode *start, int cnt) {
        if (cnt <= 0) {
            return NULL;
        }
        int mid = cnt / 2, tmp_mid = mid;
        ListNode *mid_node = start;
        while (tmp_mid) {
            mid_node = mid_node->next;
            --tmp_mid;
        }
        TreeNode *new_node = new TreeNode(mid_node->val);
        new_node->left = buildInterval(start, mid);
        new_node->right = buildInterval(mid_node->next, cnt-mid-1);
        return new_node;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        int cnt = 0;
        for (ListNode *p = head; p; p = p->next){
            ++cnt;
        }
        return buildInterval(head, cnt);
    }
};
