class Solution {
public:
    int cnt=0;
   //This Function tells if we can places queen at particular row and coloumn
    void solve(int col,vector<vector<string>>&ans,vector<string>&board,int A, vector<int>&left ,                       vector<int>&left_upper_diagonal ,vector<int>&left_lower_diagonal)
{
    if(col==A)
    {
        ans.push_back(board);
        cnt++;
        return;
    }
    for(int row=0;row<A;row++)
    {
        if(left[row]==0 and left_lower_diagonal[row+col]==0 and left_upper_diagonal[A-1+col-row]==0)
        {
            left[row]=1;
            left_lower_diagonal[row+col]=1;
            left_upper_diagonal[A-1+col-row]=1;
            board[row][col]='Q';
            solve(col+1,ans,board,A,left,left_upper_diagonal,left_lower_diagonal);
            //While Backtracking
            left[row]=0;
            left_lower_diagonal[row+col]=0;
            left_upper_diagonal[A-1+col-row]=0;
            board[row][col]='.';
        }
    }
 }
    
    int totalNQueens(int n) {
        string s(n,'.');
        vector<vector<string>>ans;
        vector<string>board(n);
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>left(n,0),left_upper_diagonal(2*n-1,0),left_lower_diagonal(2*n-1,0);
        solve(0,ans,board,n,left,left_upper_diagonal,left_lower_diagonal);
        return cnt;   
        
    }
};