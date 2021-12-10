class Solution {
public:
    //Binary Search on Answer
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.size() == 0)
        {
            return { -1, -1};
        }

        int left = 0;
        int right = nums.size() - 1;
        int ans1 = -1;
        //Finding First Occurance of An Element
        // T T T T T F F F F F
        //Have to Find Last True
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target)
            {

                left = mid + 1;

            }
            else
            {
                if (nums[mid] == target)
                {
                    ans1 = mid;
                }
                right = mid - 1;
            }
        }
        //Finding Last Occurance of An Element
        // F F F F F T T T T
        //Have to Find First True
        left = 0;
        right = nums.size() - 1;
        int ans2 = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {

                right = mid - 1;

            }
            else
            {
                if (nums[mid] == target)
                {
                    ans2 = mid;
                }
                left = mid + 1;
            }
        }
        return {ans1, ans2};

    }
};