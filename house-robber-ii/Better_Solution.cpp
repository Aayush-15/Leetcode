class Solution {
public:
    int money_collected(vector<int>A)
    {
        int n = A.size();
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0; //Not Considering thiws element
        dp[0][1] = A[0]; //Considering Current Element
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + A[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<int>A = vector<int>(nums.begin(), nums.end() - 1);
        vector<int>B = vector<int>(nums.begin() + 1, nums.end());
        int ans1 = money_collected(A);
        int ans2 = money_collected(B);
        int ans = max(ans1, ans2);
        return ans;
    }
};