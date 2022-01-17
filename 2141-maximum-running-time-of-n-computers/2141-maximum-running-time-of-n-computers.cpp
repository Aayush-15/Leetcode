class Solution {
public:
    bool is_possible(vector<int>&batteries,int n,long long time)
    {
        long long max_time=0;//Time for which every computer is on
        long long req_time=n*time;//Total Time Required By Each Computer
        for(auto x:batteries)
        {
            max_time+=(long long)min(time,(long long)x);
        }
        if(max_time>=req_time)
        {
            return true;
        }
        return false;
        
    }
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        long long left=0;
        long long right=0;
        for(auto x:batteries)
        {
            right+=(long long)x;
        }
        long long ans=0;
        while(left<=right)
        {
            long long mid=(left)+((right-left)/2);
            if(is_possible(batteries,n,mid))
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
};