class Solution {
public:
	int minSwaps(vector<int>& nums)
	{
		//
		int count = 0;
		int index = -1;
		int last = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 1)
			{
				index = i;
				break;
			}
		}
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (nums[i] == 1)
			{
				last = i;
				break;
			}
		}
		if (index == -1 || count == -1 || index == last)
		{
			return 0;
		}

		for (int i = index; i < last; i++)
		{
			if (nums[i] == 0)
			{
				count++;
			}
		}
		int count1 = 0;
		for (int i = 0; i < index; i++)
		{
			if (nums[i] == 0)
			{
				count1++;
			}
		}
		//cout<<count<<'\n';
		for (int i = last; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				count1++;
			}
		}
		count = 0;
		for (auto x : nums)
		{
			if (x == 1)
			{
				count++;
			}
		}
		vector<int>nums_ = nums;
		for (auto x : nums)
		{
			nums_.push_back(x);
		}
		//debug(nums_);
		int sz = count;
		count1 = 0;
		int count2 = 1e9;
		for (int i = 0; i < sz; i++)
		{
			if (nums_[i] == 1)
			{
				count1++;
			}
		}
		//debug(count1);
		//debug(count);
		count2 = min(count2, count - count1);
		int kk = 0;
		for (int i = sz; i < nums_.size(); i++)
		{
			if (nums_[i] == 1)
			{
				count1++;
			}
			if (nums_[kk++] == 1)
			{
				count1--;
			}

			//debug(count1);
			count2 = min(count2, count - count1);
		}

		//count = min(count, count1);
		//return count;
		return count2;
	}
};