
class Solution {
public:
	int minimumNumbers(int num, int k)
	{
		vector<int>coins;
		for (int i = 0; i <= num; i++)
		{
			if (i % 10 == k)
			{
				coins.push_back(i);
			}
		}
		int target = num;
		vector<int>dp(target + 1, -1);
		int n = coins.size();
		for (int i = 0; i < n; i++)
		{
			if (coins[i] <= target)
			{
				dp[coins[i]] = 1;
			}
		}
		for (int i = 1; i <= target; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i - coins[j] > 0)
				{
					if (dp[i - coins[j]] != -1)
					{
						//dp[i] = min(1 + dp[i - coins[j]], dp[i]);
						if (dp[i] == -1)
						{
							dp[i] = 1 + dp[i - coins[j]];
						}
						else
						{
							dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
						}
					}
				}
			}
		}
		if (target == 0)
		{
			return 0;
		}
		return dp[target];
	}
};