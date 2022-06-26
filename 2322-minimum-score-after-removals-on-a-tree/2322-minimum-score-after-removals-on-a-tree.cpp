class Solution {
    int timer = 0;
    int dfs(int node, int p, vector<vector<int>> &adj, vector<int> &par, vector<int> &XOR, vector<int> &nums, vector<int> &intime, vector<int> &outtime)
    {
        par[node] = p;
        intime[node] = timer++;
        int val = nums[node];
        for (int adjNode : adj[node])
        {
            if (adjNode == p) continue;
            val ^= dfs(adjNode, node, adj, par, XOR, nums, intime, outtime);
        }
        outtime[node] = timer++;
        return XOR[node] = val;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), res = INT_MAX;
        vector<vector<int>> adj(n);
        for (vector<int> &v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> par(n, -1), XOR(n), intime(n), outtime(n);
        dfs(0, -1, adj, par, XOR, nums, intime, outtime);
        for (vector<int> &v : edges)
        {
            if (par[v[1]] != v[0])
                swap(v[1], v[0]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                int n1 = edges[i][1], n2 = edges[j][1], n3 = 0;
                // n1 is in subtree of n2
                if (intime[n2] < intime[n1] && outtime[n1] < outtime[n2])
                {
                    int a = XOR[n1];
                    int b = (XOR[n2] ^ XOR[n1]);
                    int c = (XOR[0] ^ XOR[n2]);
                    res = min(res, max({a, b, c}) - min({a, b, c}));
                }
                // n2 is in subtree of n1
                else if (intime[n1] < intime[n2] && outtime[n2] < outtime[n1])
                {
                    int a = XOR[n2];
                    int b = (XOR[n1] ^ XOR[n2]);
                    int c = (XOR[0] ^ XOR[n1]);
                    res = min(res, max({a, b, c}) - min({a, b, c}));
                }
                // n1 & n2 are separate
                else
                {
                    int a = XOR[n1];
                    int b = XOR[n2];
                    int c = (XOR[0] ^ XOR[n1] ^ XOR[n2]);
                    res = min(res, max({a, b, c}) - min({a, b, c}));
                }
            }
        }
        return res;
    }
};