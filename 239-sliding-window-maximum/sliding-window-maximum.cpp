class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>deq;//Defining Douby-Ended Queue
        int maxi=-1e8;
        vector<int>result;
        for(int i=0;i<k;i++){
            // maintain decreasing order in the deque, remove smaller elements
            while(!deq.empty() && nums[deq.back()]<=nums[i]){
                deq.pop_back();
            }
            deq.push_back(i);//Always Adding Current index to the Back
        }
        result.push_back(nums[deq.front()]);

        for(int i=k;i<nums.size();i++)
        {
            //Removal of Out of Range Elements
            while(!deq.empty() && i-deq.front()>=k){
                deq.pop_front();
            }
            //Removal Of Smaller Elements Compared to Current From Deque
            while(!deq.empty() && nums[deq.back()]<=nums[i] ){
                deq.pop_back();
            }

            deq.push_back(i);
            result.push_back(nums[deq.front()]);
        }
        return result;

        
    }
};

