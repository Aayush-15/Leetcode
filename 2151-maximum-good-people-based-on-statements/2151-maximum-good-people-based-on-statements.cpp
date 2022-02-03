class Solution {
public:
    int n=0,ans=0;
    
    void dfs(vector<vector<int>>& statements, string &curr, int i, int good){
        if(i==n){
            if(isValid(curr, statements)){ // checking if curr is a valid combination of good and bad people
                ans=max(ans, good);
            }
            return;
        }
        curr.push_back('1'); // considering ith person is good
        dfs(statements, curr, i+1, good+1); 
        curr.back()='0'; // considering ith person is bad
        dfs(statements, curr, i+1, good);
        curr.pop_back(); // backtrack
    }
    
    bool isValid(string &curr, vector<vector<int>>& statements){
        for(int i=0;i<n;i++){ // check if all the statements said by good people are valid 
            if(curr[i]=='1'){ 
                for(int j=0;j<n;j++){
                    if(statements[i][j]!=2 && statements[i][j]!=curr[j]-'0')
                        return false;
                }
            }
        }
        return true;
    }
    
    int maximumGood(vector<vector<int>>& statements) {
        n=statements.size();
        string curr="";
        dfs(statements, curr, 0, 0);
        return ans;
    }
};