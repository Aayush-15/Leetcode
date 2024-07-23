class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> frequence_count;
        for (int num : nums) {
            frequence_count[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (frequence_count[a] != frequence_count[b]){
                return frequence_count[a] < frequence_count[b];
            }
            if (frequence_count[a] == frequence_count[b]) {
                return a > b;
            }
            return frequence_count[a] < frequence_count[b];
        });
        return nums;
    }
};