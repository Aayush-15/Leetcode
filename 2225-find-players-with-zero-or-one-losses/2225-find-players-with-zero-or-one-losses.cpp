//JAI SHREE KRISHNA
#include <bits/stdc++.h>
using namespace std;
#define pb              push_back


struct custom_hash {
      static uint64_t splitmix64(uint64_t x) {
            // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
      }

      size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
      }
};
class Solution {
public:
	vector<vector<int>> findWinners(vector<vector<int>>& matches)
	{
		unordered_map<long long, int, custom_hash>win, lose, track;
		for (auto x : matches)
		{
			win[x[0]] = 0;
            win[x[1]]=0;
            lose[x[0]]=0;
			lose[x[1]] = 0;
			track[x[0]]++;
			track[x[1]]++;
		}
		for (auto x : matches)
		{
			win[x[0]]++;
			lose[x[1]]++;
		}
		vector<vector<int>>ans;
		vector<int>all_win;
		vector<int>lose_one;
		for (auto x : track)
		{
			int curr_player = x.first;
			if (lose[curr_player] == 0)
			{
				all_win.pb(curr_player);
			}
			if (lose[curr_player] == 1)
			{
				lose_one.pb(curr_player);
			}
		}
        sort(all_win.begin(),all_win.end());
        sort(lose_one.begin(),lose_one.end());
		ans.pb(all_win);
		ans.pb(lose_one);
		return ans;
	}
};