class Solution {
public:
    //  finding cycles 
    void dfs(int v,vector<bool>& vis,vector<bool>& rec,vector<int>& par,vector<int> adj[],int& ans){
        vis[v] = rec[v] = true;
        for(auto& u:adj[v]){
            if(!vis[u]){
                par[u] = v;
                dfs(u,vis,rec,par,adj,ans);
            }
            else if(rec[u]){
                // find the length of cycle
                int vertex = v,curr = 1;
                while(vertex!=u){
                    curr++;
                    vertex = par[vertex];
                }
                ans = max(ans,curr);
            }
        }
        rec[v] = false;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        // cycle finding
        vector<int> adj[n],par(n,-1),in(n);
        for(int i=0;i<n;i++){
            adj[i].push_back(favorite[i]); // i --> favorite[i]
            in[favorite[i]]++;
        }
        vector<bool> vis(n),rec(n);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i,vis,rec,par,adj,ans);
        }
 
        // toplogical sorting using khan's algo
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!in[i])
                q.push(i);
        }
 
        vector<int> dp(n,1);
        while(!q.empty()){
            int v = q.front();
            q.pop();
 
            for(auto& u:adj[v]){
                if(--in[u]==0)
                    q.push(u);
                dp[u] = max(dp[u],1+dp[v]);
            }
        }
 
        int sum = 0;
        for(int i=0;i<n;i++){
            if(favorite[favorite[i]]==i){
                // length of cycle = 2;
                sum += dp[i] + dp[favorite[i]];
            }
        }
 
        sum/=2;
 
        ans = max(ans,sum);
        return ans;
    }
};