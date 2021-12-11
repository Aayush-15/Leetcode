class Solution {
public:
    //Using Set Data Structure
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        set<pair<int,int>>pq;
        //Min-Heap Priority Queue
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        pq.insert({0,k});
        while(!pq.empty())
        {
            auto it=*pq.begin();
            pq.erase(it);
            int curr_node=it.second;
            int curr_dist=it.first;
            for(auto x:adj[curr_node])
            {
                //Now we will iterate over all the adjacent nodes to the current node and try to reduce the distance 
                int next=x.first;
                int weight=x.second;
                if(dist[next]>dist[curr_node]+weight)
                {
                    dist[next]=dist[curr_node]+weight;
                    pq.insert({dist[next],next});
                }
            }
        }
        int maxi=-1;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
            {
                return -1;
            }
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};