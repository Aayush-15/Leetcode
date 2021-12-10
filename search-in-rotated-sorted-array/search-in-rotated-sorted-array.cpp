class Solution {
public:
    //Distinct Values In the array 
    //Since the array is rotated only once
    //So if we go on any particular index and look at the left and right side of
    //The array we observe that atleast one side of the array is Sorted
    int search(vector<int>& nums, int target)
    {
        int sz=nums.size();
        int l=0;
        int r=sz-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                break;
            }
            //Left Segment Is Sorted
            if(nums[mid]>=nums[l])
            {
                //Targhet Element should be on left segment
                if(target>=nums[l]&&target<=nums[mid])
                {
                    r=mid-1;
                }
                //Target should be on right segment
                else
                {
                    l=mid+1;
                }
            }
            //Right Segment Is Sorted
            else
            {
                //Target should be on Right Segment
                if(target>=nums[mid]&&target<=nums[r])
                {
                    l=mid+1;
                }
                //Target should be on Left Segment
                else
                {
                    r=mid-1;
                }
            }
        }
        return ans;
    }
};