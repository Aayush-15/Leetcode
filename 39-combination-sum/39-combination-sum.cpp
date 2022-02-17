class Solution {
public:
    void generate_combination(int index,int target,vector<int>&candidates,vector<int>&ds,vector<vector<int>>&ans){
        if(index==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(target>=candidates[index])
        {
            ds.push_back(candidates[index]);
            generate_combination(index,target-candidates[index],candidates,ds,ans);
            ds.pop_back();
        }
        generate_combination(index+1,target,candidates,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        generate_combination(0,target,candidates,ds,ans);
        return ans;
    }
};