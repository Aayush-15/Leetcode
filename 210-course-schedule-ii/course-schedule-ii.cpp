class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj_list(numCourses);
        vector<int>Indegree(numCourses,0);
        for(auto edge:prerequisites){
            int from=edge[1];
            int to=edge[0];
            Indegree[to]++;
            adj_list[from].push_back(to);
        }
        queue<int>que;
        vector<int>order;
        for(int i=0;i<numCourses;i++){
            if(Indegree[i]==0){
                que.push(i);
                // order.push(i);
            }
        }
        
        while(!que.empty()){
            int curr_node=que.front();
            que.pop();
            order.push_back(curr_node);
            for(auto x:adj_list[curr_node]){
                Indegree[x]--;
                if(Indegree[x]==0){
                    que.push(x);
                }
            }
        }
        if(order.size()==numCourses){
            return order;
        }
        vector<int>empty_array;
        return empty_array;

        
    }
};