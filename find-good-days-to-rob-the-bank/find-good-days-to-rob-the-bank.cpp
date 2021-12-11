class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& a, int time) {
      int n = a.size();
      vector<int> left(n, 0), right(n, 0);
      for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) 
        {
          left[i] = left[i - 1] + 1;
        } else 
        {
          left[i] = 0;
        }
      }
      for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= a[i + 1]) {
          right[i] = right[i + 1] + 1;
        } else {
          right[i] = 0;
        }
      }
      vector<int> ans;
      for (int i = 0; i < n; i++) {
        if (left[i] >= time and right[i] >= time) {
          ans.push_back(i);
        }
      }
      return ans;
    }
};