class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        bool ok=true;
        vector<string>S;
        string tmp="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' '||i==s.length()-1)
            {
                if(s[i]!=' ')
                {
                    tmp+=s[i];
                }
                S.push_back(tmp);
                tmp="";
            }
            else
            {
                tmp+=s[i];
            }
        }
        // for(auto x:S)
        // {
        //     cout<<x<<'\n';
        // }
        // return true;
         
        map<char,string>mp;
        set<string>ss;
       // cout<<s.size()<<'\n';
        if(S.size()!=pattern.length())
        {
            return false;
        }
        
        for(int i=0;i<pattern.length();i++)
        {
            if(mp.count(pattern[i]))
            {
                if(mp[pattern[i]]!=S[i])
                {
                    ok=false;
                    break;
                }
            }
            else
            {
                mp[pattern[i]]=S[i];
            }
        }
        for(auto x:mp)
        {
            ss.insert(x.second);
        }
        if(ss.size()!=mp.size())
        {
            ok=false;
        }
       
        return ok;
    }
};