class Solution {
    vector<vector<int>>Adj_List;
    map<int,set<int>>Pre_Req;
public:
    void Ordering(int numCourses,vector<vector<int>>& prerequisites){
        Adj_List.resize(numCourses);
        vector<int>Indegree(numCourses,0);
        for(auto x:prerequisites){
            int from=x[0]; int to=x[1];
            Adj_List[from].push_back(to);
            Indegree[to]++;
        }
        queue<int>que;
        
        for(int i=0;i<numCourses;i++){
            if(Indegree[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int curr_node=que.front();
            que.pop();
            for(auto child:Adj_List[curr_node]){
                Indegree[child]--;
                Pre_Req[child].insert(curr_node);
                for(auto pre_:Pre_Req[curr_node]){
                    Pre_Req[child].insert(pre_);
                }
                // Pre_Req[child].insert(Pre_Req[curr_node]);
                if(Indegree[child]==0){
                    que.push(child);
                }
            }
        }       

    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        Ordering(numCourses,prerequisites);
        vector<bool>res;
        for(auto x:queries){
            int from=x[0];
            int to=x[1];
            res.push_back(Pre_Req[to].contains(from));
        }

        return res;
    }
};