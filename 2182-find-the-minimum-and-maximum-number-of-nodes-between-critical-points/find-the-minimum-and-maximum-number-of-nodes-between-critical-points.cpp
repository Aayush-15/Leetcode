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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>critical_nodes;
        int previous=-1;
        int next=-1;
        int current=-1;
        int pos=0;
        while(head && head->next!=NULL)
        {
            if(previous==-1)
            {
                previous = head->val;
                head=head->next;
                pos++;
            }
            else{
                current = head->val;
                next=head->next->val;

                if(current>previous and current>next)
                {
                    critical_nodes.push_back(pos);
                }
                else if (current<previous and current<next){
                    critical_nodes.push_back(pos);
                }
                previous=current;
                head=head->next;
                
                pos++;
            }
            // cout<<"previous:"<<previous<<" Current:"<<current<<" Next:"<<next<<'\n';
        }
        if(critical_nodes.size()<2)
        {
            critical_nodes={-1,-1};
            
        }
        else
        {
            int len=critical_nodes.size();
            int max_value=critical_nodes[len-1]-critical_nodes[0];
            int min_value=1e6;
            for(int i=1;i<len;i++)
            {
                min_value=min(min_value,critical_nodes[i]-critical_nodes[i-1]);
            }
            critical_nodes={min_value,max_value};
        }

        return critical_nodes;
        
    }
};