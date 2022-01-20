class Solution {
public:
    bool is_possible(vector<int>&quantities,int n,int mid)
    {
        int count=0;
        for(auto x:quantities)
        {
            count+=(x/mid);
            if(x%mid)
            {
                count++;
            }
        }
       // cout<<mid<<" "<<count<<'\n';
        if(count<=n)
        {
            return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        //There exists a monotonic nature such that when x is smaller than some number, there will be no way to distribute, and when x is not smaller than that number, there will always be a way to distribute.
        //F F F F F F F F T T T T T ->Find First True
        int left=1;
        int right=1e9+7;
        int ans=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(is_possible(quantities,n,mid))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;

    }
};