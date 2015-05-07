/*
 * Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *sorthead = NULL, *sorttail = NULL;
        while (head) {
            ListNode *minnode = head, *prenode = NULL, *pre_of_min = NULL;
            for (ListNode *x = head; x; prenode = x, x = x->next) {
                if (x->val < minnode->val) {
                    minnode = x;
                    pre_of_min = prenode;
                }
            }

            //remove the minimal node from original list
            if (pre_of_min) {//minnode != head
                pre_of_min->next = minnode->next;
            } else {
                head = head->next;
            }
            
            //insert the minimal node to sorted list
            if (sorttail) { //the sorted list is not empty
                sorttail->next = minnode;
                sorttail = minnode;
            } else {
                sorthead = sorttail = minnode;
            }
            sorttail->next = NULL;
        }
        return sorthead;
    }
};
