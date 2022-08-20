class Solution {
public:
	string shiftingLetters(string s, vector<vector<int>>& shifts) {
		int sz = s.size();
		vector<int>change(sz + 2, 0);
		for (auto x : shifts)
		{
			int to = x[0];
			int from = x[1];
			int dir = x[2];
			if (dir == 1)
			{
				change[to]++;
				change[from + 1]--;
			}
			else
			{
				change[to]--;
				change[from + 1]++;
			}
		}
		int curr = 0;
		for (int i = 0; i < change.size(); i++)
		{
			curr += change[i];
			change[i] = curr;
			change[i] = change[i] % 26;
		}
		// debug(change);
		map<int, char>mp1;
		int ii = 0;
		char xx = 'a';
		for (int kk = 0; kk < 26; kk++)
		{
			mp1[ii] = xx;
			ii++;
			xx++;
		}
		xx = 'z';
		for (int i = -1; i >= -26; i--)
		{
			mp1[i] = xx;
			xx--;
		}
		
		for (int i = 0; i < s.size(); i++)
		{
			int to_int = (int)((char)s[i] - 'a');
			to_int += change[i];
			to_int = to_int % 26;
			s[i] = (char)mp1[to_int];
		}
		return s;
	}
};