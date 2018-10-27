#include <iostream>
#include <cstdio>
int dp[1001][1001],a[1001],p[1001],t,n,minn;
int main() {
    scanf("%d",&t);
    for (int i=0;i<t;++i)
    {
        scanf("%d",&n);
        for (int j=n-1;j>=0;--j) scanf("%d%d",&a[j],&p[j]);
        dp[0][0]=a[0]*p[0]+10*p[0];
        for (int j=1;j<n;++j)
        {
            minn=2100000000;
            for (int k=0;k<=j-1;++k) {
                dp[j][k] = dp[j - 1][k] + a[j] * p[k];
                if (dp[j-1][k]<minn) minn=dp[j-1][k];
            }
            dp[j][j]=minn+a[j]*p[j]+10*p[j];
        }
        minn=2100000000;
        for (int j=0;j<n;++j)
            if (dp[n-1][j]<minn) minn=dp[n-1][j];
        printf("%d\n",minn);
    }
    return 0;
}