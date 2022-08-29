class Solution {
public:
    long long cnt=0;
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis)
    {
        cnt++;
        vis[node]=1;
        for(auto x:adj[node])
        {
            if(vis[x]==0)
            {
                dfs(x,adj,vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n,vector<int>());
        vector<int>vis(n,0);
        long long ans=0;
        vector<long long>component_sz;
        for(auto x:edges)
        {
            int to,from;
            to=x[0],from=x[1];
            adj[to].push_back(from);
            adj[from].push_back(to);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                cnt=0;
                dfs(i,adj,vis);
                component_sz.push_back(cnt);
                cnt=0;
            }
        }
        // for(auto x:component_sz)
        // {
        //     cout<<x<<" ";
        // }
        // cout<<'\n';
        if(component_sz.size()==0||component_sz.size()==1)
        {
            return 0;
        }
        vector<int>suffix_(component_sz.size(),0);
        for(int i=component_sz.size()-1;i>=0;i--)
        {
            if(i==component_sz.size()-1)
            {
                suffix_[i]=component_sz[i];
                continue;
            }
            suffix_[i]=suffix_[i+1]+component_sz[i];
        }
        for(int i=0;i<suffix_.size()-1;i++)
        {
            ans+=(component_sz[i]*suffix_[i+1]);
        }
        return ans;
        
        
    }
};