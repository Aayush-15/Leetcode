//aaabb
// _a _ b_ a_b _a
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto x:s){
            mp[x]++;
        }

        priority_queue<pair<int,char>>pq;
        
        for(auto x:mp){
            pq.push({x.second,x.first});
        }

        int idx=0;
        while(idx<s.size() && pq.size()>0){
            auto curr_top=pq.top();
            pq.pop();
            // cout<<curr_top.first<<" "<<curr_top.second<<" "<<idx<<endl;
            if(pq.size()==0){
                if(idx+1<s.size()){
                    return "";
                }
                else{
                    s[idx]=curr_top.second;
                    return s;
                }
            }
            auto second_top=pq.top();
            pq.pop();
            // cout<<second_top.first<<" "<<second_top.second<<" "<<idx<<endl;
            s[idx]=curr_top.second;
            s[idx+1]=second_top.second;
            idx+=2;
            if(curr_top.first>1){
                pq.push({curr_top.first-1,curr_top.second});
            }
            if(second_top.first>1){
                pq.push({second_top.first-1,second_top.second});
            }
        }
        if(idx<s.size()){
            return "";
        }
        return s;



    }
};