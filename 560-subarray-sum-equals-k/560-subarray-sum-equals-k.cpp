class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int result = 0;
    int sum = 0; 
    unordered_map<int, int> values; 
    values[0]++;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i]; 
           if (values[sum - k])
           {
            result += values[sum - k];
           } 
         values[sum]++;
    }
        
        
    return result;
        
    }
};