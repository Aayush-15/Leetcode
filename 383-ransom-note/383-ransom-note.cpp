class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        vector<int>magazine_(26,0),ransomNote_(26,0);
        for(auto x:magazine)
        {
            magazine_[x-'a']++;
        }
        for(auto x:ransomNote)
        {
            ransomNote_[x-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(ransomNote_[i]>magazine_[i])
                return false;
        }
return true;
    }
};