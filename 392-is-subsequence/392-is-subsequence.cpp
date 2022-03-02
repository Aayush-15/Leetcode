class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        bool ans=true;
        int i=0;
        int j=0;
        while(i<s.size() and j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(i!=s.size())
        {
            ans=false;
            
        }
        return ans;
    }
};