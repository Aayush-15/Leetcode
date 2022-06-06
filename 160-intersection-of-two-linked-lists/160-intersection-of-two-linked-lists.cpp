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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==nullptr || headB==nullptr)
        {
            return NULL;
        }
        ListNode* first_ptr;
        ListNode* second_ptr;
        first_ptr=headA;
        second_ptr=headB;
        while(first_ptr!=second_ptr)
        {
            first_ptr=first_ptr==NULL?headB:first_ptr->next;
            second_ptr=second_ptr==NULL?headA:second_ptr->next;
        }
        return first_ptr;
    }
};