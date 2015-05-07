/*
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space?
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
    ListNode *getMeetPoint(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && slow) {
            if (fast->next) {
                fast = fast->next->next;
            } else {
                return NULL;
            }
            slow = slow->next;
            if (fast == slow) {
                return fast;
            }
        }
        return NULL;
    }
    
    ListNode *getMeetPoint(ListNode *a, ListNode *b) {
        ListNode *p = a, *q = b;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
    

    ListNode *detectCycle(ListNode *head) {
        ListNode *meet = getMeetPoint(head);
        if (meet) {
            return getMeetPoint(meet, head);
        } else {
            return NULL;
        }
        
    }
};
