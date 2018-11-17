#include <iostream>
#include <iomanip>
using namespace std;
int m,n;
double dp[1001][1001],ans=0;
int main() {
    cin>>n>>m;
    dp[0][n]=1;
    for (int i=1;i<=n;++i)
        for (int j=0;j<n;++j) {
            for (int k = max(j + 1, n - m + 1); k <= n; ++k)
                dp[i][j] += dp[i - 1][k] / k;
            if (j<=n-m) ans+=i*dp[i][j];
        }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans;
    return 0;
}