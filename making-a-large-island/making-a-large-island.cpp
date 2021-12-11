/*
Reference:
https://leetcode.com/problems/making-a-large-island/discuss/1375992/C%2B%2BPython-DFS-paint-different-colors-Union-Find-Solutions-with-Picture-Clean-and-Concise
https://leetcode.com/problems/making-a-large-island/discuss/1379015/c-solution-using-dsu-union-find
*/
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int n;
    map<int,int>componentsize;
    int largestIsland(vector<vector<int>>& grid)
    {
        n=grid.size();    
        int color=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid,color);
                    color++;
                }
            }
        }
        int ans=0;
        bool zero_occur=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    zero_occur=true;
                    set<int>s;
                    for(int k=0;k<4;k++)
                    {
                        int newx=i+dx[k];
                        int newy=j+dy[k];
                        if(newx<0||newx>=n||newy<0||newy>=n)
                            continue;
                        if(grid[newx][newy]==0)
                            continue;
                        s.insert(grid[newx][newy]);
                    }
                    int curr_count=1;
                    for(auto x:s)
                    {
                        curr_count+=componentsize[x];
                    }
                    ans=max(ans,curr_count);
                }
            }
        }
       /*  for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
               cout<<grid[i][j]<<" ";
            }
             cout<<'\n';
        }
        for(auto x:componentsize)
            cout<<x.first<<" "<<x.second<<'\n';*/
        if(zero_occur==false)
            ans=n*n;
        return ans;
    }
    void dfs(int x,int y,vector<vector<int>>&grid,int color)
    {
        if(x<0||x>=n||y>=n||y<0||grid[x][y]!=1)
        {
            return;
        }
        grid[x][y]=color;
        componentsize[color]++;
        for(int i=0;i<4;i++)
        {
            dfs(x+dx[i],y+dy[i],grid,color);
        }
        
    }
};