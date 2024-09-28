class Solution {
public:
    void dfs(vector<vector<int>>&isConnected,vector<int>&visited,int i,int n){
        visited[i]=1;
        for(int j=0;j<n;j++)
        {
            if(i!=j && visited[j]==0 && isConnected[i][j]==1){
                // cout<<i<<" "<<j<<'\n';
                dfs(isConnected,visited,j,n);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {

     int n=isConnected.size();


     vector<int>visited(n,0);
     int ans=0;
     for(int i=0;i<n;i++)
     {
        if(visited[i]==0){
    
            dfs(isConnected,visited,i,n);
            ans++;
        }
        
     }
     return ans;
    }
};