class Solution {
public:
	void permute(int ind, string pattern, vector<int>&used, vector<int>&ans, vector<int>&ress, vector<int>&ans_mini)
	{
		if (ind == pattern.size())
		{
			ress = ans;
			ans_mini = min(ans_mini, ress);
			return;
		}
		int curr = ans[ind];
		if (pattern[ind] == 'I')
		{
			
			for (int j = curr + 1; j < 10; j++)
			{
				if (used[j] == 0)
				{
					used[j] = 1;
					ans[ind + 1] = j;
					permute(ind + 1, pattern, used, ans, ress, ans_mini);
					used[j] = 0;
					ans[ind + 1] = 0;
				}
			}
		}
		else if (pattern[ind] == 'D')
		{
			for (int j = curr - 1; j > 0; j--)
			{
				if (used[j] == 0)
				{
					used[j] = 1;
					ans[ind + 1] = j;
					permute(ind + 1, pattern, used, ans, ress, ans_mini);
					used[j] = 0;
					ans[ind + 1] = 0;
				}
			}
		}
	}
	string smallestNumber(string pattern) {
		int n = pattern.size();
		vector<int>ans(n + 1, 0);
		vector<int>used(10, 0);
		vector<int>ress(n + 1, 9);
		vector<int>ans_mini(n + 1, 9);
		for (int i = 1; i <= 9; i++)
		{
			int yy = i;
			ans[0] = yy;
			used[yy] = 1;
			permute(0, pattern, used, ans, ress, ans_mini);
			ans[0] = 0;
			used[yy] = 0;
			
		}
		string return_res = "";
		for (auto x : ans_mini)
		{
			char xx = x + '0';
			return_res += xx;
		}
		return return_res;

	}
};