/*
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 *
 *
 * Sol:
 *		If there is a cycle, two pointer proceeds with different velocity shall meet
 *		o.w. there isn't a cycle
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while (p != NULL && q != NULL) {
            if (p->next) {
                p = p->next->next;
            } else {
                return false;
            }
            q = q->next;
            if (p == q) {
                return true;
            }
        }
        return false;
    }
};
