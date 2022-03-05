class Solution {
public:
	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums)
	{
		map<pair<int, int>, int>res;
		vector<pair<int, int>>vp;
		for (int i = 0; i < nums.size(); i++)
		{
			string curr = to_string(nums[i]);
			int tmp = nums[i];
			for (int j = 0; j < curr.size(); j++)
			{
				int cur = curr[j] - '0';
				int mpp = mapping[cur];
				curr[j] = mpp + '0';
			}
			int new_ = stoi(curr);
			vp.push_back({new_, i});
			res[ {new_, i}] = tmp;
		}
		sort(vp.begin(), vp.end());
		vector<int>ans;
		for (int i = 0; i < vp.size(); i++)
		{
			int curr = res[ {vp[i].first, vp[i].second}];
			ans.push_back(curr);
		}
		return ans;
	}
};