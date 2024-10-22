class Solution {
public:
    bool is_possible(vector<int>&nums,int k,int possible_largest){
        int current_partitions=1;
        int curr_partition_sum=0;
        for(auto x:nums){
            if(x>possible_largest){
                return false;
            }
            if(x+curr_partition_sum>possible_largest){
                curr_partition_sum= x;
                current_partitions++;
            }
            else{
                curr_partition_sum+=x;
            }
        }
        // cout<<"current_partitions"<<current_partitions<<endl;
        // if(curr_partition_sum>0){
        //     current_partitions++;
        // } 
        if(current_partitions<=k){
            return true;
        }
        return false;

    }
    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        for(auto x:nums){
            r+=x;
        }
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(is_possible(nums,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return ans;
    }
};