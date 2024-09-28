class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int dx[4] = {+1,-1,0,0};
        int dy[4] = {0,0,-1,+1};
        queue<pair<int,int>>que;
        int n=grid.size();
        int m=grid[0].size();

        int time=0;
        //Initially Rotten Oranges, Push to Queue
        int fresh_cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2){
                    que.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh_cnt++;
                }
            }
        }

        while(!que.empty())
        {
            int curr_size=que.size();
            time++;
            for(int i=0;i<curr_size;i++)
            {
                pair<int,int>curr_orange=que.front();
                
                que.pop();

                for(int i=0;i<4;i++)
                {
                    int new_x=curr_orange.first+dx[i];
                    int new_y=curr_orange.second+dy[i];
                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<m){
                        if(grid[new_x][new_y]==1){
                            grid[new_x][new_y]=2;
                            fresh_cnt--;
                            que.push({new_x,new_y});
                        }
                    }

                }
            }
        }

        if(fresh_cnt>0){
            return -1;
        }
        if(time==0){
            return 0;
        }
    return time-1;
    }
};