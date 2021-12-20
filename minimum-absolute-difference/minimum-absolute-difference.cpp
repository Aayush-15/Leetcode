class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mini=1e9;
        for(int i=1;i<n;i++)
        {
            mini=min(mini,arr[i]-arr[i-1]);
        }
        vector<vector<int>>ans;
        for(int i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]==mini)
            {
                vector<int>tmp={arr[i-1],arr[i]};
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};