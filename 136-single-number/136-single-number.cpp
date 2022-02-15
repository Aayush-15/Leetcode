class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int missing=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            missing=missing^nums[i];
        }
        return missing;
    }
};