#include <iostream>
#include <cstring>
using namespace std;
int n,a,b,t[41][161][161],ans,sum;//第i天，吃j个，总共k个
int main() {
    cin>>n;
    for (int q=0;q<n;++q)
    {
        memset(t,0,sizeof(t));
        cin>>a>>b;
        t[0][0][0]=1;
        for (int i=1;i<=b;++i){
            for (int k=0;k<=a;++k){
                sum=0;
                for (int j=0;j<=a-k;++j){
                    sum+=t[i-1][j][k];
                    if (j!=0) t[i][j][k+j]=sum;
                }
            }
        }
        ans=0;
        for (int i=1;i<=a;++i)
            ans+=t[b][i][a];
        cout<<ans<<endl;
    }
    return 0;
}