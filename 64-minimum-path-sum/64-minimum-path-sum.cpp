class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==j and i==0)
                {
                    continue;
                }
                int poss1=INT_MAX;
                if(i-1>=0)
                {
                    if(dp[i-1][j]==INT_MAX)
                    {
                        
                    }
                    else
                    {
                        poss1=dp[i-1][j]+grid[i][j];
                    }
                }
                int poss2=INT_MAX;
                if(j-1>=0)
                {
                    if(dp[i][j-1]==INT_MAX)
                    {
                        
                    }
                    else
                    {
                        poss2=dp[i][j-1]+grid[i][j];
                    }
                }
                dp[i][j]=min(poss1,poss2);
            }
            
        }
        return dp[n-1][m-1];
    }
};