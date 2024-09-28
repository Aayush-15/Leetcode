class Solution {
public:
    bool is_possible(int k,int h,vector<int>&piles){
        int hours=0;
        for(auto x:piles){
            hours+=((x+k-1)/k);
        }
        // cout<<k<<" "<<hours<<endl;
        if(hours<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=1e9+7;
        // for(auto x:piles){
        //     r=max(r,x);
        // }
        int ans=-1;
        while(l<r){
            int mid=((r-l)/2)+l;
            if(is_possible(mid,h,piles)){
                ans=mid;
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};