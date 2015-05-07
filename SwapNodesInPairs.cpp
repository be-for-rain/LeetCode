/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 *
 *
 *
 * Sol:
 *		minor probleam of Reverse Nodes In K Groups (k == 2)
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
   void reverse(ListNode *&head, ListNode *&tail, int k) {
         if (head == NULL || k == 1) {
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
 
    ListNode *reverseKGroupSub(ListNode *&head, int k) {
        if (head == NULL || k  == 0) {
            return head;
        }
        ListNode *tail = NULL;
        reverse(head, tail, k);
        if (tail) {
            reverseKGroupSub(tail->next, k);
        }
        return head;
    }
 
    ListNode *swapPairs(ListNode *head) {
        return reverseKGroupSub(head, 2);
    }
};
