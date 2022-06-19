#define ll   long long
class Solution {
public:
	int longestSubsequence(string s, int k)
	{
		string curr_str = "";
		ll curr_val = 0;
		ll cnt_ = 0;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			cnt_++;
			if (s[i] == '0')
			{
				curr_str += '0';
			}
			else
			{
				if (cnt_ > 31 || curr_val >= k)
				{

				}
				else
				{
					ll new_val = curr_val;
					ll kk = curr_str.length();
					new_val += pow(2, kk);
					if (new_val <= k)
					{
						curr_val = new_val;
						curr_str += '1';
					}
					else
					{

					}
				}

			}
		}
		return curr_str.length();
	}
};