class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        int index=-1;
        for(int i=s.length()-1;i>=0;i--)
        {
            mp[s[i]]++;
        }
        for(int i=s.length()-1;i>=0;i--)
        {
            if(mp[s[i]]==1)
            {
                index=i;
            }
        }
return index;
        
    }
};