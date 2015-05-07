/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 *
 * Sol:
 *		while they are not both empty
 *		choose the smaller node to insert to the new list
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
    bool shldChooseFormer(ListNode *a, ListNode *b) {
        if (a == NULL) {
            return false;
        }
        if (b == NULL) {
            return true;
        }
        return a->val <= b->val;
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode *cur = NULL;
        while (l1 || l2) {
            if (shldChooseFormer(l1, l2)) {
                if (cur) {
                    cur->next = l1;
                    cur = cur->next;
                } else {
                    head = cur = l1;
                }
                l1 = l1->next;
            } else {
                if (cur) {
                    cur->next = l2;
                    cur = cur->next;
                } else {
                    head = cur = l2;
                }
                l2 = l2->next;
            }
        }
        return head;
    }
};
