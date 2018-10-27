#include <iostream>
using namespace std;
int n,m,dp[1005][1005];
char x[1005],y[1005];
int main() {

    cin>>n>>m;
    cin>>x>>y;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            if (x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    cout<<dp[n][m];
    return 0;
}