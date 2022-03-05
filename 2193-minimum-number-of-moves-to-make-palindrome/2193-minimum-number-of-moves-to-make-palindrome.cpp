//JAI SHREE KRISHNA
#include<bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define F               first
#define S               second
#define pbmax           priority_queue<int>//max heap
#define pbmin           priority_queue<int, vector<int>, greater<int>>//min heap priority_queue
#define lpi(i,a,b)      for(int i=a;i<b;i++)
#define lpd(i,a,b)      for(int i=b;i>=a;i--)
/**********************DEBUGGING************************/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" :"; _print(x);cerr<<'\n';
#else
#define debug(x)
#endif
void _print(int a) {cerr << a << " ";}
void _print(ll a) {cerr << a << " ";}
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



class Solution {
public:
	int minMovesToMakePalindrome(string s)
	{
		if (s.length() == 1)
		{
			return 0;
		}
		if (s.length() == 2)
		{
			if (s[1] == s[0])
			{
				return 0;
			}
		}
		//Check if Palindrome possible
		int o_occurance = 0;
		vector<int>chkk(26, 0);
		for (auto x : s)
		{
			chkk[x - 'a']++;
		}
		for (auto x : chkk)
		{
			if (x % 2)
			{
				o_occurance++;
			}
		}
		if (o_occurance > 1)
		{
			return -1;
		}
		vector<vector<int>>pos(26, vector<int>());
		for (int i = 0; i < s.size(); i++)
		{
			pos[s[i] - 'a'].push_back(i);
		}
		// for (auto x : pos)
		// {
		// 	for (auto y : x)
		// 	{
		// 		cout << y << " ";
		// 	}
		// 	cout << '\n';
		// }
		int l = 0;
		int r = s.size() - 1;
		int cnt = 0;
		while (l < r)
		{
			if (s[l] == s[r])
			{
				l++;
				r--;
				continue;
			}
			else
			{
				int pos = r;
				while (pos > l and s[pos] != s[l])
				{
					pos--;
				}
				if (pos > l)
				{
					//Now we have to take the pos->req char to the last
					while (pos != r)
					{
						char x = s[pos];
						char y = s[pos + 1];
						s[pos] = y;
						s[pos + 1] = x;
						cnt++;
						pos++;
					}
				}
				else
				{
					char x = s[pos];
					char y = s[pos + 1];
					s[pos] = y;
					s[pos + 1] = x;
					cnt++;
				}
			}
		}
		return cnt;
	}
};