class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int>ans;
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>Inorder(n,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int fir=prerequisites[i][0];
            int sec=prerequisites[i][1];
            adj[sec].push_back(fir);
            Inorder[fir]++;
        }
        queue<int>que;
        for(int i=0;i<n;i++)
        {
            if(Inorder[i]==0)
            {
                que.push(i);
            }
        }
    
        int vis_cnt=0;
        while(!que.empty())
        {
            int sz=que.size();
            vis_cnt+=sz;
            for(int i=0;i<sz;i++)
            {
                int curr=que.front();
                que.pop();
                ans.push_back(curr);
                for(auto x:adj[curr])
                {
                    Inorder[x]--;
                    if(Inorder[x]==0)
                    {
                        que.push(x);
                    }
                }
            }
        }
        if(vis_cnt!=n)
        {
           return {};
        }
        return ans;
        
    }
};