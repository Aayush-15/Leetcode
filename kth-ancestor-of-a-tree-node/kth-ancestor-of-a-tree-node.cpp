class TreeAncestor {
    vector<vector<int>>adj;//Building Tree
    vector<vector<int>>Parent;
    int LOG=20;
    vector<int>Depth;
public:
    void dfs(int node,int par,vector<vector<int>>&Parent)
    {
        //Because 0th Node parent is -1, Negative Index So Continue
        if(node==0)
        {
            Depth[node]=0;
        }
        else
        {
            Depth[node]=Depth[par]+1;
        }
        
        Parent[node][0]=par;
        
        //Filling The Sparse Table
        //Rercurrance: Par[i][j]=Par[Par[i][j-1]][j-1]
        for(int j=1;j<LOG;j++)
        {
            Parent[node][j]=Parent[Parent[node][j-1]][j-1];
        }
        
        for(auto child:adj[node])
        {
            if(child!=par)
            {
                dfs(child,node,Parent);
            }
        }
    }
    TreeAncestor(int n, vector<int>& parent) 
    {
        adj.resize(n);
        Depth.resize(n);
        LOG=ceil(log2(n));
        Parent=vector<vector<int>>(n,vector<int>(LOG,0));
        
        //Making The Adjacency List
        for(int i=0;i<parent.size();i++)
        {
            if(i==0)//Because 0th Node parent is -1, Negative Index So Continue
            {
                continue;
            }
            int to=i;
            int from=parent[i];
            adj[to].push_back(from);
            adj[from].push_back(to);
        }
        Parent[0][0]=0;
        dfs(0,0,Parent);
        
    }
    
    int getKthAncestor(int node, int k) 
    {
        if(Depth[node]<k)
        {
            return -1;
        }
        for(int j=0;j<LOG;j++)
        {
            if(k&(1<<j)){
                node=Parent[node][j];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
