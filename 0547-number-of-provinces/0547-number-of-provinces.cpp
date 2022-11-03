class Solution {
public:
    void dfs(vector<vector<int>>&adj,int node,vector<int>&visited)
    {
        visited[node]=1;
        for(auto x:adj[node])
        {
            if(!visited[x])
            {
                dfs(adj,x,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int count=0;
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<vector<int>>adj(n);
        vector<int>visited(n,0);
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(isConnected[i][j]==1 and isConnected[j][i]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(adj,i,visited);
                count++;
            }
        }
        return count;
        
    }
};