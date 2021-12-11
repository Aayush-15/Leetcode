class Solution {
public:
    //We can represent bombs using a directed graph - when a bomb i can detonate bomb j, there is an edge from i to j
    
    long long dis2(vector<vector<int>> &bombs, int i, int j) {
        long long x1 = bombs[i][0], y1 = bombs[i][1];
        long long x2 = bombs[j][0], y2 = bombs[j][1];
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    vector<int> g[110];
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int n = bombs.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long d = dis2(bombs, i, j);
                long long r = bombs[i][2];
                if (r * r >= d) {
                    g[i].push_back(j);
                }
            }
        }
        int res = 0;
        for (int start = 0; start < n; start++) {
            int vis[110];
            memset(vis, 0, sizeof(vis));
            queue<int> q;
            q.push(start);
            vis[start] = 1;
            int tmp = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int to: g[u]) {
                    if (!vis[to]) {
                        q.push(to);
                        vis[to] = 1;
                        tmp++;
                    }
                }
            }
            res = max(res, tmp);
        }
        return res;
    }
};