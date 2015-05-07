/*
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 *
 * Sol:
 *		if ptr has a duplicate
 *		then ptr must be the same with its pre or its next
 * Note:
 *		remember to set tail->next = NULL (if tail != NULL)
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
    bool isSame(ListNode *a, ListNode *b) {
        return a && b && (a->val == b->val);
    }
    
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *pre = NULL, *tail = NULL, *new_head = NULL;
        for (ListNode *p = head; p; p = p->next) {
            if (!isSame(pre, p) && !isSame(p->next, p)) {
                if (!tail) {
                    tail = p;
                    new_head = p;
                } else {
                    tail->next = p;
                    tail = p;
                }
            }
            pre = p;
        }
        if (tail) {
            tail->next = NULL;
        }
        return new_head;
    }
};
