// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle=false;
    void dfs(int node,int par,vector<int>adj[],vector<int>&Visited)
    {
        Visited[node]=true;
        for(auto child:adj[node])
        {
            if(child==par)
            {
                continue;
            }
            if(Visited[child])
            {
                cycle=true;
                return;
            }
            else
            {
                dfs(child,node,adj,Visited);
            }
            
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>Visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!Visited[i])
            {
                dfs(i,-1,adj,Visited);
            }
        }
        return cycle;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends