

#include <stdio.h>
#include <stdlib.h>
long long int dp[1000000]={0};
long long int solve(long long int k)
{
    if(k<12)
    {
        return k;
    }
    if(k<1000000&&dp[k]!=0)
    {
        return dp[k];
    }
    else if(k<1000000)
    {
        dp[k]=solve(k/2)+solve(k/3)+solve(k/4);
    }
    return solve(k/2)+solve(k/3)+solve(k/4); ;
}

int main(void)
{
    long long int n;
    while(scanf("%lld",&n)!=EOF)
    {
        long long int l= solve(n);
        if(n<l) printf("%lld\n",l);
        else printf("%lld\n",n);
    }
    return 0;
}
