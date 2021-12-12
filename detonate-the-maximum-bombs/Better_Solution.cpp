class Solution {
public:
    //We can represent bombs using a directed graph
    //When a bomb i can detonate bomb j, there is an edge from i to j
    long long calc_dist_square(vector<vector<int>>&bombs, int i, int j)
    {
        long long x1 = bombs[i][0], y1 = bombs[i][1];
        long long x2 = bombs[j][0], y2 = bombs[j][1];
        //long long dist=
        return ((x1 - x2)) * ((x1 - x2)) + ((y1 - y2)) * ((y1 - y2));
    }
    int maximumDetonation(vector<vector<int>>& bombs)
    {
        //Iterate over All the Pair of Bombs And Check
        //If i can detonate j Insert i make directed edge from i to j
        vector<vector<int> >adj(101);
        for (int i = 0; i < bombs.size(); i++)
        {
            for (int j = 0; j < bombs.size(); j++)
            {

                if (i == j)
                {
                    continue;
                }
                //Checking if i can detonate jth bomb
                long long radius = bombs[i][2];
                long long dist = calc_dist_square(bombs, i, j);
                if (radius * radius >= dist)
                {
                    adj[i].push_back(j);//if i can detonate the jth bomb
                }
            }
        }
        int ans = 0;
        //Now for every bomb , Calculate the Number of bombs that can be diffused
        for (int i = 0; i < bombs.size(); i++)
        {
            int start = i;
            queue<int>que;
            vector<int>vis(bombs.size());
            vis[start] = 1;
            que.push(start);
            while (!que.empty())
            {
                int curr_ = que.front();
                que.pop();
                for (auto child : adj[curr_])
                {
                    if (!vis[child])
                    {
                        vis[child] = 1;
                        que.push(child);
                    }
                }
            }
            int count = 0;
            for (auto x : vis)
            {
                if (x)
                {
                    count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};