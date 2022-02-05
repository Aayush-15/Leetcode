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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        vector<int>values;
        for(auto x:lists)
        {
              while(x)
              {
                  values.push_back(x->val);
                  x=x->next;
              }
        }
        sort(values.begin(),values.end());
        if(values.size()==0)
        {
            return NULL;
        }
        ListNode* head=new ListNode(values[0]);
        ListNode* curr=head;
        for(int i=1;i<values.size();i++)
        {
            curr->next=new ListNode(values[i]);
            curr=curr->next;
        }
        return head;
    }
};