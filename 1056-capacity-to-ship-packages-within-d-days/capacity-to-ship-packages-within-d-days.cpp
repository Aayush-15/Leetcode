class Solution {
public:
    bool is_possible(vector<int>&weights,int days, int min_capacity){
        int curr_days=1;
        int curr_weight=0;
        for(auto x:weights){
            if(x>min_capacity){
                return false;
            }
            if(x+curr_weight>min_capacity){
               curr_days++;
                curr_weight=x;
            }
            else{
                curr_weight+=x;
            }
        }
        return curr_days<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0,r=0;
        for(auto x:weights){
            l=max(l,x);
            r+=x;
        }
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(is_possible(weights,days,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
        
    }
};