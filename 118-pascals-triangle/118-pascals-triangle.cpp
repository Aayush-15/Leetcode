class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        int n=numRows;
        vector<vector<int>>ans;
        
        for(int i=1;i<=n;i++)
        {
            if(i==1)
            {
                vector<int>tmp={1};
                ans.push_back(tmp);
                cout<<ans.size()<<'\n';
                continue;
            }
            if(i==2)
            {
                vector<int>tmp={1,1};
                ans.push_back(tmp);
            
                continue;
            }
            vector<int>prev=ans[ans.size()-1];
           
            vector<int>curr(i,0);

            for(int j=0;j<i;j++)
            {
                if(j==0||j==i-1)
                {
                    curr[j]=1;
                    continue;
                }
                curr[j]=prev[j]+prev[j-1];
            }
            ans.push_back(curr);
            
        }
        return ans;
    }
};