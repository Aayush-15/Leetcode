class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int>Indegree(n+1,0);
        vector<int>Outdegree(n+1,0);
        for(auto x:trust)
        {
            Indegree[x[1]]++;
            Outdegree[x[0]]++;
        }
        int count=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(Indegree[i]==n-1 and Outdegree[i]==0)
            {
                count++;
                ans=i;
            }
        }
        if(count!=1)
        {
            return -1;
        }
        return ans;
    }
};