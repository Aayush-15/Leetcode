//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>Indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                Indegree[it]++;
            }
        }
        // for(auto x:Indegree)
        // {
        //     cout<<x<<" ";
        // }
        
        
        int nodes_processed=0;
        queue<int>que;
        for(int i=0;i<Indegree.size();i++)
        {
            if(Indegree[i]==0)
            {
                //start_node=i;
                que.push(i);
            }
        }
        while(!que.empty())
        {
            int curr_=que.front();
            que.pop();
            nodes_processed++;
            for(auto x:adj[curr_])
            {
                Indegree[x]--;
                if(Indegree[x]==0)
                {
                    que.push(x);
                }
            }
        }
        
        
        if(V!=nodes_processed)
        {
            return true;
        }
        
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends