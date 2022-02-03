class Solution {
public:
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        map<int,int>AB;
        for(auto a:nums1)
        {
            for(auto b:nums2)
            {
                AB[a+b]++;
            }
        }
        int count=0;
        for(auto c:nums3)
        {
            for(auto d:nums4)
            {
                int curr=c+d;
                if(AB.count(-curr))
                {
                    count+=AB[-curr];
                }
            }
        }
        return count;
        
    }
};