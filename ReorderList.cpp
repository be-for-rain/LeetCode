/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *ans_tail = NULL;
        for (ListNode *pa = a, *pb = b; ; ) {
            if (pa) {
                if (ans_tail) {
                    ans_tail->next = pa;
                }
                ans_tail = pa;
                pa = pa->next;
            } else {
                break;
            }
            if (pb) {
                ans_tail->next = pb;
                ans_tail = pb;
                pb = pb->next;
            } else {
                break;
            }
        }
    }

    ListNode *reverse(ListNode *head) {
        ListNode *prev = NULL;
        while (head) {
            ListNode *cur = head;
            head = head->next;
            cur->next = prev;
            prev = cur;
        }
        return prev;
    }

    void reorderList(ListNode *head) {
        if (head == NULL) {
            return;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid_head = slow->next;
        slow->next = NULL;
        ListNode *rev_mid_head = reverse(mid_head);
        merge(head, rev_mid_head);
    }
};
