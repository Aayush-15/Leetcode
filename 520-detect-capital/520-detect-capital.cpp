class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        bool ok=true;
        for(auto x:word)
        {
            ok = ok and (x>='A' and x<='Z');
        }
        if(ok)
        {
            return 1;
        }
        ok=true;
        for(int i=0;i<word.size();i++)
        {
            if(i==0)
            {
                if(word[i]>='A' and word[i]<='Z')
                {
                    
                }
                else
                {
                    ok=false;
                }
            }
            else
            {
                if(word[i]>='a' and word[i]<='z')
                {
                    
                }
                else
                {
                    ok=false;
                }
            }
        }
        if(ok)
        {
            return 1;
        }
        ok=true;
        for(auto x:word)
        {
            ok = ok and (x>='a' and x<='z');
        }
        if(ok)
        {
            return 1;
        }
        return 0;
    }
};