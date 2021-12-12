class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int array_sum=0;
        for(auto x:nums)
        {
            array_sum+=x;
        }
        if(array_sum%2)
        {
            return 0;
        }
        //Now we will have to find such a subset whose sum is equal to 
        //(array_sum/2) then another subset wil automatically have this sum(Array_sum/2)
        //This Problem has been reduced to subset sum problem where we
        //Just have to find out if there is any subset present with given sum
        int req_sum=(array_sum)/2;
        int dp[n+1][req_sum+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=req_sum;j++)
            {
                if(j==0)
                {
                    //j==0-->>Required sum=0
                    //If Required sum is equal to zero which is always possible->empty subset
                    dp[i][j]=1;
                    continue;
                }
                if(i==0)
                {
                    //i==0 -->Subset is empty and its sum can not be greater than zero
                    dp[i][j]=0;
                    continue;
                }
                if(j>=nums[i-1])
                {
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
                
            }
            
            
        }
        return (bool)dp[n][req_sum];
    }
};