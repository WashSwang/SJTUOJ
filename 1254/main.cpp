#include <iostream>
using namespace std;
long long x[31][31];
int n,m;
int main() {
    x[0][0]=1;
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        x[i][0] = x[i - 1][n - 1] + x[i - 1][1];
        for (int j = 1; j < n - 1; ++j){
            x[i][j]=x[i-1][j-1]+x[i-1][j+1];
        }
        x[i][n-1]=x[i-1][0]+x[i-1][n-2];
    }
    cout<<x[m][0];
    return 0;
}