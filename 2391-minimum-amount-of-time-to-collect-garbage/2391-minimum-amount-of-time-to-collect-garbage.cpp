//JAI SHREE KRISHNA
#include<bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
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
	int garbageCollection(vector<string>& garbage, vector<int>& travel) {
		int last_glass = 0, last_metal = 0, last_paper = 0;
		int glass_cnt = 0, metal_cnt = 0, paper_cnt = 0;
		for (int i = 0; i < garbage.size(); i++)
		{
			string str = garbage[i];
			for (auto x : str)
			{
				if (x == 'M')
				{
					last_metal = i;
					metal_cnt++;
				}
				if (x == 'G')
				{
					glass_cnt++;
					last_glass = i;
				}
				if (x == 'P')
				{
					paper_cnt++;
					last_paper = i;
				}
			}
		}
		int ans = 0;
		vector<int>dist(travel.size() + 1, 0);
		for (int i = 1; i < dist.size(); i++)
		{
			dist[i] = dist[i - 1] + travel[i - 1];
		}
		ans += dist[last_paper] + dist[last_glass] + dist[last_metal] + metal_cnt + glass_cnt + paper_cnt;
		debug(dist);
		debug(last_paper);
		debug(last_glass);
		debug(last_metal);
		return ans;
	}
};
