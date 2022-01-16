class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int first_occurance;
        int last_occurance;
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]==1)
            {
                first_occurance=i;
                break;
            }
        }
        for(int j=seats.size()-1;j>=0;j--)
        {
            if(seats[j]==1)
            {
                last_occurance=j;
                break;
            }
        }
        int ans=max((int)first_occurance-0,(int)seats.size()-1-last_occurance);
        if(last_occurance==first_occurance)
        {
            return ans;
        }
        
        vector<int>index;
        for(int i=first_occurance;i<=last_occurance;i++)
        {
            if(seats[i]==1)
            {
               index.push_back(i);

            }
        }
        // for(auto x:index)
        // {
        //     cout<<x<<" ";
        // }
        for(int i=1;i<index.size();i++)
        {
            ans=max(ans,((index[i]-index[i-1])/2));
        }
        return ans;
    }
};