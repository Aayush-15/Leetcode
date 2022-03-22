class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string str="";
        int rem=k;
        while(n>0)
        {
            int max_curr=(rem-n+1);
            max_curr=min(max_curr,26);
            char x='a'+max_curr-1;
            rem-=max_curr;
            //cout<<max_curr<<" "<<rem<<'\n';
            str+=x;
            
            n--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};