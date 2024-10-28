class Solution {
	int recurse(vector<int>&prices, int n, int ind, int fee, int own, vector<vector<int>>&dp) {

		//Base Case
		if (ind >= n) {
			return 0;// I need to break this and I Cannot Make any Further profit
		}
        if(dp[ind][own]!=-1){
            return dp[ind][own];
        }
		int profit = 0;

		if (own == 1) {
			// I am currently Owning A Stock
			// I have 2 options.
			//1.Either Sell the Stock
			//2. Do Nothing
			int option1 = prices[ind] + recurse(prices, n, ind + 1, fee, 0, dp);
			int option2 = recurse(prices, n, ind + 1, fee, own, dp);
			profit = max(option1, option2);

		}
		else if (own == 0) {
			// I am currently Not Owning A Stock
			// I have 2 options.
			//1.Either Buy the Stock
			//2. Do Nothing
			int option1 = -(prices[ind] + fee) + recurse(prices, n, ind + 1, fee, 1, dp);
			int option2 = recurse(prices, n, ind + 1, fee, own, dp);
			profit = max(option1, option2);

		}
		dp[ind][own] = profit;

		return profit;
	}
public:
	//dp[i][0]-> Maximum Profit i can make from Buying And Selling the Stocks such that on ith day i am not currently holding any stock
	//dp[i][1]->Maximum Profit i can make such that on ith day i am not currently holding any stock
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		vector<vector<int>>dp(n, vector<int>(2, -1));
		return recurse(prices, n, 0, fee, 0, dp);


	}
};