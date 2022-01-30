class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int sz=nums.size();
        k=k%sz;
        if(k==0)
        {
            return;
        }
        map<int,int>mp;
        
        for(int i=0;i<sz;i++)
        {
            mp[(i+k)%(sz)]=(nums[i]);
            //cout<<mp[i]<<'\n';
        }
        int ind=0;
        for(auto x:mp)
        {
            nums[ind]=x.second;
            ind++;
        }
    }
};