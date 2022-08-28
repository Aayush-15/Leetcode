class Solution {
public:
	vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
		int n = k;
		vector<vector<int>>res(n, vector<int>(n, 0));
		vector<vector<int>>row_(n + 1, vector<int>(n + 1, 0));
		vector<vector<int>>col_(n + 1, vector<int>(n + 1, 0));
		vector<int>Indegree(n + 1, 0), Indegree2(n + 1, 0);
		bool ok1 = true, ok2 = true;
		for (int i = 0; i < rowConditions.size(); i++)
		{
			int to, from;
			to = rowConditions[i][1];
			from = rowConditions[i][0];
			row_[from].push_back(to);
			Indegree[to]++;
		}
		queue<int>que;
		for (int i = 1; i <= n; i++)
		{
			if (Indegree[i] == 0)
			{
				que.push(i);
			}
		}
		vector<int>ans;
		while (!que.empty())
		{
			int curr = que.front();
			que.pop();
			ans.push_back(curr);
			for (auto x : row_[curr])
			{
				Indegree[x]--;
				if (Indegree[x] == 0)
				{
					que.push(x);
				}
			}
		}
		map<int, int>row_ind, col_ind;
		if (ans.size() == n)
		{

			int ind = 0;
			for (int i = 0; i < ans.size(); i++)
			{
				int curr_node = ans[i];
				row_ind[curr_node] = ind++;
			}
		}
		else
		{
			ok1 = false;
		}
		if (ok1 == false)
			return vector<vector<int>>();


		for (int i = 0; i < colConditions.size(); i++)
		{
			int to, from;
			to = colConditions[i][1];
			from = colConditions[i][0];
			col_[from].push_back(to);
			Indegree2[to]++;
		}
		while (que.size() > 0)
		{
			que.pop();
		}
		for (int i = 1; i <= n; i++)
		{
			if (Indegree2[i] == 0)
			{
				que.push(i);
			}
		}
		ans.clear();
		while (!que.empty())
		{
			int curr = que.front();
			que.pop();
			ans.push_back(curr);
			for (auto x : col_[curr])
			{
				Indegree2[x]--;
				if (Indegree2[x] == 0)
				{
					que.push(x);
				}
			}
		}
		if (ans.size() == n)
		{
			int ind = 0;
			for (int i = 0; i < ans.size(); i++)
			{
				int curr_node = ans[i];
				col_ind[curr_node] = ind++;
			}
		}
		else
		{
			ok2 = false;
		}
		if (ok2 == false)
			return vector<vector<int>>();

		for (int i = 1; i <= n; i++)
		{
			int row___ = row_ind[i];
			int col___ = col_ind[i];
			res[row___][col___] = i;
		}
		return res;
	}
};
