#include <iostream>
using namespace std;
typedef long long ll;
ll t[4000000],ans[1000000];
int n,m,k,l,r;
inline int lowbit(int x){ return x&-x;}
void update(int x,int k){
    while (x<=n){
        t[x]+=k;
        x+=lowbit(x);
    }
}
ll query(int x){
    ll sum=0;
    while (x>0){
        sum+=t[x];
        x-=lowbit(x);
    }
    return sum;
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%d",&k);
        update(i,k);
    }
    for (int i=0;i<m;++i){
        scanf("%d%d",&l,&r);
        ans[i]=query(r)-query(l-1);
    }
    for (int i=0;i<m;++i)
        printf("%lld\n",ans[i]);
    return 0;
}