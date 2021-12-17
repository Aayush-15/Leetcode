//Kindly Note This Is A Brute Force Solution
//Don't Refer This
class Solution {
public:
    int bfs(vector<vector<int>>&adj, int source, int n)
    {

        int sz = n;
        vector<int>visited(sz, 0);
        queue<int>que;
        vector<int>dist(sz, 1e9);
        visited[source] = 1;
        dist[source] = 0;
        que.push(source);
        int maxi = 0;
        while (!que.empty())
        {
            int curr_ = que.front(); //Popping the nearest Node from The Queue
            que.pop();
            //    if(source==4)
            //    {
            //        cout<<curr_<<'\n';
            //    }

            for (auto x : adj[curr_])
            {
                if (visited[x] == 0)
                {
                    visited[x] = 1;
                    que.push(x);
                    dist[x] = dist[curr_] + 1;

                }
            }
        }
        for (auto x : dist)
        {
            maxi = max(maxi, x);
        }
        /*if(source==4)
        {
            for(auto x:dist)
            {
                cout<<x<<" ";
            }
        }*/
        return maxi;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>>adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        /*
        Debugging
        for(auto x:adj[4])
        {
            cout<<x<<" ";
        }
        cout<<'\n';
        */
        vector<int>ans;
        //Consider Each Node as a Source Node and Make A Bfs Call And Find the Farthest Node Dist
        for (int i = 0; i < n; i++)
        {
            ans.push_back(bfs(adj, i, n));
        }
        int mini = 1e9;
        for (auto x : ans)
        {
            mini = min(mini, x);
            //cout<<x<<" ";
        }
        //Store the Minimum Distances Index in The Roots Array
        vector<int>roots;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == mini)
            {
                roots.push_back(i);
            }
        }
        return roots;
    }
};