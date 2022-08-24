class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        map<int,int>mp;
        set<int>ss;
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
            ss.insert(nums[i]);
        }
        vector<int>ans_;
        ans_.push_back(*ss.rbegin());
        for(int i=k;i<nums.size();i++)
        {
            int ind_=i-k;
            int val=nums[ind_];
            mp[val]--;
            if(mp[val]==0)
            {
                ss.erase(ss.find(val));
            }
            mp[nums[i]]++;
            ss.insert(nums[i]);
            ans_.push_back(*ss.rbegin());

            
        }
        return ans_;
    }
};