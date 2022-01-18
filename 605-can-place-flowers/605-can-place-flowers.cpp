class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        vector<int>pos;
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==1)
            {
                pos.push_back(i);
            }
        }
        if(pos.size()==0)
        {
           long long possible=0;
            if(flowerbed.size()==1||flowerbed.size()==2)
            {
                possible=1;
            }
            else
            possible=(flowerbed.size()+1)/2;
            if(possible<n)
            {
                return false;
            }
            return true;
        }
        long long possible=0;
        // for(auto x:pos)
        // {
        //     cout<<x<<" ";
        // }
        for(int i=0;i<pos.size();i++)
        {
            if(i==0)
            {
               possible+=((pos[i]-0)/2);
                
               
            }
            if(i==pos.size()-1)
            {
                possible+=((flowerbed.size()-1-pos[i])/2);
                //continue;
            }
            if(i!=0 and pos.size()>1)
            {
                possible+=((pos[i]-pos[i-1]-2)/2);
            }
            
        }
       // cout<<possible<<'\n';
        if(possible>=n)
        {
            return true;
        }
        return false;
    }
};