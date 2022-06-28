class Solution {
public:
	int timer = 0;
	void precalculate(vector<vector<int>>&adj, vector<int>&pre, int node, int par, vector<int>&nums, vector<int>&parent, vector<int>&inTime, vector<int>&outTime)
	{
		int curr_val = nums[node];
		parent[node] = par;
		inTime[node] = timer++;

		for (auto x : adj[node])
		{
			if (x == par)
			{
				continue;
			}
			precalculate(adj, pre, x, node, nums, parent, inTime, outTime);
			curr_val = curr_val ^ pre[x];
		}

		outTime[node] = timer++;

		pre[node] = curr_val;
	}
	int minimumScore(vector<int>& nums, vector<vector<int>>& edges)
	{
		int nodes = nums.size();
		vector<vector<int>>adj(nodes, vector<int>());
		vector<int>pre(nodes, 0);//Storing Xor Values Tree Wise
		vector<int>inTime(nodes, 0);
		vector<int>outTime(nodes, 0);
		vector<int>parent(nodes, -1);
		for (auto x : edges)
		{
			int yy = x[0];
			int zz = x[1];
			adj[yy].push_back(zz);
			adj[zz].push_back(yy);
		}
		precalculate(adj, pre, 0, -1, nums, parent, inTime, outTime);
		for (auto &x : edges)
		{
			if (parent[x[1]] != x[0])
			{
				swap(x[0], x[1]);
			}
		}
		int res= INT_MAX;
		for (int i = 0; i < nodes - 1; i++)
		{
			for (int j = i + 1; j < nodes - 1; j++)
			{
				int n1 = edges[i][1];
				int n2 = edges[j][1];
				//n1 is in the subtree of n2
				if (inTime[n2] < inTime[n1] && outTime[n1] < outTime[n2])
				{
					int a = pre[n1];
					int b = (pre[n2] ^ pre[n1]);
					int c = (pre[0] ^ pre[n2]);
					res = min(res, max({a, b, c}) - min({a, b, c}));
				}
				// n2 is in subtree of n1
				else if (inTime[n1] < inTime[n2] && outTime[n2] < outTime[n1])
				{
					int a = pre[n2];
					int b = (pre[n1] ^ pre[n2]);
					int c = (pre[0] ^ pre[n1]);
					res = min(res, max({a, b, c}) - min({a, b, c}));
				}
				// n1 & n2 are separate
				else
				{
					int a = pre[n1];
					int b = pre[n2];
					int c = (pre[0] ^ pre[n1] ^ pre[n2]);
					res = min(res, max({a, b, c}) - min({a, b, c}));
				}

			}
		}
		// debug(res);
		return res;
		// debug(pre);
		return 0;
	}
};