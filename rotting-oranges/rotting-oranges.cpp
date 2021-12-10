class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        if(grid.empty())
            return 0;
        int n=grid.size();
        int m=grid[0].size();
        int total_oranges=0;
        int rotten_count=0;
        int days_count=0;
        queue<pair<int,int>>que;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    continue;
                total_oranges++;
                if(grid[i][j]==2)
                {
                    que.push({i,j});
                }
            }
        }
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        //inserted all current rotten oranges to que
        //now pop out one by one and push their neighbour oranges which have became rotten
        //and continue this until ann connected oranges do not become rotten
        while(!que.empty())
        {
            int tot=que.size();
            rotten_count+=tot;
            while(tot--)
            {
                int x=que.front().first;
                int y=que.front().second;
                que.pop();
                for(int i=0;i<4;i++)
                {
                    int newx=x+dx[i];
                    int newy=y+dy[i];
                    if(newx<0||newy<0||newx>=n||newy>=m||grid[newx][newy]!=1)
                        continue;
                    grid[newx][newy]=2;
                    que.push({newx,newy});
                }
            }
            if(!que.empty())
                days_count++;
        }
        int ans=days_count;
        if(rotten_count!=total_oranges)
            ans=-1;
        return ans;
        
    }
};