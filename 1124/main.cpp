#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[410][33000],x[500],y[500],sx,sy,n,ans;
int main() {
    cin>>n>>sx>>sy;
    for (int i=1;i<=n;++i)
        cin>>x[i]>>y[i];
    memset(dp,-40000,sizeof(dp));
    dp[0][sx]=sy;
    for (int i=1;i<=n;++i)
        for (int j = 0; j < 32000; ++j) {
            dp[i][j] = dp[i - 1][j];
            if ((j >= x[i]) && (dp[i - 1][j - x[i]] > -40000) && (dp[i - 1][j - x[i]] + y[i] > dp[i][j]))
                dp[i][j] = dp[i - 1][j - x[i]] + y[i];
        }
    for (int i=1;i<32000;++i)
        if ((dp[n][i]>70)&&(i*dp[n][i]>ans))
            ans=i*dp[n][i];
    if (ans!=0) cout<<ans<<endl;
    else cout<<"Death"<<endl;
    return 0;
}