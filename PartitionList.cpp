/*
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *smaller_head = NULL, *smaller_tail = NULL, *greater_head = NULL, *greater_tail = NULL;
        ListNode *sorted_head = NULL;
        
        for (ListNode *ptr = head; ptr; ptr = ptr->next) {
            if (ptr->val < x) {
                if (smaller_head) {
                    smaller_tail->next = ptr;
                } else {
                    smaller_head = ptr;
                }
                smaller_tail = ptr;
            } else {
                if (greater_head) {
                    greater_tail->next = ptr;
                } else {
                    greater_head = ptr;
                }
                greater_tail = ptr;
            }
        }
        
        if (smaller_head) {
            sorted_head = smaller_head;
            smaller_tail->next = greater_head;
        } else {
            sorted_head = greater_head;
        }
        
        //[ATTENTION!] since the tail of the original list can be the smaller_tail rather than greater_tail
        //so greater_tail->next may not point to NULL
        if (greater_tail) {
            greater_tail->next = NULL;
        }
        
        return sorted_head;
    }
};
