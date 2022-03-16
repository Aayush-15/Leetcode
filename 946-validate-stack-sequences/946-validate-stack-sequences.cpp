class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int>st;
        int i=0;
        for(auto x:pushed)
        {
            st.push(x);
            while(st.size() and st.top()==popped[i])
            {
                i++;
                st.pop();
            }
            
        }
        //cout<<st.size()<<'\n';
        if(st.size()==0)
        {
            return true;
        }
        return false;
    }
};