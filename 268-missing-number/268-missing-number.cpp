class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int xor_val = 0, i = 0;
	    for (i = 0; i < nums.size(); i++) {
		    xor_val = xor_val ^ i ^ nums[i];
	    }

	     return xor_val ^ i;
    }
};