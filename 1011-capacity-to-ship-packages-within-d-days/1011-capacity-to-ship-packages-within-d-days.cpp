class Solution {
public:
    bool is_possible(vector<int>&weights,int days,int curr_capacity)
    {
        int curr_days=1;
        int curr_weight=0;
        for(auto x:weights)
        {
            if(x>curr_capacity)
            {
                return false;
            }
            if(x+curr_weight<=curr_capacity)
            {
                curr_weight+=x;
            }
            else
            {
                curr_weight=x;
                curr_days++;
            }
        }
        return curr_days<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        //Observation:Monotonic Search Space
        // Let Capacity Of Ship->X(Consider Optimal) , then all possible values>X, Answer is always possible, but any smaller value of ship Capacity, it will take More Days Then Expected.
       // Monotonic Search Space-> F F F F F F F F T T T T T(Find First True)
        int left=1;
        int right=5e4*500;
        int ans=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            //If Current Mid Value Satisfies The Condition
            //Look for more optimal Answer in the left search Space
            if(is_possible(weights,days,mid))
            {
                ans=mid;
                right=mid-1;
            }
            //Look for Answer in Right Search space
            else
            {
                left=mid+1;
            }
        }
        return ans;
        
    }
};