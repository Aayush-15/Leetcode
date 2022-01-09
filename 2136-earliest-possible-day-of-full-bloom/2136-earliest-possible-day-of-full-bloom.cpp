class Solution {
public:
	// bool sortbysec( pair<int, int> &a,  pair<int, int> &b)
	// {
	// 	return (a.second < b.second);
	// }
	int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime)
	{
		vector<pair<int, int>>vp;
		for (int i = 0; i < plantTime.size(); i++)
		{
			vp.push_back({ growTime[i], plantTime[i]});
		}
		sort(vp.begin(), vp.end());
		reverse(vp.begin(), vp.end());
		// for (auto x : vp)
		// {
		// 	cerr << x.F << " " << x.S << '\n';
		// }
		int day = 0;
		int mini = 0;
		for (int i = 0; i < vp.size(); i++)
		{
			day += vp[i].second;
			//debug(day);
			//debug(mini);
			mini = max(mini, day + vp[i].first);

		}

		return mini;
	}
};