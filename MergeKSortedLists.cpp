/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * Sol:
 *		pick up the smallest one each time, insert it to the new list
 *		if can't find the smallest one (candidate == NULL), the old lists are all empty, which means it's time to break
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
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL, *cur = NULL;
        while (true) {
            ListNode *candidate = NULL;
            int index = -1;
            for (unsigned int i = 0; i < lists.size(); ++i) {
                if (shldChooseFormer(lists[i], candidate)) {
                    candidate = lists[i];
                    index = i;
                }
            }
            if (index == -1) {  // all lists are empty
                break;
            }
            if (cur) {
                cur->next = candidate;
                cur = cur->next;
            } else {
                cur = head = candidate;
            }
            lists[index] = candidate->next; 
        }
        return head;
    }
};
