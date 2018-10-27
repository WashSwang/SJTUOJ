#include <iostream>
using namespace std;
int p[3001],q[3001],dp[3001][3001],m,n,ptr,ans,win,ping;
void qsort(int *s,int *t)
{
    if (s+1>=t) return;
    int i=0,j=int(t-s)-1,x=s[0];
    while (i<j)
    {
        while (i<j&&s[j]<=x) j--;
        if (i<j) s[i++]=s[j];
        while (i<j&&s[i]>=x) i++;
        if (i<j) s[j--]=s[i];
    }
    s[i]=x;
    qsort(s,s+i);
    qsort(s+i+1,t);
}
inline int cmp(int x,int y){
    if (x>y) return 1;
    if (x<y) return -1;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>m;
    for (int i=0;i<m;++i) cin>>p[i];
    for (int i=0;i<m;++i) cin>>q[i];
    qsort(p,p+m);
    qsort(q,q+m);
    for (int i=1;i<=m;++i){
        for (int j=0;j<=i;++j)
        {
            dp[i][j]=-100000000;
            if (j>=1)
                dp[i][j]=max(dp[i-1][j-1]+cmp(p[j-1],q[i-1]),dp[i][j]);
            if (j<i)
                dp[i][j]=max(dp[i-1][j]+cmp(p[m-(i-j)],q[i-1]),dp[i][j]);
        }
    }
    ans=-100000000;
    for (int i=0;i<=m;++i)
        ans=max(dp[m][i],ans);
    cout<<ans*200;
    return 0;
}