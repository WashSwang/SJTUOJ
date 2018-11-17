#include <iostream>
using namespace std;
int m,n,w[101],dp[101][100001],ans[101],ansn;
int main() {
    cin>>m>>n;
    for (int i=1;i<=n;++i) {
        cin>>w[i];
        m-=w[i];
    }
    m=-m;
    dp[0][0]=1;
    for (int i=1;i<=n;++i)
        for (int j = m; j >= 0; --j) {
            dp[i][j] = dp[i - 1][j];
            if (j>=w[i]) dp[i][j]+=dp[i - 1][j - w[i]];
        }
    if (dp[n][m]==0) cout<<0<<endl;
    else if (dp[n][m]>1) cout<<-1<<endl;
    else{
        ansn=0;
        for (int i=n;i>=1;--i)
            if (m>=w[i]&&dp[i - 1][m - w[i]]) {
                ans[ansn++] = i;
                m-=w[i];
            }
        for (int i=ansn-1;i>=0;--i)
            cout<<ans[i]<<' ';
    }
    return 0;
}