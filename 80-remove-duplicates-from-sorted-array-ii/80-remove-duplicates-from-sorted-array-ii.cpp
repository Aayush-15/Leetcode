class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size()<2)
        {
            return nums.size();
        }
        int curr_pointer=2;
        int forward_pointer=2;
        while(forward_pointer<nums.size())
        {
            if(nums[curr_pointer-2]!=nums[forward_pointer])
            {
                
                nums[curr_pointer]=nums[forward_pointer];
                curr_pointer++;
               
            }
            forward_pointer++;
            
        }
        return curr_pointer;
    }
};