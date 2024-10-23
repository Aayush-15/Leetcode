class Solution {
public:
    static bool comperator(vector<int>&a,vector<int>&b){
        return a[1]<b[1];//Sort By Ending Date
    }

    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(),courses.end(),comperator);

        priority_queue<int>pq;
        int time=0;

        for(auto x:courses){
            //We Can Include this
            if(time+x[0]<=x[1]){
                time+=x[0];
                pq.push(x[0]);
            }
            //else if i cannot add this, It exceeds the time
            else{
                if(pq.size()>0 && pq.top()>=x[0]){
                    time=time-pq.top()+x[0];
                    pq.pop();
                    pq.push(x[0]);
                }
            }
        }
        return pq.size();
        
    }
};