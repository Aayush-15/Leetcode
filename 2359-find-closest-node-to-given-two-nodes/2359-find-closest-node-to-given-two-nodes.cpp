//JAI SHREE KRISHNA
#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define pii             pair<int,int>
#define F               first
#define S               second
#define pbmax           priority_queue<int>//max heap
#define pbmin           priority_queue<int, vector<int>, greater<int>>//min heap priority_queue
#define lpi(i,a,b)      for(int i=a;i<b;i++)
#define lpd(i,a,b)      for(int i=b;i>=a;i--)
/****************************************************************************************/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" :"; _print(x);cerr<<'\n';
#else
#define debug(x)
#endif
void _print(int a) {cerr << a << " ";}
void _print(long long  a) {cerr << a << " ";}
void _print(char a) {cerr << a << " ";}
void _print(double a) {cerr << a << " ";}
void _print(float a) {cerr << a << " ";}
void _print(string a) { cerr << a << " ";}
template<class T> void _print(vector<T>v) {
	cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template<class T> void _print(set<T>s)
{
	cerr << "[ "; for (T i : s) {_print(i); cerr << " ";} cerr << "]";
}
template<class T> void _print(multiset<T>s)
{
	cerr << "[ "; for (T i : s) {_print(i); cerr << " ";} cerr << "]";
}
template <class T, class V> void _print(pair <T, V> pair_p) {
	cerr << "{"; _print(pair_p.first); cerr << ","; _print(pair_p.second); cerr << "}";
}
template <class T, class V> void _print(map <T, V> mp) {
	cerr << "[ "; for (auto i : mp) {_print(i); cerr << " ";} cerr << "]";
}
/****************************************************************************************/



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
				Graph[cnt].pb(x);
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
		// debug(dist1);
		// debug(dist2);
		// debug(ans);
		return ans_node;
	}
};
