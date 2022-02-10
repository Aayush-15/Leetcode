struct Job{
    int start;
    int end;
    int profit;
};
bool comperator(Job A,Job B)
{
    return (A.end < B.end);
}
class Solution {
public:
    int b_search(Job Arr[],int n,int ind)
    {
        int l=0;
        int r=ind-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(Arr[mid].end<=Arr[ind].start)
            {
                ans=max(ans,mid);
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n=startTime.size();
        Job Arr[n];
        for(int i=0;i<n;i++)
        {
            Arr[i].start=startTime[i];
            Arr[i].end=endTime[i];
            Arr[i].profit=profit[i];
        }
        sort(Arr,Arr+n,comperator);
        vector<int>dp(n,0);
        dp[0]=Arr[0].profit;
        for(int i=1;i<n;i++)
        {
            //For Every Job We Have Two Choice
            //Choice1:Don't Take Current Job
            int option1=dp[i-1];
            //Choice2:Take The Current Job
            //Therefore Using Binary Search Find The Job with max profit whose 
            //End Tiem IS Less Than Current Job Start Time
            int option2=Arr[i].profit;
            int prev_=b_search(Arr,n,i);
           // cout<<prev_<<'\n';
            if(prev_!=-1)
            {
                option2+=dp[prev_];
            }
            dp[i]=max(option1,option2);
        }
        // for(auto x:dp)
        // {
        //     cout<<x<<" ";
        // }
        return dp[n-1];
    }
};