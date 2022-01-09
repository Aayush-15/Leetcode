class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        bool ok=true;
        //checking rows
        for(int i=0;i<n;i++)
        {
            vector<bool>present(101,false);
            for(int j=0;j<n;j++)
            {
                present[matrix[i][j]]=true;
            }
            bool ok1=true;
            for(int i=1;i<=n;i++)
            {
                if(present[i]==false)
                {
                    ok1=false;
                }
            }
            if(ok1==false)
            {
                ok=false;
            }
        }
        if(ok==false)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            vector<bool>present(101,false);
            for(int j=0;j<n;j++)
            {
                present[matrix[j][i]]=true;
            }
            bool ok1=true;
            for(int i=1;i<=n;i++)
            {
                if(present[i]==false)
                {
                    ok1=false;
                }
            }
            if(ok1==false)
            {
                ok=false;
            }
        }
        return ok;
    }
};