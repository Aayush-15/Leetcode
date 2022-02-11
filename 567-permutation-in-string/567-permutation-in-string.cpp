class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.length()>s2.length())
        {
            return false;
        }
        map<char,int>mp1;
        for(auto x:s1)
        {
            mp1[x]++;
        }
        map<char,int>mp2;
        int len=s1.length();
        for(int i=0;i<len;i++)
        {
            mp2[s2[i]]++;
        }
        int count=0;
        if(mp1==mp2)
        {
            count++;
        }
        for(int i=len;i<s2.length();i++)
        {
            mp2[s2[i]]++;
            if(mp2[s2[i-len]]==1)
            {
                mp2.erase(mp2.find(s2[i-len]));
            }
            else
            {
                mp2[s2[i-len]]--;
            }
            if(mp1==mp2)
            {
                count++;
            }
        }
        return count;
    }
};