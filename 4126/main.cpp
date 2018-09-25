#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,m,dp[100001],k,ans;
long long a[101],c[101];
void zeroone(int w)
{
    for (int i=m;i>=w;--i)
        if (dp[i-w]) dp[i]=1;
}
void complete(int w)
{
    for (int i=w;i<=m;++i)
        if (dp[i-w]) dp[i]=1;
}
int main() {
    scanf("%d",&t);
    for (int i=0;i<t;++i)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for (int j=0;j<n;++j) scanf("%lld",&a[j]);
        for (int j=0;j<n;++j) {
            scanf("%lld",&c[j]);
            if (a[j]*c[j]<m)
            {
                k=1;
                while (k<c[j])
                {
                    zeroone(k*a[j]);
                    c[j]-=k;
                    k*=2;
                }
                zeroone(c[j]*a[j]);
            }
            else
                complete(a[j]);
        }
        for (int j=1;j<=m;++j)
            if (dp[j]) ++ans;
        printf("%d\n",ans);
    }
    return 0;
}