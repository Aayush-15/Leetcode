class Solution {
public:
    void dfs(vector<vector<int> >&adj,int node,vector<int>&vis)
    {
        vis[node]=1;
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                dfs(adj,x,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        vector<vector<int>>adj(n+1);
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(isConnected[i][j]==1)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,i,vis);
                count++;
            }
        }
        return count;
        
    }
};