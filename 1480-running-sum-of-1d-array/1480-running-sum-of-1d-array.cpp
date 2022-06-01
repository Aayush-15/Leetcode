class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                continue;
            }
            nums[i]=nums[i-1]+nums[i];
        }
        return nums;
    }
};