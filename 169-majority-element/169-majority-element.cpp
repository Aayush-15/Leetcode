class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> counter;
        for (int num : nums) {
            if (++counter[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
    }
};
