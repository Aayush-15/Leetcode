/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total_Node=0;
        ListNode* tmp=head;
        while(tmp!=NULL){
            total_Node++;
            tmp=tmp->next;
        }
        // cout<<total_Node<<'\n';
        if(n==total_Node){
            ListNode* new_head=head->next;
            delete(head);  
            return new_head;
        }
        
        int target_index=total_Node-n;
        int curr_pos=1;
        ListNode* curr_node=head;
        tmp=head;
        while(tmp!=NULL){
            if(curr_pos==target_index){
                tmp->next=tmp->next->next;
                
                return head;
            }
            curr_pos++;
            tmp=tmp->next;
        }
    return head;
    }
};