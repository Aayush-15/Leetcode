class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        map<string,int>mp;
        int count=0;
        for(auto x:words)
        {
            string yy=x;
            reverse(yy.begin(),yy.end());
            if(mp[yy]==1)
            {
                count+=4;
                mp.erase(mp.find(yy));
            }
            else if(mp[yy]>1)
            {
                count+=4;
                mp[yy]--;
            }
            else
            {
                mp[x]++;
            }
        }
        bool ok=false;
        for(auto x:mp){
            string str=x.first;
            if(str[0]==str[1] and ok==false){
                count+=2;
                ok=true;
            }
        }
        return count;
    }
};