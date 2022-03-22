class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        map<int,char>mp;
        char x='a';
        for(int i=1;i<=26;i++)
        {
            mp[i]=x;
            x++;
        }
        string str="";
        int rem=k;
        while(n>0)
        {
            int max_curr=(rem-n+1);
            max_curr=min(max_curr,26);
            char x=mp[max_curr];
            rem-=max_curr;
            //cout<<max_curr<<" "<<rem<<'\n';
            str+=x;
            
            n--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};