class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int>ordering;
        vector<vector<int>>adj(numCourses);
        vector<int>Indegree(numCourses,0);
        for(auto x:prerequisites)
        {
            adj[x[0]].push_back(x[1]);
            Indegree[x[1]]++;
        }
        queue<int>que;
        for(int i=0;i<numCourses;i++)
        {
            if(Indegree[i]==0)
            {
                que.push(i);
            }
        }
        while(!que.empty())
        {
            int curr_node=que.front();
           // cout<<curr_node<<" ";
            que.pop();
            ordering.push_back(curr_node);
            for(auto x:adj[curr_node])
            {
                Indegree[x]--;
                if(Indegree[x]==0)
                {
                    que.push(x);
                }
            }
            
        }
        // for(auto x:ordering)
        // {
        //     cout<<x<<" ";
        // }
        reverse(ordering.begin(),ordering.end());
        if(ordering.size()==numCourses)
        {
            return ordering;
        }
        vector<int>empty_array;
        return empty_array;
        
    }
};