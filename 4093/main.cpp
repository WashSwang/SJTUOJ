#include <cstdio>
using namespace std;
int m,a,b;
long long n,ans,num[200001];
int main() {
    scanf("%lld%d",&n,&m);
    for (int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        num[b]+=a;
    }
    for (int i=200000;i>=1;--i)
    {
        if (n>=num[i]) {
            ans += num[i] * i;
            n -= num[i];
        }
        else{
            ans+=n*i;
            break;
        }
    }
    printf("%lld",ans);
    return 0;
}