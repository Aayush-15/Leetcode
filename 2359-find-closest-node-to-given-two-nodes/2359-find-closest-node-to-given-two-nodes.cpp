class Solution {
	void dfs(int node, int depth, vector<vector<int>>&graph, vector<int>&dist, vector<int>&vis)
	{
		if (vis[node])
		{
			return;
		}
		vis[node] = 1;
		dist[node] = depth;
		for (auto child : graph[node])
		{
			// if (vis[child] == 0)
			{
				dfs(child, depth + 1, graph, dist, vis);
			}
		}

	}
public:

	int closestMeetingNode(vector<int>& edges, int node1, int node2)
	{
		int n = edges.size();
		vector<vector<int>>Graph(n, vector<int>());
		vector<int>dist1(n, -1), dist2(n, -1);
		vector<int>vis1(n, 0), vis2(n, 0);
		int cnt = 0;
		for (auto x : edges)
		{
			if (x != -1) {
				Graph[cnt].push_back(x);
			}
			cnt++;

		}
		cnt = 0;
		// for (auto x : Graph)
		// {
		// 	cout << cnt << ": ";
		// 	for (auto y : x)
		// 		cout << y << " ";
		// 	cout << '\n';
		// 	cnt++;
		// }
		int ans = 1e8;
		int ans_node = -1;
		dfs(node1, 0, Graph, dist1, vis1);
		dfs(node2, 0, Graph, dist2, vis2);
		for (int i = 0; i < n; i++)
		{
			if (dist1[i] >= 0 and dist2[i] >= 0)
			{
				// ans = min(ans, max(dist1[i], dist2[i]));
				if (max(dist1[i], dist2[i]) < ans)
				{
					ans = max(dist1[i], dist2[i]);
					ans_node = i;
				}
			}
		}
		return ans_node;
	}
};
