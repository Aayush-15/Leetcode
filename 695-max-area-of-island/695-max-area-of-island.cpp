class Solution {
public:
    int m,n;
    int vis[51][51];
    int mat[51][51];
    vector<int>Connected_components_area;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int area_counter=0;
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
        area_counter++;
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
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
         n = grid.size();
         m = grid[0].size();
         for(int i=0;i<51;i++)
         {
             for(int j=0;j<51;j++)
             {
                 vis[i][j]=0;
                 mat[i][j]=-1;
             }
         }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int yy=grid[i][j];
                mat[i][j]=yy;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1&&vis[i][j]==0)
                {
                    area_counter=0;
                    dfs(i,j);
                    Connected_components_area.push_back(area_counter);
                }
            }
        }
        int ANS=0;
        for(auto x:Connected_components_area)
        {
            ANS=max(ANS,x);
        }
        return ANS;
    }
};