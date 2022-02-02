class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        map<char,int>mp1,mp2;
        for(auto x:p)
        {
            mp2[x]++;
            
        }
        
        for(int i=0;i<p.size();i++)
        {
            mp1[s[i]]++;
        }
        int left=0;
        int right=p.size()-1;
        vector<int>index;
        
        while(right<s.size())
        {
            // cout<<left<<" "<<right<<'\n';
            // for(auto x:mp1)
            // {
            //     cout<<x.first<<" "<<x.second<<'\n';
            // }
            // cout<<".."<<'\n';
            // for(auto x:mp2)
            // {
            //     cout<<x.first<<" "<<x.second<<'\n';
            // }
            if(mp1==mp2)
            {
                index.push_back(left);
            }
            if(mp1[s[left]]==1)
            {
                mp1.erase(mp1.find(s[left]));
            }
            else
            {
                mp1[s[left]]--;
            }
            left++;
            right++;
            if(right==s.size())
            {
                break;
            }
            mp1[s[right]]++;
            
        }
        
        return index;
        
        
    }
};