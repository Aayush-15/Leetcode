class Solution {
public:
    int dx[4]={+1,-1,0,0};
    int dy[4]={0,0,+1,-1};
    void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>& vis,int n,int m)
    {
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if(new_x<0||new_x>=n)
            {
                continue;
            }
            if(new_y<0||new_y>=m)
            {
                continue;
            }
            if(vis[new_x][new_y]==0 and grid[new_x][new_y]=='1')
            {
                dfs(new_x,new_y,grid,vis,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int island_count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and visited[i][j]==0)
                {
                    dfs(i,j,grid,visited,n,m);
                    island_count++;
                }
            }
        }
        return island_count;
    }
};