class Solution {
public:
    bool searchMatrix(vector<vector<int>> &m, int t) {
        // Just Treat The Matrix as a Sorted List Of Size -> N*M
        //  0 1  2  3
        //  4 5  6  7     ->Arr[xx]=Mat[xx/m][xx%m]
        //  8 9 10 11
        //n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
        //an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
        int row=m.size();
        int col=m[0].size();
        int left=0;
        int right=row*col-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(m[mid/col][mid%col]==t)
            {
                return true;
            }
            if(m[mid/col][mid%col]>t){
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return false;
        
    }
};