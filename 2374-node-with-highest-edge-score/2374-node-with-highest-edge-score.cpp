
class Solution {
public:
	int edgeScore(vector<int>& edges) {
		int n = edges.size();
		vector<vector<int>>Graph(n, vector<int>());
		int nn = 0;
		for (auto x : edges)
		{
			Graph[x].push_back(nn);
			nn++;
		}
		nn = 0;
		// for (auto x : Graph)
		// {
		// 	cout << nn++ << ":";
		// 	for (auto y : x)
		// 	{
		// 		cout << y << " ";
		// 	}
		// 	cout << '\n';
		// }
		vector<long long>ans;
		for (auto x : Graph)
		{
			long long curr_ans = 0;
			for (auto y : x)
			{
				curr_ans += (long long)y;
			}
			ans.push_back(curr_ans);
		}
		long long maxi = -1; int ind = 0;
		for (int i = 0; i < ans.size(); i++)
		{
			if (ans[i] > maxi)
			{
				maxi = ans[i];
				ind = i;
			}
		}
		return ind;
	}
};