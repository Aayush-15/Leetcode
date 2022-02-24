class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int>A=nums;
        int n=A.size();
        for(int i=0;i<n;i++)
        {
            while(A[i]>=1 and A[i]<n and A[i]!=A[A[i]-1])
            {
                swap(A[i],A[A[i]-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(A[i]!=i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }
};