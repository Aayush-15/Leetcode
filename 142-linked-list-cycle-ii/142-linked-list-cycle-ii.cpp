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
     ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        
        while(slow!=NULL && fast!=NULL && fast->next!=NULL) {
            
            slow = slow->next;               //Slow moves by 1 step
            fast = fast->next->next;        //Fast moves by two steps
            
            //If they meet then there is a loop
            if(slow==fast) 
            {
                //To find the starting element where the loop starts
                fast = fast;
                slow = head;
                while(slow!=fast) 
                {
                    //Both move by 1 step
                    slow = slow->next;
                    fast=fast->next;
                }
                return slow;
                
            }
 
        }
        
        return NULL; //No loop
    }
};