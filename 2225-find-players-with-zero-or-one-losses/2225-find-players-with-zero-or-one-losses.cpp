//JAI SHREE KRISHNA
#include <bits/stdc++.h>
using namespace std;
#define pb              push_back



class Solution {
public:
	vector<vector<int>> findWinners(vector<vector<int>>& matches)
	{
		unordered_map<int, int>win, lose, track;
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