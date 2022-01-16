class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(maxDoubles==0)
        {
            return target-1;
        }
        int count=0;
        while(target!=1)
        {
            if(maxDoubles==0)
            {
                break;
            }
            if(target%2==1)
            {
                count++;
                
            }
            count++;
            target=target/2;
            maxDoubles--;
        }
        if(target>1)
        {
            count+=(target-1);
        }
        return count;
    }
};