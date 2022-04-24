//JAI SHREE KRISHNA
#include <bits/stdc++.h>
using namespace std;
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define F               first
#define S               second
#define pbmax           priority_queue<int>//max heap
#define pbmin           priority_queue<int, vector<int>, greater<int>>//min heap priority_queue
#define lpi(i,a,b)      for(int i=a;i<b;i++)
#define lpd(i,a,b)      for(int i=b;i>=a;i--)
/****************************************************************************************/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" :"; _print(x);cerr<<'\n';
#else
#define debug(x)
#endif
void _print(int a) {cerr << a << " ";}
void _print(long long  a) {cerr << a << " ";}
void _print(char a) {cerr << a << " ";}
void _print(double a) {cerr << a << " ";}
void _print(float a) {cerr << a << " ";}
void _print(string a) { cerr << a << " ";}
template<class T> void _print(vector<T>v) {
	cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template<class T> void _print(set<T>s)
{
	cerr << "[ "; for (T i : s) {_print(i); cerr << " ";} cerr << "]";
}
template<class T> void _print(multiset<T>s)
{
	cerr << "[ "; for (T i : s) {_print(i); cerr << " ";} cerr << "]";
}
template <class T, class V> void _print(pair <T, V> pair_p) {
	cerr << "{"; _print(pair_p.first); cerr << ","; _print(pair_p.second); cerr << "}";
}
template <class T, class V> void _print(map <T, V> mp) {
	cerr << "[ "; for (auto i : mp) {_print(i); cerr << " ";} cerr << "]";
}
/****************************************************************************************/



class Solution {
public:
	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons)
	{
		int N = 5 * (1e4) + 5;
		map<long long, long long>mp_;
		for (auto x : flowers)
		{
			int xx = x[0];
			int yy = x[1];
			mp_[xx]++;
			mp_[yy + 1]--;
		}
		// vector<int>DP(N, 0);
		// for (int i = 1; i < N; i++)
		// {
		// 	DP[i] = DP[i - 1] + arr[i];
		// }
		vector<int>ans;
		vector<long long>kk;
		for (auto x : mp_)
		{
			kk.push_back(x.first);
		}
		for (int i = 1; i < kk.size(); i++)
		{
			mp_[kk[i]] += mp_[kk[i - 1]];
		}
		mp_[1e9 + 4] = 0;
		for (auto x : persons)
		{
			auto it = mp_.lower_bound(x);
			if (it->first != x)
			{
				it--;
			}
			if (it == mp_.end())
			{
				ans.push_back(0);
			}
			else
			{
				ans.push_back(it->second);
			}

		}
		return ans;
	}
};