class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        vector<int>indices;
        int tmp_k=k;
        while(tmp_k--)
        {
            auto it=pq.top();
            pq.pop();
            indices.push_back(it.second);
        }
        sort(indices.begin(),indices.end());
        vector<int>ans;
        for(auto x:indices)
        {
            ans.push_back(nums[x]);
        }
        return ans;
        
    }
};