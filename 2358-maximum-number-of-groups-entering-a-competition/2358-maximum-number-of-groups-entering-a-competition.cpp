class Solution {
public:
    int maximumGroups(vector<int>& grades) 
    {
        int l=0;
        int r=500;
        int total_students=grades.size();
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if((mid*(mid+1))/2<=total_students)
            {
                l=mid+1;
                ans=max(ans,mid);
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};