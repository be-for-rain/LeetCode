/*
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    //insert a new node right after each original node
    RandomListNode *dupList(RandomListNode *head) {
        for (RandomListNode *p = head; p; p = p->next->next) {
            RandomListNode *dup_p = new RandomListNode(p->label);
            dup_p->next = p->next;
            dup_p->random = p->random;
            p->next = dup_p;
        }
        return head ? head->next : NULL;    //empty list?
    }
    
    void setRandomToNext(RandomListNode *dup_head) {
        for (RandomListNode *p = dup_head; p; p = p->next ? p->next->next : NULL) {
            if (p->random) {
                p->random = p->random->next;
            }
        }
    }
    
    void setNextToNext(RandomListNode *head) {
        for (RandomListNode *p = head; p; p = p->next) {
            RandomListNode *dup_p = p->next;
            p->next = p->next->next;
            if (dup_p->next) {
                dup_p->next = dup_p->next->next;
            }
        }
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *dup_head = dupList(head);
        setRandomToNext(dup_head);
        setNextToNext(head);
        return dup_head;
    }
};
