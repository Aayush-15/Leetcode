class Solution {

int n,m;
int dx[4]={+1,-1,0,0};
int dy[4]={0,0,+1,-1};
public:
    bool is_coordinates_valid(int x,int y){
        if(x<0||y<0||x>=n||y>=m){
            return false;
        }
        return true;
    }
    int subtree_size(vector<vector<int>>&grid,int x,int y,int grp){
        int dir=4;
        int sz=1;
        grid[x][y]=grp;
        for(int i=0;i<4;i++){
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if(is_coordinates_valid(new_x,new_y)){
                if(grid[new_x][new_y]==1){
                    sz+=subtree_size(grid,new_x,new_y,grp);
                }
            }
        }
        return sz;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size(); m=grid[0].size();
        map<int,int>grp_size_mapping;
        int grp=3;
        int new_size=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grp_size_mapping[grp]=subtree_size(grid,i,j,grp);
                    new_size=max(new_size,grp_size_mapping[grp]);
                    grp++;
                }
                
            }
        }
        
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                if(grid[x][y]==0){
                    int curr_sz=1;
                    set<int>group_set;
                    for(int idx=0;idx<4;idx++){
                        int new_x=x+dx[idx];
                        int new_y=y+dy[idx];
                        if(is_coordinates_valid(new_x,new_y)){
                            int curr_grp=grid[new_x][new_y];
                            if(curr_grp>1){
                               group_set.insert(curr_grp);
                            }
                        }
                    }
                    for(auto x:group_set){
                        curr_sz+=grp_size_mapping[x];
                    }
                    new_size=max(new_size,curr_sz);
                }
                
            }
        }
        return new_size;
        
    }
};