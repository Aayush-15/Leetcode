class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        int n=s.size();
        vector<string>ans;
        for(int i=0;i<n;i+=k)
        {
            if(i+k<n)
            {
                vector<char>tmp;
                for(int j=i;j<i+k;j++)
                {
                    tmp.push_back(s[j]);
                }
                string t="";
                for(auto x:tmp)
                {
                    t+=x;
                }
                ans.push_back(t);
            }
            else
            {
                vector<char>tmp;
                for(int j=i;j<n;j++)
                {
                    tmp.push_back(s[j]);
                }
                while(tmp.size()<k)
                {
                    tmp.push_back(fill);
                }
                string t="";
                for(auto x:tmp)
                {
                    t+=x;
                }
                ans.push_back(t);
            }
        }
        return ans;
    }
};