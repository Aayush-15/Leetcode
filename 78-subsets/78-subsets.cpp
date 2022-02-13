class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums,int curr_,int n,vector<int>&curr_subset)
    {
        if(curr_==n)
        {
            ans.push_back(curr_subset);
            return;
        }
        //For every Element we have 2 Choice , Include it is subset or do not include
        helper(nums,curr_+1,n,curr_subset);
        curr_subset.push_back(nums[curr_]);
        helper(nums,curr_+1,n,curr_subset);
        curr_subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int>curr_subset;
        helper(nums,0,nums.size(),curr_subset);
        return ans;
    }
};