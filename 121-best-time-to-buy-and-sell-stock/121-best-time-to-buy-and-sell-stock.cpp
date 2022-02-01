class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int cheapest=prices[0];
        int max_profit=0;
        for(int i=1;i<n;i++)
        {
            if(prices[i]<cheapest)
            {
                cheapest=prices[i];
            }
            else
            {
                max_profit=max(max_profit,prices[i]-cheapest);
            }
        }
        return max_profit;
    }
};