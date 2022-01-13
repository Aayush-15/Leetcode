class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        vector<pair<int,int>>vp;
        //Insert End Point,StartPoint In Vector Of Pairs
        for(auto x:points)
        {
            vp.push_back({x[1],x[0]});
        }
        sort(vp.begin(),vp.end());
        int count=1;
        int curr_end=vp[0].first;
        for(int i=1;i<vp.size();i++)
        {
            if(vp[i].second<=curr_end)
            {
                
            }
            else 
            {
                count++;
                curr_end=vp[i].first;
            }
        }
        return count;
    }
};