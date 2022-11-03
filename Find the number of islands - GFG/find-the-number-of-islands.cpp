//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int n,m;
    int dx[4]={+1,-1,0,0};
    int dy[4]={-1,+1,0,0};
    
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis)
    {
        if(grid[i][j]=='0')
        {
            vis[i][j]=1;
            return;
        }
        
        vis[i][j]=1;
        for(auto x:dx)
        {
            for(auto y:dy)
            {
                if(abs(x)+abs(y)>=1)
                {
                    int new_x=i+x;
                    int new_y=j+y;
                    if(new_x>=0 and new_x<n and new_y>=0 and new_y<m and vis[new_x][new_y]==0 and grid[new_x][new_y]=='1')
                    {
                        dfs(new_x,new_y,grid,vis);
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and vis[i][j]==0)
                {
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends