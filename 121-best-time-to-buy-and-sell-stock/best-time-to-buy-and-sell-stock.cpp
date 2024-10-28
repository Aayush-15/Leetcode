class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest=prices[0];
        int ans=0;
        for(auto x:prices){
            ans=max(ans,x-cheapest);
            cheapest=min(x,cheapest);
        }
        return ans;


        
    }
};