class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        map<char,int>mp;
        for(auto x:s)
        {
            mp[x]++;
        }
        for(auto x:t)
        {
            mp[x]--;
        }
        char ans;
        for(auto x:mp)
        {
            if(x.second==-1)
            {
                ans=x.first;
            }
        }
        return ans;
    }
};