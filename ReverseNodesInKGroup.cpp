/*
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 *
 * Sol	:
 *		recursion!!! pass by reference!!
 *
 *
 *		modifying head of the link is a headache? pass by reference!!
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
	//reverse the list starting from head whose length is k
	//change head, tail to the reversed list's head, tail
    void reverse(ListNode *&head, ListNode *&tail, int k) {
         if (head == NULL || k <= 1) {
             tail = head;
             return;
         }
         ListNode *new_head = head->next;
         reverse(new_head, tail, k-1);
         if (tail) {//successfully reversed
            head->next = tail->next; //insert head between tail & tail->next
            tail->next = head;
            tail = head;
            head = new_head;
         }
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
    
    ListNode *reverseKGroup(ListNode *head, int k) {
        return reverseKGroupSub(head, k);
    }
};
