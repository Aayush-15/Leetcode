class Solution {
public:
    int dfs(int node,int par,vector<vector<int>>&adj,vector<int>& manager, vector<int>& informTime)
    {
        int total_time=informTime[node];
        int max_time=0;
        for(auto child:adj[node])
        {
            if(child!=par)
            {
                max_time=max(max_time,dfs(child,node,adj,manager,informTime));
            }
        }
        //cout<<node<<" "<<total_time<<'\n';
        return total_time+max_time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        vector<vector<int>>adj(n);
        int curr_node=0;
        for(auto x:manager)
        {
            if(x!=-1)
            {
                adj[curr_node].push_back(x);
                adj[x].push_back(curr_node);
                
            }
            curr_node++;
        }
       
        int ans=dfs(headID,-1,adj,manager,informTime);
        return ans;
    }
};