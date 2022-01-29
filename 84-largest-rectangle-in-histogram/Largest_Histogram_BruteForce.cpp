class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        //Just Trying Brute Frce
        int global_ans = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            int curr = i;
            int l;
            int r;
            //For every i,->I will Consider Histogram of Height[i]
            //I will move towards left till, i get some block which has height less than ith block(left Pointer)
            //Similarly, I will move towards Right till i get block which has height less than current Block(Right Pointer)
            //Find width of histogram (l-r+1)
            while (curr >= 0 and heights[curr] >= heights[i])
            {
                curr--;
            }
            curr++;
            l = curr;
            curr = i;
            while (curr<heights.size() and heights[curr] >= heights[i])
            {
                curr++;
            }
            curr--;
            r = curr;
            //cout<<l<<" "<<r<<'\n';
            int width = r - l + 1;
            int height = heights[i];
            int curr_ans = width * height;
            global_ans = max(global_ans, curr_ans);
        }
        return global_ans;
    }
};