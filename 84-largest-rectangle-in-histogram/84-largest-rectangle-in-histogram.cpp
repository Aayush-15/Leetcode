class Solution {
public:
	int largestRectangleArea(vector<int>& heights)
	{
		//Find Next Smaller from left and right for every i optimally using stack and store them in 2 arrays
		stack<int>st;
		int sz = heights.size();

		vector<int>left_smaller(sz, 0), right_smaller(sz); //For Storing Indices of Next Left Smaller and Next Right Smaller
		for (int i = 0; i < sz; i++)
		{
			while (st.size() > 0 and heights[st.top()] >= heights[i])
			{
				st.pop();
			}
			//Every block on left is greater than curr block
			if (st.size() == 0)
			{
				left_smaller[i] = 0;
			}
			else
			{
				left_smaller[i] = st.top() + 1;

			}
			st.push(i);
		}
		//Now reuse stack for calculating right_smaller
		while (st.size())
		{
			st.pop();
		}

		for (int i = sz - 1; i >= 0; i--)
		{
			while (st.size() > 0 and heights[st.top()] >= heights[i])
			{
				st.pop();
			}
			//Every block on left is greater than curr block
			if (st.size() == 0)
			{
				right_smaller[i] = sz - 1;
			}
			else
			{
				right_smaller[i] = st.top() - 1;

			}
			st.push(i);
		}
		int global_ans = 0;
		for (int i = 0; i < sz; i++)
		{
			int curr_ans;
			int width = right_smaller[i] - left_smaller[i] + 1;
			int height = heights[i];
			curr_ans = width * height;
			global_ans = max(global_ans, curr_ans);
		}
		return global_ans;
	}
};