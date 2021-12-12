class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) 
    {
        int l=0;
        int r=plants.size()-1;
        int count=0;
        int A=capacityA;
        int B=capacityB;
        while(l<=r)
        {
            if(l==r)
            {
                if(capacityA>=capacityB)
                {
                    if(capacityA>=plants[l])
                    {
                        
                    }
                    else
                    {
                        count++;
                    }
                }
                else
                {
                    if(capacityB>=plants[l])
                    {
                        
                    }
                    else
                    {
                        count++;
                    }
                }
                break;
            }
            if(capacityA>=plants[l])
            {
                   capacityA-=plants[l];     
            }
            else
            {
                
                count++;
                capacityA=A;
                capacityA-=plants[l];   
            }
            l++;
            if(capacityB>=plants[r])
            {
                   capacityB-=plants[r];     
            }
            else
            {
                
                count++;
                capacityB=B;
                capacityB-=plants[r];   
            }
            r--;            
                    
            
        }
        return count;
    }
};