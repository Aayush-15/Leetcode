class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        vector<int>lis;
	    lis.push_back(nums[0]);
	    for (int i = 1; i < nums.size(); i++)
	    {
		    int sz = lis.size();
		    if (lis[sz - 1] < nums[i])
		    {
			    lis.push_back(nums[i]);
		    }
		    else
		    {
			    auto pos = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
			    lis[pos] = nums[i];
		    }
	    }
	    return lis.size()>=3;    
    }
};