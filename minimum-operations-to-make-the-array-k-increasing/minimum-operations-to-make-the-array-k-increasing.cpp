class Solution {
public:
    int helper(vector < int > & arr) 
    {
        vector < int > tmp;
         for (int x: arr) 
         {
             int yy=tmp.size();
            if (tmp.empty() || tmp[yy - 1] <=x) 
            {
              tmp.push_back(x);  
            } 
            else 
            {
                auto it = upper_bound(tmp.begin(), tmp.end(), x);       
                * it = x;
             }
        }
        return tmp.size();
    }
    int kIncreasing(vector<int>& arr, int k) 
    {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<k;i++)
        {
            vector<int>yy;
            for(int kk=i;kk<n;kk+=k)
            {
                yy.push_back(arr[kk]);
            }
            ans+=yy.size()-helper(yy);
        }
        return ans;
    }
};