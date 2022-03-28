class Solution {
public:
    //The Problem is different at just one point
    // When We get first and last element same
    /*
    I figured, that the only real scenario we should look out for is when we're given an array
where the first element == last element like in the following: 2, 5, 6, 0, 0, 1, 2 .
Then we can just shrink our array on both sides, the left and the right, so that we could just perform the regular binary search on a rotated array algorithm.
It would give us this array: 5, 6, 0, 0, 1 to work with.

O(n) worst but O(logn) average.
    */
    bool search(vector<int>& nums, int target)
    {
        int sz=nums.size();
        int l=0;
        int r=sz-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            while(l < r && nums[l] == nums[r]) {
            if(nums[l] == target) {
                return true;
            }
            l++;
                r--;
            }
            if(nums[mid]==target)
            {
                return true;
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
       return false;
    }
};