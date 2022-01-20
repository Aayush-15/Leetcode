class Solution {
public:
    bool is_possible(vector<int>&piles,int k,int h)
    {
        int total_hours=0;
        for(auto x:piles)
        {
            total_hours+=((x)/k);
            if(x%k)
            {
                total_hours++;
            }
        }
        if(total_hours<=h)
        {
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        //Binary Search On The Answer
        // F F F F F F T T T T T->Search for the first True
        int left=1;
        int right=1e9+8;
        int ans=0;
        while(left<=right)
        {
            int mid=((left+right)/2);
            //If we get a correct Answer for this current value of Mid, 
            //Then all the values greater then mid will also satisfy the conditions
            //But we have to minimize K, hence searh for the more optimal value of K 
            //In the left searchspace
            if(is_possible(piles,mid,h))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};