class Solution {
public:
    int maxPower(string s) 
    {
        int ans=0;
        for(int i=0;i<s.length();)
        {
            char curr=s[i];
            int curr_ans=0;
            while(i<s.length() and s[i]==curr)
            {
                i++;
                curr_ans++;
            }
            ans=max(ans,curr_ans);
        }
        return ans;
    }
};