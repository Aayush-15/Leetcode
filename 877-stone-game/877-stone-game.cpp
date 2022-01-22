class Solution {
public:
    //This Function will try to maximize value for Alice
    int helper(int l,int r,vector<vector<int>>&dp,vector<int>&piles)
    {
        if(l == r-1) return max(piles[l], piles[r]);
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        int ifleft=piles[l]+max(helper(l+2,r,dp,piles),helper(l+1,r-1,dp,piles));
        int ifright=piles[r]+max(helper(l,r-2,dp,piles),helper(l+1,r-1,dp,piles));
        return dp[l][r]=max(ifleft,ifright);
    }
    bool stoneGame(vector<int>& piles) 
    {
        int sz=piles.size();
        int l=0;
        int r=sz-1;
        vector<vector<int>>dp(sz,vector<int>(sz,-1));
        int alice=helper(l,r,dp,piles);
        int total_sum=0;
        for(auto x:piles)
        {
            total_sum+=(x);
        }
        int bob=total_sum-alice;
        return alice>bob;
    }
};