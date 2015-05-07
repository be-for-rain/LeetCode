/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
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
    ListNode *getKthNode(ListNode *head, int k) {
        if (k == 0) {
            return NULL;
        }
        if (k == 1) {
            return head;
        }
        return getKthNode(head->next, k-1);
    }
    
    void reverse(ListNode *&head, ListNode *&tail, int k) {
         if (head == NULL || k <= 1) {
             tail = head;
             return;
         }
         ListNode *new_head = head->next;
         reverse(new_head, tail, k-1);
         if (tail) {//successfully reversed
            head->next = tail->next; //insert head
            tail->next = head;
            tail = head;
            head = new_head;
         }
         return;
    }
    
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *tail = NULL;
        ListNode *pre_start = getKthNode(head, m-1);
        if (pre_start) {
            reverse(pre_start->next, tail, n-m+1);
        } else {
            reverse(head, tail, n-m+1);
        }
        return head;
    }
};
