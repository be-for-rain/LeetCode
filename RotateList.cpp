/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
    ListNode *right_head = NULL;

    void reverse(ListNode *x, ListNode *&new_head, int k) {
        if (!x || !x->next || k==0 || k==1) {
            new_head = x;
            if (k >= 0) {
                right_head = new_head ? new_head->next : NULL;
            }
            return;
        }
        reverse(x->next, new_head, k-1);
        x->next->next = x;
        x->next = NULL;
    }
    
    int getLength(ListNode *x) {
        int len = 0;
        while (x) {
            len++;
            x = x->next;
        }
        return len;
    }
    
    ListNode *rotateRight(ListNode *head, int k) {
        int len = getLength(head);
        if (len == 0 || (k=k%len) == 0) {
            return head;
        }
        
        ListNode *origin_head = head, *origin_tail = NULL;
        ListNode *new_right_head = NULL, *new_head = NULL;
        
        reverse(origin_head, origin_tail, -1);
        reverse(origin_tail, new_head, k);
        reverse(right_head, new_right_head, -1);
        
        if (origin_tail) 
            origin_tail->next = new_right_head;
        return new_head;
    }
};
