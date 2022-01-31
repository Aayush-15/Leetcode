class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int global_max=0;
        for(auto x:accounts)
        {
            int curr_max=0;
            for(auto y:x)
            {
                curr_max+=y;
            }
            global_max=max(global_max,curr_max);
        }
        return global_max;
    }
};