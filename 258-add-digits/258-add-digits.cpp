class Solution {
public:
    int addDigits(int num) 
    {
        while(true)
        {
            if(num<10)
            {
                return num;
            }
            int new_num=0;
            while(num)
            {
                new_num+=(num%10);
                num=num/10;
            }
            num=new_num;
        }
    }
};