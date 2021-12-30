class Solution {
public:
    int fib(int n) {
        vector<int>a(n+1);
        a[0]=0;
        if(n<1)
        {
            return 0;
        }
        if(n<2)
            return 1;
        a[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
        return a[n];
    }
};