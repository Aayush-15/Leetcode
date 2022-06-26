class Solution {
public:
    //Kadane
	int maxSubArray(vector<int>& nums) {
		int curMax = 0, maxTillNow = INT_MIN;
		for (auto c : nums)
			curMax = max(c, curMax + c),
			maxTillNow = max(maxTillNow, curMax);
		return maxTillNow;
	}
	int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
		vector<int>diff1(nums1.size(), 0);
		for (int i = 0; i < nums1.size(); i++)
		{
			diff1[i] = nums1[i] - nums2[i];
		}
		int max_increase1 = maxSubArray(diff1);
		int array1_sum = 0, array2_sum = 0;
		for (auto x : nums1)
		{
			array1_sum += x;
		}
		for (auto x : nums2)
		{
			array2_sum += x;
		}
		// debug(max_increase1);
		vector<int>diff2(nums1.size(), 0);
		for (int i = 0; i < nums1.size(); i++)
		{
			diff2[i] = nums2[i] - nums1[i];
		}
		int max_increase2 = maxSubArray(diff2);
		// debug(max_increase2);
		int ans = max(max(array1_sum, array2_sum + max_increase1), max(array1_sum + max_increase2, array2_sum));
		return ans;
		return 0;
	}
};