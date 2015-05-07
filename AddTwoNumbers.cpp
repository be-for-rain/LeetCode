/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 * My Solution:
 *		[0] convert each list to an unsigned long long
 *		[1] add these two numbers up
 *		[2] convert the number back to a list
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
    unsigned long long ListToNum(ListNode *l) {
        unsigned long long result = 0;
        unsigned long long x = 1;
        for (ListNode *p = l; p; p = p->next) {
            result += x * p->val;
            x = x * 10;
        }
        return result;
    }
    
    ListNode *numToList(unsigned long long num) {
        ListNode *ans=NULL, *ptr=NULL;
        unsigned long long digit = num % 10;
        ans = new ListNode(digit);
        ptr = ans;
        num = num / 10;
        while (num) {
            unsigned long long digit = num % 10;
            ListNode *new_node = new ListNode(digit);
            ptr->next = new_node;
            ptr = ptr->next;
            num /= 10;
        }
        return ans;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        unsigned long long num1 = ListToNum(l1);
        unsigned long long num2 = ListToNum(l2);
        unsigned long long ans_num = num1 + num2;
        ListNode *ans_list = numToList(ans_num);
        return ans_list;
    }
};
