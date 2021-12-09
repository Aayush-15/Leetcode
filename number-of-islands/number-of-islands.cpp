class Solution {
public:
    int m,n;
    int vis[303][303];
    int mat[303][303];
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int islands=0;
    bool is_valid(int aa,int bb)
    {
        if(aa<0||aa>=n||bb<0||bb>=m)
            return false;
        if(vis[aa][bb]||mat[aa][bb]!=1)
            return false;
        return true;
    }
    void dfs(int x,int y)
    {
        
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int j=i;
            {
                if(is_valid(x+dx[i],y+dy[j]))
                    dfs(x+dx[i],y+dy[j]);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid)
    {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++)
         {
             for(int j=0;j<m;j++)
             {
                 vis[i][j]=0;
                 mat[i][j]=-1;
             }
         }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int yy=grid[i][j]-'0';
                mat[i][j]=yy;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1&&vis[i][j]==0)
                {
                    
                    dfs(i,j);
                    islands++;
                    
                }
            }
        }
        
        return islands;
    }
};