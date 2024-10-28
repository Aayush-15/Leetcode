class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[i][0]->Maximum Amount of Money YOu Can ROb Not robbing the Current House
        //dp[i][1]->Maximum Amount of money YOu Can rob Robbing the Current House
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2,0));

        dp[0][1]=nums[0];
        dp[0][0]=0;
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]+nums[i],dp[i-1][1]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
        
    }
};