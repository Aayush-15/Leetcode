class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int n=matrix.size();int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        //Dp[i][j]->The Lengrth Of the Maximum Square Whose Bottom Right Corner is (i,j)
        
        //Recurrance:  dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int left=0;
                int upper=0;
                int diagonal_left=0;
                if(matrix[i][j]=='1')
                {
                    if(i-1>=0)
                    {
                        left=dp[i-1][j];
                    }
                    if(j-1>=0)
                    {
                        upper=dp[i][j-1];
                    }
                    if(i-1>=0 and j-1>=0)
                    {
                        diagonal_left=dp[i-1][j-1];
                    }
                    dp[i][j]=min({left,upper,diagonal_left})+1;
                    //cout<<dp[i][j]<<'\n';
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans*ans;
        
        
    }
};