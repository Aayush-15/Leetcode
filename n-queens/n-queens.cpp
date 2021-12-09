class Solution {
public:
    //This Function tells if we can places queen at particular row and coloumn
    bool is_safe(int row,int col,vector<string>&board,int n)
    {
        int curr_row=row;
        int curr_col=col;
        //Checking upper diagonal
        //. . _ . .
        //. . . _ .
        //. . . . X
        while(curr_row>=0 and curr_col>=0)
        {
            if(board[curr_row][curr_col]=='Q')
            {
                return false;
            }
            curr_row--;curr_col--;
        }
        //Checking Left Horizontal
        //. . . . .
        //. _ _ _ X
        //. . . . .
        curr_row=row;
        curr_col=col;
        while(curr_col>=0)
        {
            if(board[curr_row][curr_col]=='Q')
            {
                return false;
            }
            curr_col--;
        }
        //Checking Left Horizontal
        //. . . . X
        //. . . _ .
        //. . _ . .
        curr_row=row;
        curr_col=col;
        while(curr_row<n and curr_col>=0)
        {
             if(board[curr_row][curr_col]=='Q')
            {
                return false;
            }
            curr_col--;
            curr_row++;
        }
        return true;
    }
    void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(is_safe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        string s(n,'.');
        vector<vector<string>>ans;
        vector<string>board(n);
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,ans,board,n);
        return ans;
            
    }
};