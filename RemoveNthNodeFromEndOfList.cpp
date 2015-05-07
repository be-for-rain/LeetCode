/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *       After removing the second node from the end, the linked list becomes 1->2->3->5.
 *       Note:
 *       Given n will always be valid.
 *       Try to do this in one pass.
 *
 * Sol:
 *		[0] get a pointer whose distance between the head & this pointer is n
 *		[1] move this pointer & another pointer from head together
 *			when the ed pointer gets the last element of the list,
 *			the st pointer will get the position where its next node should be deleted
 *		[2] delete st->next by set st->next = st->next->next
 *
 *		Special case : delete head
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *ed = head;
        for (int i = 0; i < n; i++) {
            ed = ed->next;
        }
        if (ed == NULL) {   //special case : delete head
            return head->next;
        }
        ListNode *st = head;
        while (ed->next) {
            st = st->next;
            ed = ed->next;
        }
        st->next = st->next->next;
        return head;
    }
};
