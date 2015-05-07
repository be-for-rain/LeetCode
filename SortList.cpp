/*
 * Sort a linked list in O(n log n) time using constant space complexity.
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
    
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *left_head = sortList(head);
        ListNode *right_head = sortList(mid);
        return mergeTwoLists(left_head, right_head);
    }
};
