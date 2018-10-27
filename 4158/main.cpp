#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,sum,m,n,x[5000],tmp;
long long ans;
int main() {
    scanf("%d",&t);
    for (int i=0;i<t;++i){
        ans=0;
        sum=0;
        scanf("%d%d",&n,&m);
        memset(x,0,sizeof(x));
        x[0]=1;
        for (int j=0;j<n;++j){
            scanf("%d",&tmp);
            sum+=tmp;
            sum%=m;
            ans+=x[sum];
            x[sum]++;
        }
        printf("%lld",ans);
    }
    return 0;
}